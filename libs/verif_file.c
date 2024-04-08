/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <mkadri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:18:49 by mkadri            #+#    #+#             */
/*   Updated: 2024/04/08 00:44:08 by mkadri           ###   ########.fr       */
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
    char	*extension;
    char	*valid_file;

    extension = ".ber";
    valid_file = ft_strstr(map_path, extension);
    if (!valid_file)
    {
      perror("Invalid file extension\n");
      exit (1);
    }
    return (1);
}

void    arg_error()
{
    perror("Only two arguments : ./so_long and a map");
}
