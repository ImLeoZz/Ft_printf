*This project has been created as part of the 42 curriculum by lemille.*

# ft_printf

## Description

**ft_printf** is a re-implementation of the standard C `printf` function, written as part of the 42 curriculum. The goal is to understand how variadic functions work in C (`<stdarg.h>`) and to design a clean dispatching architecture.

```c
int ft_printf(const char *f, ...);
```

It writes the formatted output to standard output and returns the number of characters printed, or `-1` on error (`NULL` format string, or a `%` at the end of the format string).

### Supported conversions

| Conversion | Meaning                                  |
|------------|------------------------------------------|
| `%c`       | single character                         |
| `%s`       | string (prints `(null)` for `NULL`)      |
| `%p`       | pointer, in hexadecimal (`(nil)` for NULL) |
| `%d`, `%i` | signed decimal integer                   |
| `%u`       | unsigned decimal integer                 |
| `%x`       | lowercase hexadecimal                    |
| `%X`       | uppercase hexadecimal                    |
| `%%`       | literal percent sign                     |

An unknown conversion such as `%k` is printed as `%k`.

## Algorithms

### Format parsing (`ft_printf`)

The format string is read once, character by character, with an index `k`:

```
k = 0, count = 0
if format is NULL: return -1
while format[k]:
    if format[k] == '%':
        if format[k + 1] exists: k++
        else: return -1
        count += dispatch(format[k], args)
    else:
        count += print_char(format[k])
    k++
return count
```

Each `%` consumes the following character as a conversion specifier, so `%%` naturally falls through to the `%` case. The total number of printed characters is accumulated in `count`, which is the value returned.

### Dispatch

`dispatch` is a `switch`-like chain (here `if`/`else`) on the conversion character. Each branch calls one helper and returns its length. Unknown specifiers print `%` followed by the character and return the combined length.

### Decimal output (`%d`, `%i`, `%u`)

Printing uses recursion on the most significant part of the number:

```
put_nbr(n):
    if n < 0: write('-'); n = -n
    if n > 9: put_nbr(n / 10)
    write('0' + n % 10)
```

Because the recursive call happens before the write, the digits are emitted from most significant to least significant without any buffer. The width is computed separately:

```
intlen(n):
    len = 1
    if n < 0: len++, n = -n
    while n > 9: n = n / 10, len++
    return len
```

Working on a `long` keeps `INT_MIN` and `UINT_MAX` correct, since negating `INT_MIN` overflows an `int`.

### Hexadecimal output (`%x`, `%X`)

Conversion is done by repeated division by 16, storing remainders in a buffer in reverse order:

```
hex(n, digits):
    if n == 0: write('0'); return 1
    while n > 0:
        buf[i++] = digits[n % 16]
        n = n / 16
    write buf from i-1 down to 0
    return i
```

`digits` is `"0123456789abcdef"` for `%x` and `"0123456789ABCDEF"` for `%X`. The `n == 0` case is needed because the loop would otherwise print nothing.

### Pointer output (`%p`)

```
if ptr == NULL: write "(nil)"; return 5
write "0x"
write hex((unsigned long)ptr, lowercase digits)
```

Casting to `unsigned long` keeps all address bits on 64-bit systems.

### Complexity

- Format parsing: O(n) in the length of the format string.
- Decimal and hexadecimal conversion: O(d), where d is the number of digits produced.
- Total: O(n + total output length).

## Instructions

### Compilation

The project depends on the `libft` located in the `libft/` directory. The Makefile builds it automatically.

```bash
make            # builds libftprintf.a
make clean      # removes object files (also in libft)
make fclean     # removes object files and libftprintf.a
make re         # rebuilds everything from scratch
```

The code is compiled with `cc -Wall -Wextra -Werror`.

`libftprintf.a` is created by copying `libft/libft.a` and adding the `ft_printf` object files to it, so the final archive contains both `ft_printf` and the libft functions.

### Usage

```c
#include "ft_printf.h"

int main(void)
{
    int len;

    len = ft_printf("Hello %s, you are %d years old! (%x)\n", "42", 42, 42);
    ft_printf("Printed %d characters\n", len);
    return (0);
}
```

```bash
cc -Wall -Wextra -Werror main.c -I includes -L. -lftprintf -o test
./test
```

## Implementation details

### Architecture

The code is split by conversion family:

- `ft_printf.c`: parses the format string and dispatches each conversion to a helper depending on its type.
- `ft_print_str.c`: `%c` and `%s`.
- `ft_print_number.c`: `%d`, `%i`, `%u`.
- `ft_print_hex.c`: `%x`, `%X`.
- `ft_print_pointer.c`: `%p`.

Every helper returns the number of characters it wrote, and `ft_printf` sums these values to produce its return value.

### Variadic arguments

Arguments are read with `va_start`, `va_arg` and `va_end`. The `va_list` is passed by value to the dispatch functions, and each conversion consumes exactly the type it expects (`int`, `unsigned int`, `char *`, `void *`...). Reading the wrong type is undefined behaviour, which is why each conversion has its own `va_arg` call.

### Number printing (`%d`, `%i`, `%u`)

Numbers are printed with the libft function `ft_putnbr_fd`, which takes a `long int`. Using a type wider than `int` has two consequences:

- the full range of `unsigned int` (up to `UINT_MAX`, 4294967295) fits without overflow, so `%u` needs no separate routine;
- negating `INT_MIN` (`nb *= -1`) is safe, since `2147483648` fits in a `long` on 64-bit systems.

Digits are emitted most significant first through recursion:

```
put_nbr(n):
    if n < 0:  write('-'), n = -n
    if n > 9:  put_nbr(n / 10)
    write('0' + n % 10)
```

The recursion reverses the order in which digits are produced, so no buffer is needed. The length of the output is computed separately by `ft_intlen`, which counts the digits (plus one for the `-` sign when negative) by repeated division by 10. That length is what the function returns to the main loop.

`%d` / `%i` and `%u` share the same printing routine: only the type fetched with `va_arg` (`int` vs `unsigned int`) differs.

### Hexadecimal (`%x`, `%X`)

The number is converted by repeated division by 16. Remainders are collected into a 20-byte buffer in reverse order, then written from the end. The digit table is `"0123456789abcdef"` for `%x` and `"0123456789ABCDEF"` for `%X`. The value `0` is handled as a special case, since the loop would otherwise print nothing.

### Pointers (`%p`)

A `NULL` pointer prints `(nil)`. Otherwise, `0x` is printed followed by the address converted to hexadecimal with the same digit-by-digit method, using the lowercase table. The pointer is cast to `unsigned long` so that all 64 bits are kept.

### Errors

- `ft_printf(NULL, ...)` returns `-1`.
- A `%` at the very end of the format string returns `-1`.
- An unknown conversion prints `%` followed by the character.

## Resources

### References

- `man 3 printf`: behaviour of the original function
- `man 3 stdarg`: variadic functions (`va_start`, `va_arg`, `va_end`)
- [GNU C Library manual: Formatted Output](https://www.gnu.org/software/libc/manual/html_node/Formatted-Output.html)
- The 42 subject for `ft_printf` and the libft subject

### Use of AI

AI was used as a pedagogical tutor during this project: to clarify concepts (variadic arguments, `va_list` behaviour, Makefile and library structure, edge cases of `printf`), to discuss design choices and to help debug reasoning. The code itself was written by the author.
