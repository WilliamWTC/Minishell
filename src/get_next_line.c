/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmolaodi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 13:31:47 by lmolaodi          #+#    #+#             */
/*   Updated: 2019/07/16 12:45:43 by lmolaodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	ft_check_line(int fd, char **file, char **buff)
{
	int			i;

	i = 0;
	while (file[fd][i] != '\n' && file[fd][i])
		i++;
	if (file[fd][i] == '\n')
	{
		*buff = ft_strsub(file[fd], 0, i);
		tmp_fd = ft_strdup(file[fd] + i + 1);
		free(file[fd]);
		file[fd] = tmp_fd;
	}
	else
	{
		*buff = file[fd];
		file[fd] = NULL;
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char	*file[1024];
	char		text[BUFF_SIZE];
	char		*temp;
	int			red_fd;

	if (fd == -1 || line == NULL || read(fd, text, 0))
		return (-1);
	if (file[fd] == NULL)
		file[fd] = ft_strnew(0);
	while ((red_fd = read(fd, text, BUFF_SIZE)) > 0)
	{
		text[red_fd] = '\0';
		temp = ft_strjoin(file[fd], text);
		free(file[fd]);
		file[fd] = temp;
		if (ft_strchr(file[fd], '\n'))
			break ;
	}
	if (red_fd == 0 && file[fd][0] == '\0')
	{
		*line = NULL;
		return (0);
	}
	return (ft_check_line(fd, file, line));
}
