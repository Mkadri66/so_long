/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 20:25:46 by mkadri            #+#    #+#             */
/*   Updated: 2024/04/26 16:22:32 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_file(int fd, char *temp)
{
	long	bytes_read;
	char	*buffer;

	bytes_read = 1;
	buffer = (char *)malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!buffer)
		return (NULL);
	while (bytes_read > 0 && !ft_strchr(temp, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(temp, buffer);
	}
	free(buffer);
	return (temp);
}

char	*make_line(char *temp)
{
	unsigned long	i;
	char			*line;

	i = 0;
	if (!temp[i])
		return (NULL);
	while (temp[i] != '\n' && temp[i] != '\0')
		i++;
	line = (char *) malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (temp[i] != '\n' && temp[i] != '\0')
	{
		line[i] = temp[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*clean_temp(char *temp)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (temp[i] && temp[i] != '\n')
		i++;
	if (!temp[i])
	{
		free(temp);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(temp) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (temp[i])
		str[j++] = temp[i++];
	str[j] = '\0';
	free(temp);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*temp;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp = read_file(fd, temp);
	if (!temp)
	{
		free(temp);
		return (NULL);
	}
	line = make_line(temp);
	temp = clean_temp(temp);
	return (line);
}
/*
int main() {
    //int fileDescriptor = 4;
    int fileDescriptor = open("file.txt", O_RDONLY);
    
    char *line;

    while((line = get_next_line(fileDescriptor)) != NULL)
    {   
        printf("%s", line);
        free(line);
    }
    close(fileDescriptor);
    return 0;
}
*/