/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihamani <ihamani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 13:43:01 by ihamani           #+#    #+#             */
/*   Updated: 2024/12/24 13:52:04 by ihamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check(char c)
{
	char	*flags;
	int		i;

	flags = "csduxiXp";
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
		count += ft_print_mem(va_arg(ap, size_t));
	return (count);
}

static int	handle_percent(const char *str, int *i)
{
	int	percent_count;

	percent_count = 0;
	while (str[*i] == '%')
	{
		percent_count++;
		(*i)++;
	}
	if (percent_count % 2 != 0)
		return (0);
	return (percent_count / 2);
}

static int	print_it(const char *str, va_list ap)
{
	int	count;
	int	i;
	int pairs;

	count = 0;
	i = 0;
	while (i < (int)ft_strlen(str))
	{
		if (str[i] == '%')
		{
            if (check(str[i + 1]))
                count += print_format(str[++i], ap);clean
            pairs = handle_percent(str, &i);
            while (pairs-- > 0)
                count += ft_putchar('%');
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

	if (!str)
		return (-1);
	va_start(ap, str);
	count = print_it(str, ap);
	va_end(ap);
	if (count == 0 && ft_strlen(str))
		return (-1);
	return (count);
}
