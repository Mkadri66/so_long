/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:24:07 by mkadri            #+#    #+#             */
/*   Updated: 2023/11/18 00:05:38 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	num_len(unsigned	int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 10;
	}
	return (len);
}

static char	*uitoa(unsigned int n)
{
	char	*num;
	int		len;

	len = num_len(n);
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
		return (0);
	num[len] = '\0';
	while (n != 0)
	{
		num[len - 1] = n % 10 + 48;
		n = n / 10;
		len--;
	}
	return (num);
}

int	print_unsigned(int n)
{
	int		print_length;
	char	*num;

	print_length = 0;
	if (n == 0)
		print_length += write(1, "0", 1);
	else
	{
		num = uitoa(n);
		print_length += print_str(num);
		free(num);
	}
	return (print_length);
}
