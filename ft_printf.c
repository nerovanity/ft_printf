/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihamani <ihamani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 13:43:01 by ihamani           #+#    #+#             */
/*   Updated: 2024/12/25 11:02:08 by ihamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

static int	print_format(char const *str, int *i, va_list ap)
{
	int	count;

	count = 0;
	(*i)++;
	if (str[*i] == 'c')
		count += ft_putchar(va_arg(ap, int));
	else if (str[*i] == 's')
		count += ft_putstr(va_arg(ap, char *));
	else if (str[*i] == 'd' || str[*i] == 'i')
		count += ft_putnbr(va_arg(ap, int));
	else if (str[*i] == 'u')
		count += ft_putunbr(va_arg(ap, unsigned int));
	else if (str[*i] == 'x')
		count += print_lhex(va_arg(ap, unsigned int));
	else if (str[*i] == 'X')
		count += print_uhex(va_arg(ap, unsigned int));
	else if (str[*i] == 'p')
		count += ft_print_mem(va_arg(ap, size_t));
	else if (str[*i] == '%')
		count += ft_putchar('%');
	(*i)++;
	return (count);
}

static int	print_it(const char *str, va_list ap)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (i < (int)ft_strlen(str))
	{
		if (str[i] == '%')
		{
			if (check(str[i + 1]))
				count += print_format(str, &i, ap);
			else if (!str[i + 1])
				return (-1);
			else
				count += ft_putchar(str[i++]);
		}
		else
			count += ft_putchar(str[i++]);
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		count;

	if (!str)
		return (-1);
	va_start(ap, str);
	count = print_it(str, ap);
	va_end(ap);
	if (count == 0 && ft_strlen(str))
		return (-1);
	return (count);
}
