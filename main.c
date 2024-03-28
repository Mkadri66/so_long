/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:27:51 by mkadri            #+#    #+#             */
/*   Updated: 2024/03/28 01:30:11 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libs/so_long.h"
#include "get_next_line/get_next_line.h"

int	main(int argc, char **argv)
{
	t_game		game;

	if(argc != 2)
		return(0);
	verify_map_extension(argv[1]);
	parsing_map(argv[1], &game);
	verify_map(&game);
	return(0);
}
