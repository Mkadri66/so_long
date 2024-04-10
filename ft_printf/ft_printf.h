/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:08:57 by mkadri            #+#    #+#             */
/*   Updated: 2024/04/10 19:12:35 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <ctype.h>
# include <stddef.h>

int	ft_printf(const char *str, ...);
int	print_hexa(long n, int base, int is_upper);
int	print_char(int c);
int	print_str(char *str);
int	print_pointer(unsigned long ptr);
int	print_unsigned(int n);

#endif