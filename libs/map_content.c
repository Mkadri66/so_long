/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_content.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <mkadri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 01:14:54 by mkadri            #+#    #+#             */
/*   Updated: 2024/04/02 02:35:31 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_content(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j] != '\n' && game->map[i][j] != '\0')
		{
			if (game->map[i][j] != '1' && game->map[i][j] != '0'
				&& game->map[i][j] != 'P'
				&& game->map[i][j] != 'C' && game->map[i][j] != 'E')
			{
				perror("Map is incorrect (must contain only : 1,0,P,C,E)");
				return (0);
			}
			j++;
		}
		i++;
	}
	count_content(game);
	return (1);
}

int	count_content(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	game->player_count = 0;
	game->collectable_count = 0;
	game->exit_count = 0;
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (game->map[i][j] == 'P')
				game->player_count++;
			if (game->map[i][j] == 'C')
				game->collectable_count++;
			if (game->map[i][j] == 'E')
				game->exit_count++;
			j++;
		}
		i++;
	}
	count_check(game);
	return (1);
}

int	count_check(t_game *game)
{
	if (! (game->player_count == 1
			&& game->exit_count == 1 && game->collectable_count >= 1))
	{
		perror("Map is incorrect");
		exit(1);
	}
	return (1);
}
