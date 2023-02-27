/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccerri <ccerri@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 11:08:20 by ccerri            #+#    #+#             */
/*   Updated: 2023/02/27 18:54:24 by ccerri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(int fd, char *line)
{
	int		byte_read;
	char	*buffer;

	byte_read = 1;
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (!ft_strchr(line, '\n') && byte_read > 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[byte_read] = '\0';
		line = ft_strjoin(line, buffer);
	}
	free(buffer);
	return (line);
}

char	*toma_la_nueva_linea(char *line)
{
	int		i;
	char	*new_line;

	i = 0;
	if (!line[i])
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	new_line = (char *)malloc((i + 2) * sizeof(char));
	if (!new_line)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		new_line[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
	{
		new_line[i] = '\n';
		i++;
	}
	new_line[i] = 0;
	return (new_line);
}

char	*linea_limpia(char *line)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	j = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i])
	{
		free(line);
		return (NULL);
	}
	new = (char *)malloc((ft_strlen(line) - i + 1) * sizeof(char));
	if (!new)
		return (NULL);
	i++;
	while (line[i])
		new[j++] = line[i++];
	new[j] = '\0';
	free(line);
	return (new);
}

char	*get_next_line(int fd)
{
	char		*s_return;
	static char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = get_line(fd, line);
	if (!line)
		return (NULL);
	s_return = toma_la_nueva_linea(line);
	line = linea_limpia(line);
	return (s_return);
}
