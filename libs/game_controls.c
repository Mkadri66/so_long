/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_controls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <mkadri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 03:42:54 by mkadri            #+#    #+#             */
/*   Updated: 2024/04/08 00:55:39 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <X11/keysym.h>

void move_left(t_game *game)
{
    if (game->map[game->y][game->x - 1] == '0' || game->map[game->y][game->x - 1] == 'C' || game->map[game->y][game->x - 1] == 'E')
    {
        if (game->map[game->y][game->x - 1] == 'C')
        {
            game->collectable_count++;
        }
		if (game->map[game->y][game->x - 1] == 'E' && game->collectable_count != 0)
			return;
		if (game->map[game->y][game->x - 1] == 'E' && game->collectable_count == 0)
        {
            exit_game(0, game);
        }
        game->map[game->y][game->x] = '0';
        game->x -= 1;
        game->map[game->y][game->x] = 'P';
		game->movement++;
    }
}

void move_right(t_game *game)
{
    if (game->map[game->y][game->x + 1] == '0' || game->map[game->y][game->x + 1] == 'C' || game->map[game->y][game->x + 1] == 'E')
    {
        if (game->map[game->y][game->x + 1] == 'C')
        {
            game->collectable_count++;
        }
		if (game->map[game->y][game->x + 1] == 'E' && game->collectable_count != 0)
			return;
		if (game->map[game->y][game->x + 1] == 'E' && game->collectable_count == 0)
        {
            exit_game(0, game);
        }
        game->map[game->y][game->x] = '0';
        game->x += 1;
        game->map[game->y][game->x] = 'P';
		game->movement++;
    }
}

void move_up(t_game *game)
{
    if (game->map[game->y - 1][game->x] == '0' || game->map[game->y - 1][game->x] == 'C' || game->map[game->y - 1][game->x] == 'E')
    {
        if (game->map[game->y - 1][game->x] == 'C')
        {
            game->collectable_count++;
        }
		if (game->map[game->y - 1][game->x] == 'E' && game->collectable_count != 0)
			return;
		if (game->map[game->y - 1][game->x] == 'E' && game->collectable_count == 0)
        {
            exit_game(0, game);
        }
        game->map[game->y][game->x] = '0';
        game->y -= 1;
        game->map[game->y][game->x] = 'P';
		game->movement++;
    }
}

void move_down(t_game *game)
{
    if (game->map[game->y + 1][game->x] == '0' || game->map[game->y + 1][game->x] == 'C' || game->map[game->y + 1][game->x] == 'E')
    {
        if (game->map[game->y + 1][game->x] == 'C')
        {
            game->collectable_count++;
        }
		if (game->map[game->y + 1][game->x] == 'E' && game->collectable_count != 0)
			return;
		if (game->map[game->y + 1][game->x] == 'E' && game->collectable_count == 0)
        {
            exit_game(0, game);
        }
        game->map[game->y][game->x] = '0';
        game->y += 1;
        game->map[game->y][game->x] = 'P';
		game->movement++;
    }
}

int exit_game(int key, t_game *game)
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

int game_controls(int key, t_game *game)
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
    printf("Movements : %d  Item : %d \n", game->movement,game->collectable_count);
    return (0);
}
