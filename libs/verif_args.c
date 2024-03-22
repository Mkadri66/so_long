/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:18:49 by mkadri            #+#    #+#             */
/*   Updated: 2024/03/19 14:55:55 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	verif_args(int argc, char *path_map)
{
	if (argc == 2)
	{
		verify_map_extension(path_map);
		return (1);
	}
	else
	{
		perror("Please enter only two arguments : ./so_long + map path");
		return (0);
	}
}
