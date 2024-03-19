/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:27:51 by mkadri            #+#    #+#             */
/*   Updated: 2024/03/19 14:09:14 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libs/so_long.h"
#include "get_next_line/get_next_line.h"

int	main(int argc, char **argv)
{
	int 		map_extension;
	t_game		game;

	map_extension = verif_args(argc, argv[1]);
	if(map_extension)
	{
		ft_memset(&game, 0, sizeof(t_game));
		parsing_map(argv[1], &game);
	}
}
