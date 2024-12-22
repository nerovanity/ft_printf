/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihamani <ihamani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 13:43:01 by ihamani           #+#    #+#             */
/*   Updated: 2024/12/22 18:41:09 by ihamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	check(char c)
{
	char	*flags;
	int		i;

	flags = "csduxiXp%";
	i = 0;
	while (flags[i])
	{
		if (flags[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	print_format(char spicifier, va_list ap)
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
	else if (spicifier == 'x')
		count += print_lhex(va_arg(ap, unsigned int));
	else if (spicifier == 'X')
		count += print_uhex(va_arg(ap, unsigned int));
	else if (spicifier == 'p')
		count += print_mem(va_arg(ap, size_t));
	else if (spicifier == '%')
		count += ft_putchar('%');
	else
		count += ft_putchar(spicifier);
	return (count);
}

static int	print_it(const char *str, va_list ap)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (check(str[i + 1]))
				count += print_format(str[++i], ap);
			else
				if (str[i + 1])
					count += ft_putchar(str[i]);
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
