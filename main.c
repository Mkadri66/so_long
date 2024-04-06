/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:27:51 by mkadri            #+#    #+#             */
/*   Updated: 2024/04/06 01:07:41 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libs/so_long.h"
#include "get_next_line/get_next_line.h"

int	close_game(int key, t_game *game)
{
	if (key == 53)
	{
		printf("Escape key pressed. Exiting game.\n");
		free(game); 
		exit(0); 
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_game		game;

	if (argc != 2)
		return (0);
	verify_map_extension(argv[1]);
	parsing_map(argv[1], &game);
	verify_map(&game);
	game_init(&game);
	mlx_hook(game.mlx_win_pointer, KeyPress, KeyPressMask, &close_game, &game);
	mlx_loop(game.mlx_pointer);
	return (0);
}
