/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:34:28 by mkadri            #+#    #+#             */
/*   Updated: 2024/04/17 16:43:52 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../get_next_line/get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdbool.h>

typedef struct t_game
{
	int		fd;
	char	**map;
	int		map_width;
	int		map_height;
	int		player_count;
	int		collectable_count;
	int		exit_count;
	int		x;
	int		y;
	int		movement;

	void	*mlx_pointer;
	void	*mlx_win_pointer;
	void	*player;
	void	*floor;
	void	*collectables;
	void	*walls;
	void	*exit;
}	t_game;

int		verify_map_extension(char *map_path);
int		verify_file_exist(char *file_path);
int		verif_args(int argc, char *path_map);
char	**parsing_map(char *argv, t_game *game);
void	*ft_memset(void *array, int value, size_t count);
char	*ft_strdup(const char *str);
void	arg_error(t_game *game);
int		verify_map(t_game *game);
int		count_content(t_game *game);
int		map_content(t_game *game);
void 	map_height_length(char *map_path, t_game *game);
int		count_check(t_game *game);
int		body_map_walls(t_game *game);

void	game_init(t_game *game);
int		game_controls(int key, t_game *game);
void	cross_exit(t_game *game);
int		exit_game(int key, t_game *game);
void	print_game_info(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);
void	move_up(t_game *game);
void	move_down(t_game *game);
void	display_player(t_game *game, int height, int width);
void	display_collectable(t_game *game, int height, int width);
void	display_sprites(t_game *game);
void	display_sprite(t_game *game, void *sprite, int width, int height);
void	set_images_in_map(t_game *game);

int		ft_printf(const char *str, ...);

#endif
