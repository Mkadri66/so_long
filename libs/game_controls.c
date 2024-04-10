/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_controls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 03:42:54 by mkadri            #+#    #+#             */
/*   Updated: 2024/04/10 02:26:45 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <X11/keysym.h>

void	move_left(t_game *game)
{
	char	left_box;

	left_box = game->map[game->y][game->x - 1];
	if (left_box == '0' || left_box == 'C' || left_box == 'E')
	{
		if (left_box == 'C')
		{
			game->collectable_count++;
		}
		if (left_box == 'E' && game->collectable_count != 0)
			return ;
		if (left_box == 'E' && game->collectable_count == 0)
		{
			exit_game(0, game);
		}
		game->map[game->y][game->x] = '0';
		game->x -= 1;
		game->map[game->y][game->x] = 'P';
		game->movement++;
	}
}

void	move_right(t_game *game)
{
	char	right_box;

	right_box = game->map[game->y][game->x + 1];
	if (right_box == '0' || right_box == 'C' || right_box == 'E')
	{
		if (right_box == 'C')
		{
			game->collectable_count++;
		}
		if (right_box == 'E' && game->collectable_count != 0)
			return ;
		if (right_box == 'E' && game->collectable_count == 0)
		{
			exit_game(0, game);
		}
		game->map[game->y][game->x] = '0';
		game->x += 1;
		game->map[game->y][game->x] = 'P';
		game->movement++;
	}
}

void	move_up(t_game *game)
{
	char	up_box;

	up_box = game->map[game->y - 1][game->x];
	if (up_box == '0' || up_box == 'C' || up_box == 'E')
	{
		if (up_box == 'C')
		{
			game->collectable_count++;
		}
		if (up_box == 'E' && game->collectable_count != 0)
			return ;
		if (up_box == 'E' && game->collectable_count == 0)
		{
			exit_game(0, game);
		}
		game->map[game->y][game->x] = '0';
		game->y -= 1;
		game->map[game->y][game->x] = 'P';
		game->movement++;
	}
}

void	move_down(t_game *game)
{
	char	down_box;

	down_box = game->map[game->y + 1][game->x];
	if (down_box == '0' || down_box == 'C' || down_box == 'E')
	{
		if (down_box == 'C')
		{
			game->collectable_count++;
		}
		if (down_box == 'E' && game->collectable_count != 0)
			return ;
		if (down_box == 'E' && game->collectable_count == 0)
		{
			exit_game(0, game);
		}
		game->map[game->y][game->x] = '0';
		game->y += 1;
		game->map[game->y][game->x] = 'P';
		game->movement++;
	}
}

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
	printf("Movements : %d \n", game->movement);
	return (0);
}
