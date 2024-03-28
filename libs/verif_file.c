/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:18:49 by mkadri            #+#    #+#             */
/*   Updated: 2024/03/28 01:47:02 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char *ft_strstr(char *str, char *to_find)
{
    int i;
    int j;

    i = 0;
    while (str[i] != '\0')
    {
        j = 0;
        while (to_find[j] == str[i + j])
        {
            if (to_find[j + 1] == '\0')
            {
                return (str + i);
            }
            j++;
        }
        i++;
    }
    return (0);
}
int	verify_map_extension(char *map_path)
{
    int		i;
    char	*extension;
    char	*valid_file;

    i = 0;
    extension = ".ber";
    valid_file = ft_strstr(map_path, extension);
    if (!valid_file)
    {
      perror("Invalid file extension\n");
      exit (1);
    }
    return (1);
}
