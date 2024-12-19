/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihamani <ihamani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 13:43:01 by ihamani           #+#    #+#             */
/*   Updated: 2024/12/19 16:50:10 by ihamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check(char c)
{
	return (c == 'c' || c == 's'
		|| c == 'd' || c == '%' || c == 'u');
}

int	print_format(char spicifier, va_list ap)
{
	int	count;

	count = 0;
	if (spicifier == 'c')
		count += ft_putchar(va_arg(ap, int));
	else if (spicifier == 's')
		count += ft_putstr(va_arg(ap, char *));
	else if (spicifier == 'd' || spicifier == 'i')
		count += ft_putnbr(va_arg(ap, int));
	else if (spicifier == 'u')
		count += ft_putunbr(va_arg(ap, unsigned int));
	else if (spicifier == '%')
		count += ft_putchar('%');
	else
		count += ft_putchar(spicifier);
	return (count);
}

int	print_it(const char *str, va_list ap)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			while (str[++i] == ' ');
			if (check(str[i]))
				count += print_format(str[i], ap);
			else if (str[i + 1])
			{
				i--;
				count += ft_putchar('%');
				count += ft_putchar(str[i]);
			}
		}
		else
			count += ft_putchar(str[i]);
		i++;
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, str);
	count = print_it(str, ap);
	va_end(ap);
	return (count); 
}

int main()
{
	int t = ft_printf("%            r %r          \n", 's');
	int s = printf("%            r %r          \n",  's');
	printf("%i , or : %i\n", t, s);

}
