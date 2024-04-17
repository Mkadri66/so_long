/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:27:51 by mkadri            #+#    #+#             */
/*   Updated: 2024/04/17 22:52:51 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libs/so_long.h"
#include "get_next_line/get_next_line.h"

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
	game_init(&game);
	mlx_key_hook(game.mlx_win_pointer, game_controls, &game);
	mlx_hook(game.mlx_win_pointer,17, 0L, exit_game, &game);
	mlx_loop(game.mlx_pointer);
	return (0);
}
