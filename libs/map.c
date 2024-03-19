/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 19:11:36 by mkadri            #+#    #+#             */
/*   Updated: 2024/03/19 14:58:38 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
int	count_lines(char *argv, t_game *game)
{
	char	*line;
	
	game->map_height = 0;
	game->fd = open(argv, O_RDONLY);
	if(game->fd < 0)
		return (0);
    while ((line = get_next_line(game->fd)) != NULL) {
        game->map_height++;
        free(line);   
    }
	close(game->fd);
	return(game->map_height);
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
		printf("%s", game->map[i]); 
		free(line);
		i++;
	}
	game->map[i] = NULL;
	close(game->fd);
	return (game->map);
}

