/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:18:39 by mkadri            #+#    #+#             */
/*   Updated: 2023/11/18 00:06:00 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hexa(long n, int base, int is_upper)
{
	int		count;
	char	*symbols;

	count = 0;
	if (is_upper == 1)
		symbols = "0123456789ABCDEF";
	else
		symbols = "0123456789abcdef";
	if (n < 0)
	{
		write(1, "-", 1);
		return (print_hexa(-n, base, is_upper) + 1);
	}
	else if (n < base)
		return (print_char(symbols[n]));
	else
	{
		count = print_hexa(n / base, base, is_upper);
		return (count + print_hexa(n % base, base, is_upper));
	}
	return (count);
}
