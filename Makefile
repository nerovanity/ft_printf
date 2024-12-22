CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS =			ft_printf.c \
               ft_printf_utils.c \
			   ft_printf_utils2.c
OBJECTS = $(SRCS:.c=.o)
NAME = libftprintf.a

all: $(NAME) 
 
$(NAME): $(OBJECTS)

%.o: %.c libftprintf.h
	$(CC) $(CFLAGS) -c $< -o $@
	ar rcs $(NAME) $@

clean: 
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all