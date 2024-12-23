/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihamani <ihamani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 18:41:17 by ihamani           #+#    #+#             */
/*   Updated: 2024/12/23 10:38:49 by ihamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putchar(char c)
{
    write(1, &c, 1);
    return (1);
}

int ft_putstr(char *str)
{
    int i;
    int count;

    if (str == NULL)
        return ft_putstr("(null)");
    i = 0;
    count = 0;
    while (str[i])
    {
        count += ft_putchar(str[i]);
        i++;
    }
    return (count);
}

int ft_putnbr(int nbr)
{
	unsigned int	n;
	char			arr_nums[10];
	int				i;
    int             count;

    count = 0;
	if (nbr == 0)
    {
		return (ft_putchar('0'));
    }
	if (nbr < 0)
	{
		n = -nbr;
		count += (ft_putchar('-'));
	}
	else
		n = nbr;
	i = 0;
	while (n)
	{
		arr_nums[i++] = (n % 10) + '0';
		n /= 10;
	}
	while (i > 0)
		count += (ft_putchar(arr_nums[--i]));
    return (count);
}

unsigned int ft_putunbr(unsigned int nbr)
{
	char			arr_nums[10];
	int				i;
    int             count;

    count = 0;
	if (nbr == 0)
    {
		return (ft_putchar('0'));
    }
	i = 0;
	while (nbr)
	{
		arr_nums[i++] = (nbr % 10) + '0';
		nbr /= 10;
	}
	while (i > 0)
		count += (ft_putchar(arr_nums[--i]));
    return (count);
}

int print_lhex(size_t t)
{
    int count = 0;

    if (t >= 16)
        count += print_lhex(t / 16);
    count += write(1, &"0123456789abcdef"[t % 16], 1);
    return count;
}