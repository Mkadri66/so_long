/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:27:51 by mkadri            #+#    #+#             */
/*   Updated: 2024/03/08 19:54:28 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	if(argc == 2)
	{
		int i;
		int j;
		char *extension = "ber";
		
		i = 0;
		j = 0;
		if(argv[1][i] == '.')
			i++;
		while(argv[1][i] != '\0' && argv[1][i] != '.')
			i++;
		i++;
		while(argv[1][i] != '\0')
		{
			if(argv[1][i] != extension[j])
			{
				write(1, "Wrong file extension", 21);
				return(0);
			}
			i++;
			j++;
		}
		i = 0;
		while(argv[1][i] == '/' || argv[1][i] == '.')
			i++;
		while(argv[1][i] != '/')
			i++;
		i++;

		while(argv[1][i] != '\0')
		{
			write(1, &argv[1][i], 1);
			i++;
		}
		
	}
	
	// void	*mlx;
	// void	*mlx_win;

	// mlx = mlx_init();
	// mlx_win = mlx_new_window(mlx, 700, 400, "Hello world!");
	// (void) mlx_win;
	// mlx_loop(mlx);
}
