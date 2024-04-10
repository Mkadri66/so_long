/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 20:28:41 by mkadri            #+#    #+#             */
/*   Updated: 2023/11/17 23:58:25 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_digits(long n, int base)
{
	int		count;
	char	*symbols;

	count = 0;
	symbols = "0123456789";
	if (n < 0)
	{
		write(1, "-", 1);
		return (print_digits(-n, base) + 1);
	}
	else if (n < base)
		return (print_char(symbols[n]));
	else
	{
		count = print_digits(n / base, base);
		return (count + print_digits(n % base, base));
	}
	return (count);
}

int	print_format(char format, va_list args)
{
	int	count;
	int	is_upper;

	count = 0;
	is_upper = 0;
	if (format == 'c')
		count += print_char(va_arg(args, int));
	else if (format == 's')
		count += print_str(va_arg(args, char *));
	else if (format == 'd' || format == 'i')
		count += print_digits((long)(va_arg(args, int)), 10);
	else if (format == 'x' || format == 'X')
	{
		if (format == 'X')
			is_upper = 1;
		count += print_hexa((long)(va_arg(args, unsigned int)), 16, is_upper);
	}
	else if (format == 'p')
		count += print_pointer((unsigned long)(va_arg(args, unsigned long)));
	else if (format == 'u')
		count += print_unsigned((unsigned long int)(va_arg(args, void *)));
	else
		count += write(1, &format, 1);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, str);
	while (*str != '\0')
	{
		if (*str == '%')
			count += print_format(*(++str), args);
		else
			count += write(1, str, 1);
		str++;
	}
	va_end(args);
	return (count);
}
