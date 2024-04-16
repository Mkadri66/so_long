/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 19:11:36 by mkadri            #+#    #+#             */
/*   Updated: 2024/04/16 18:39:17 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdbool.h>

int	verify_is_map_rectangular(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map_height)
	{
		if ((int)(ft_strlen(game->map[0])) == game->map_height)
		{
			perror("Map cannot be a square");
			exit(0);
		}
		i++;
	}
	game->map_width = ft_strlen(game->map[0]);
	return (1);
}

int	top_bottom_walls(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[0][i] != '\0')
	{
		if (game->map[0][i] != '1')
		{
			perror("Top map must only contain wall");
			exit(1);
		}
		i++;
	}
	i = 0;
	while (game->map[game->map_height - 1][i] != '\0')
	{
		if (game->map[game->map_height - 1][i] != '1')
		{
			perror("Bottom map must only contain wall");
			exit(1);
		}
		i++;
	}
	body_map_walls(game);
	return (1);
}

int	body_map_walls(t_game *game)
{
	int	i;
	int	right_wall;

	i = 1;
	right_wall = ft_strlen(game->map[1]) - 1;
	while (i < game->map_height - 1)
	{
		if (game->map[i][0] != '1' || game->map[i][right_wall] != '1')
		{
			perror("Body map must be surrounded by walls");
			exit(1);
		}
		i++;
	}
	map_content(game);
	return (1);
}

char	**parsing_map(char *argv, t_game *game)
{
	char	*line;
	int		i;

	game->map = (char **) malloc(sizeof(char *) * (game->map_height + 1));
	game->map[game->map_height] = NULL;
	if (!game->map)
		return (NULL);
	game->fd = open(argv, O_RDONLY);
	if (game->fd < 0)
		return (NULL);
	i = 0;
	while (true)
	{
		line = get_next_line(game->fd);
		if(!line)
			break;
		game->map[i] = ft_strdup(line);
		free(line);
		i++;
	}
	close(game->fd);
	return (game->map);
}

int	verify_map(t_game *game)
{
	if (!verify_is_map_rectangular(game))
	{
		return (0);
	}
	top_bottom_walls(game);
	map_content(game);
	return (1);
}
