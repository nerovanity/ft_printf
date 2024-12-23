# ifndef FT_PRINTF_FT
# define FT_PRINTF_FT

# include <unistd.h>
# include <stdarg.h>

int ft_putchar(char c);
int ft_putstr(char *str);
int ft_putnbr(int nbr);
unsigned int ft_putunbr(unsigned int nbr);
int print_lhex(size_t t);
int print_uhex(size_t t);
int	print_mem(size_t t);
int	ft_printf(const char *str, ...);

# endif