/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihamani <ihamani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 18:41:26 by ihamani           #+#    #+#             */
/*   Updated: 2024/12/23 12:22:36 by ihamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_uhex(size_t t)
{
	int	count;

	count = 0;
	if (t >= 16)
		count += print_uhex(t / 16);
	count += write(1, &"0123456789ABCDEF"[t % 16], 1);
	return (count);
}

int	ft_print_mem(size_t t)
{
	int	count;

	count = 0;
	if (!t)
		return (ft_putstr("(nil)"));
	count += ft_putstr("0x");
	count += print_lhex(t);
	return (count);
}
