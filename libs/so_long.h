/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:34:28 by mkadri            #+#    #+#             */
/*   Updated: 2024/03/22 03:21:31 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "../mlx/mlx.h"
#include "../get_next_line/get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

typedef struct t_game
{
	int		fd;
	char	**map;
	int 	map_width;
	int		map_height;
	int		player_count;
	int		collectable_count;
	int		exit_count;
} t_game;

int		verify_map_extension(char *map_path);
int		verif_args(int argc, char *path_map);
char	**parsing_map(char *argv, t_game *game);
void	*ft_memset(void *array, int value, size_t count);
char	*ft_strdup(const char *str);
int		verify_map(t_game *game);

#endif