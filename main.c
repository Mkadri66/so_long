/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:27:51 by mkadri            #+#    #+#             */
/*   Updated: 2024/04/16 18:36:30 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libs/so_long.h"
#include "get_next_line/get_next_line.h"

void print_t_game(const t_game *game) {
    printf("fd: %d\n", game->fd);
    printf("map:\n");
    for (int i = 0; game->map[i] != NULL; i++) {
        printf("%s\n", game->map[i]);
    }
    printf("map_width: %d\n", game->map_width);
    printf("map_height: %d\n", game->map_height);
    printf("player_count: %d\n", game->player_count);
    printf("collectable_count: %d\n", game->collectable_count);
    printf("exit_count: %d\n", game->exit_count);
    printf("x: %d\n", game->x);
    printf("y: %d\n", game->y);
    printf("movement: %d\n", game->movement);
    printf("mlx_pointer: %p\n", game->mlx_pointer);
    printf("mlx_win_pointer: %p\n", game->mlx_win_pointer);
    printf("player: %p\n", game->player);
    printf("floor: %p\n", game->floor);
    printf("collectables: %p\n", game->collectables);
    printf("walls: %p\n", game->walls);
    printf("exit: %p\n", game->exit);
    printf("original_map:\n");
}

int	main(int argc, char **argv)
{
	t_game		game;

	if (argc != 2)
	{
		arg_error(&game);
		return (0);
	}
	if(!verify_file_exist(argv[1]))
		return(0);
	ft_memset(&game, 0, sizeof(game));
	map_height_length(argv[1], &game);
	verify_map_extension(argv[1]);
	parsing_map(argv[1], &game);
	verify_map(&game);
	print_t_game(&game);
	game_init(&game);
	mlx_key_hook(game.mlx_win_pointer, game_controls, &game);
	mlx_loop(game.mlx_pointer);
	return (0);
}
