/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_controls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 03:42:54 by mkadri            #+#    #+#             */
/*   Updated: 2024/04/06 04:15:01 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <X11/keysym.h>

int	exit_game(int key, t_game *game)
{
	int	i;

	i = 0;
	mlx_destroy_window(game->mlx_pointer, game->mlx_win_pointer);
	while (i < game->map_height - 1)
		free(game->map[i++]);
	free(game->map);
	(void) key;
	exit(0);
	return (0);
}

int	game_controls(int key, t_game *game)
{
	if(key == XK_Escape)
		exit_game(key, game);
	return(0);
}

