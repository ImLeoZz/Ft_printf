NAME = libftprintf.a

SRC = ft_printf.c ft_print_hex.c \
			ft_print_number.c ft_print_str.c \
			ft_print_pointer.c
INCLUDES = includes

PRE = ./srcs/
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = ${addprefix ${PRE}, ${SRC}}
OBJS = ${SRCS:.c=.o}

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDES) -I$(LIBFT_DIR)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@cp $(LIBFT) $(NAME)
	@ar rcs $(NAME) $(OBJS) 

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

%.o: %.c Makefile $(INCLUDES)/ft_printf.h
	@$(CC) -c $(CFLAGS) $< -o $@

clean:
	@rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
