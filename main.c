/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:27:51 by mkadri            #+#    #+#             */
/*   Updated: 2024/03/18 14:58:24 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libs/so_long.h"
#include "get_next_line/get_next_line.h"

int	main(int argc, char **argv)
{
	int 	map_extension;

	map_extension = verif_args(argc, argv[1]);
	if(map_extension)
	{
		parsing_map(argv[1]);
	}
}
