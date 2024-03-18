/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 19:11:36 by mkadri            #+#    #+#             */
/*   Updated: 2024/03/18 15:02:11 by mkadri           ###   ########.fr       */
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
int	count_lines(char *argv)
{
	char	*line;
	int	   	fd;
	int 	count_line;
	
	count_line = 0;
	fd = open(argv, O_RDONLY);
	if(fd < 0)
		return (0);
    while ((line = get_next_line(fd)) != NULL) {
        count_line++;
        free(line);   
    }
	close(fd);
	return(count_line);
}
char	**parsing_map(char *argv)
{
	char	**map_parsed;
	int		i;
	char	*line;
	int		fd;

	map_parsed = (char **) malloc(sizeof(char*) * (count_lines(argv) + 1));
	i = 0; 
	fd = open(argv, O_RDONLY);
	if(fd < 0)
		return (0);
	while (i < count_lines(argv)) {
        map_parsed[i] = get_next_line(fd);
        free(line);
		i++;
    }
	map_parsed[i] = NULL;
	return(map_parsed);
}
