/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 01:57:06 by mkadri            #+#    #+#             */
/*   Updated: 2024/04/26 18:10:58 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_player(t_game *game, int height, int width)
{
	mlx_put_image_to_window(game->mlx_pointer,
		game->mlx_win_pointer, game->player, width * 50, height * 50);
	game->y = height;
	game->x = width;
}

void	display_collectable(t_game *game, int height, int width)
{
	mlx_put_image_to_window(game->mlx_pointer,
		game->mlx_win_pointer, game->collectables, width * 50, height * 50);
	game->collectable_count++;
}

void	set_images_in_map(t_game *game)
{
	int		i;
	int		j;
	char	*mlx;

	mlx = game->mlx_pointer;
	game->floor = NULL;
	game->walls = NULL;
	game->player = NULL;
	game->exit = NULL;
	game->collectables = NULL;
	game->x = 0;
	game->y = 0;
	game->floor = mlx_xpm_file_to_image(mlx, "images/floor.xpm", &i, &j);
	game->walls = mlx_xpm_file_to_image(mlx, "images/walls.xpm", &i, &j);
	game->player = mlx_xpm_file_to_image(mlx, "images/player.xpm", &i, &j);
	game->exit = mlx_xpm_file_to_image(mlx, "images/exit.xpm", &i, &j);
	game->collectables = mlx_xpm_file_to_image(mlx,
			"images/collectables.xpm", &i, &j);
}

void	display_sprite(t_game *game, void *sprite, int width, int height)
{
	mlx_put_image_to_window(game->mlx_pointer,
		game->mlx_win_pointer, sprite, width * 50, height * 50);
}

void	display_sprites(t_game *game)
{
	int	height;
	int	width;

	game->collectable_count = 0;
	height = 0;
	while (height < game->map_height)
	{
		width = 0;
		while (game->map[height][width])
		{
			if (game->map[height][width] == '1')
				display_sprite(game, game->walls, width, height);
			if (game->map[height][width] == '0')
				display_sprite(game, game->floor, width, height);
			if (game->map[height][width] == 'C')
				display_collectable(game, height, width);
			if (game->map[height][width] == 'P')
				display_player(game, height, width);
			if (game->map[height][width] == 'E')
				display_sprite(game, game->exit, width, height);
			width++;
		}
		height++;
	}
}
