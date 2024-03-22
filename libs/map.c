/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 19:11:36 by mkadri            #+#    #+#             */
/*   Updated: 2024/03/22 03:29:29 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int verify_is_map_rectangular(t_game *game)
{
	int	i;

	i = 0;
	while(i < game->map_height)
	{
		if((ft_strlen(game->map[0]) - 1) == game->map_height)
		{
			
			perror("Map cannot be a square");
			return(0);
		}
		i++;
	}
	return(1);
}

int	verify_map_extension(char *map_path)
{
		int i;
		int j;
		char *extension = ".ber";
		
		i = 0;
		j = 0;
		if(map_path[i] == '.')
			i++;
		while(map_path[i]!= '\0' && map_path[i + 1] != '.')
			i++;
		i++;
		while(map_path[i] != '\0')
		{
			if(map_path[i] != extension[j])
			{
				write(1, "Wrong file extension", 21);
				return(0);
			}
			i++;
			j++;
		}
		return(1);
}

char	**parsing_map(char *argv, t_game *game)
{
	char	*line;
	int		i;

	game->map = (char **)malloc(sizeof(char *) * (game->map_height + 1));
	if (!game->map)
		return (NULL);
	game->fd = open(argv, O_RDONLY);
	if (game->fd < 0)
		return (NULL);
	i = 0;
	while ((line = get_next_line(game->fd)) != NULL)
	{
		game->map[i] = ft_strdup(line);
		free(line);
		i++;
	}
	game->map_height = i;
	game->map[i] = NULL;
	close(game->fd);
	return (game->map);
}

int	verify_map(t_game *game)
{
	if(!verify_is_map_rectangular(game))
		return(0);
	return(1);
}
