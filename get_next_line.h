/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccerri <ccerri@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:02:38 by ccerri            #+#    #+#             */
/*   Updated: 2023/02/27 18:57:51 by ccerri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

int		ft_strlen(char *s);
int		ft_strchr(char *s, int c);
char	*ft_strjoin(char *line, char *buf);
char	*get_next_line(int fd);
char	*get_line(int fd, char *line);

#endif