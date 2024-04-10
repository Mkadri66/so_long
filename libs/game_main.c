/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 19:05:08 by mkadri            #+#    #+#             */
/*   Updated: 2024/04/10 19:10:52 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <X11/keysym.h>

void	game_init(t_game *game)
{
	game->mlx_pointer = mlx_init();
	game->mlx_win_pointer = mlx_new_window(game->mlx_pointer,
			(game->map_width * 50), (game->map_height * 50), "So_Long");
	set_images_in_map(game);
	display_sprites(game);
	game->movement = 0;
}

int	game_controls(int key, t_game *game)
{
	if (key == XK_Escape || key == XK_Cancel)
		exit_game(key, game);
	else if (key == XK_Left)
		move_left(game);
	else if (key == XK_Right)
		move_right(game);
	else if (key == XK_Up)
		move_up(game);
	else if (key == XK_Down)
		move_down(game);
	mlx_clear_window(game->mlx_pointer, game->mlx_win_pointer);
	display_sprites(game);
	mlx_do_sync(game->mlx_pointer);
	ft_printf("Movements : %d \n", game->movement);
	return (0);
}
