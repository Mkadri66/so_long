/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verifier.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 19:11:36 by mkadri            #+#    #+#             */
/*   Updated: 2024/03/13 14:06:45 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	verify_map_extension(char *map_path)
{
		int i;
		int j;
		char *extension = ".ber";
		
		i = 0;
		j = 0;
		if(map_path[i] == '.')
			i++;
		while(map_path[i]!= '\0' && map_path[i + 1] != '.')
			i++;
		i++;
		while(map_path[i] != '\0')
		{
			if(map_path[i] != extension[j])
			{
				write(1, "Wrong file extension", 21);
				return(0);
			}
			i++;
			j++;
		}
		return(1);
}

int	parsing_map(char *argv)
{

	char 	*line;
	int	   	fd;
	
	fd = open(argv, O_RDONLY);
	if(fd < 0)
		return (0);
    while ((line = get_next_line(fd)) != NULL) {
        printf("%s\n", line);
        free(line); // N'oubliez pas de libérer la mémoire allouée par get_next_line
    }
	close(fd); 
	return(0);
}
