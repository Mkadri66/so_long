/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:18:49 by mkadri            #+#    #+#             */
/*   Updated: 2024/03/25 01:29:57 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	verif_args(int argc, char *path_map)
{
	if (argc == 2)
	{
		verify_map_extension(path_map);
		return (1);
	}
	else
	{
		perror("Please enter only two arguments : ./so_long + map path");
		return (0);
	}
}

int	verify_map_extension(char *map_path)
{
	int		i;
	int		j;
	char	*extension;

	i = 0;
	j = 0;
	extension = ".ber";
	if (map_path[i] == '.')
		i++;
	while (map_path[i] != '\0' && map_path[i + 1] != '.')
		i++;
	i++;
	while (map_path[i] != '\0')
	{
		if (map_path[i] != extension[j])
		{
			write(1, "Wrong file extension", 21);
			return (0);
		}
		i++;
		j++;
	}
	return (1);
}
