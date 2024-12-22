CC = cc
SRCS =			ft_printf.c \
               ft_printf_utils.c \
               main.c


NAME = printf

all: $(NAME) 
 
$(NAME): $(SRCS)
	$(CC) $(SRCS) -o $(NAME)


clean: clean
	rm -f $(NAME)

re: fclean all