/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:05:40 by mkadri            #+#    #+#             */
/*   Updated: 2023/11/18 00:08:22 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_putnbr_base(unsigned long nbr, char *base)
{
	int	i;

	i = 0;
	if (nbr < 16)
		return (print_char(base[nbr]));
	if (nbr >= 16)
	{
		i = i + ft_putnbr_base(nbr / 16, base);
		i = i + ft_putnbr_base(nbr % 16, base);
	}
	return (i);
}

int	print_pointer(unsigned long ptr)
{
	if (!ptr)
		return (print_str("(nil)"));
	return (print_str("0x") + ft_putnbr_base(ptr, "0123456789abcdef"));
}
