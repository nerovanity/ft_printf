/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihamani <ihamani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 10:59:55 by ihamani           #+#    #+#             */
/*   Updated: 2024/12/24 10:57:16 by ihamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putnbr(int nbr);
int		ft_putunbr(unsigned int nbr);
int		print_lhex(size_t t);
int		print_uhex(size_t t);
int		ft_print_mem(size_t t);
size_t	ft_strlen(char const *str);
int		ft_printf(const char *str, ...);

#endif