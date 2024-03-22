/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 20:26:29 by mkadri            #+#    #+#             */
/*   Updated: 2024/02/23 22:29:29 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *str1, char *str2)
{
	char	*str_cat;
	int		i;
	int		j;

	if (!str1)
	{
		str1 = (char *) malloc (sizeof(char) * 1);
		str1[0] = '\0';
	}
	if (!str1 || !str2)
		return (NULL);
	i = 0;
	j = 0;
	str_cat = malloc(sizeof(char) * ((ft_strlen(str1) + ft_strlen(str2)) + 1));
	if (str_cat == NULL)
		return (NULL);
	i = -1;
	if (str1)
		while (str1[++i] != '\0')
			str_cat[i] = str1[i];
	while (str2[j] != '\0')
		str_cat[i++] = str2[j++];
	str_cat[ft_strlen(str1) + ft_strlen(str2)] = '\0';
	free(str1);
	return (str_cat);
}

char	*ft_strchr(const char *str, int searched_char)
{
	if (!str)
		return (NULL);
	while (*str != '\0' && *str != (char) searched_char)
		str++;
	if (*str == (char) searched_char)
	{
		return ((char *) str);
	}
	return (0);
}
