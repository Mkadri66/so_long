/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:34:28 by mkadri            #+#    #+#             */
/*   Updated: 2024/03/14 00:14:36 by mkadri           ###   ########.fr       */
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

typedef struct t_map
{
	int		fd;
	char	**map;
	
	
} t_map;

int		verify_map_extension(char *map_path);
int		verif_args(int argc, char *path_map);
char	**parsing_map(char *argv);
int		count_lines(char *argv);

#endif