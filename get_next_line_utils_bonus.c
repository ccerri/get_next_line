/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccerri <ccerri@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 18:33:22 by ccerri            #+#    #+#             */
/*   Updated: 2023/02/27 18:57:13 by ccerri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int	ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != 0)
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *line, char *buf)
{
	char	*s3;
	int		i;
	int		j;

	if (!line)
	{
		line = (char *)malloc(sizeof(char) * 1);
		line[0] = '\0';
	}
	if (!buf)
		return (NULL);
	s3 = (char *)malloc((ft_strlen(line) + ft_strlen(buf) + 1) * sizeof(char));
	if (!s3)
		return (NULL);
	i = 0;
	j = 0;
	while (line[i])
		s3[j++] = line[i++];
	i = 0;
	while (buf[i])
		s3[j++] = buf[i++];
	s3[j] = 0;
	free(line);
	return (s3);
}
