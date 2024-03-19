/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utilis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:06:24 by mkadri            #+#    #+#             */
/*   Updated: 2024/03/19 14:23:04 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

void	*ft_memset(void *array, int value, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		*((unsigned char *)(array + i)) = (unsigned char)value;
		i++;
	}
	return (array);
}

char	*ft_strdup(const char *str)
{
	char	*str_copy;
	int		str_size;
	int		i;

	i = 0;
	str_size = ft_strlen(str);
	str_copy = (char *) malloc ((str_size + 1) * sizeof(char));
	if (!str || !str_copy)
		return (NULL);
	while (str[i] != '\0')
	{
		str_copy[i] = str[i];
		i++;
	}
	str_copy[i] = '\0';
	return (str_copy);
}