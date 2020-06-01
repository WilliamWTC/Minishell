/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmabitse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 18:03:00 by lmabitse          #+#    #+#             */
/*   Updated: 2019/09/24 16:52:38 by william          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include "libft.h"
# include <stdlib.h>
# define BUFF_SIZE 8
# define MAX_FD 1024 + 1
# define RET_VALUE(ret)	ret > 0 ? 1 : ret

int		get_next_line(int const fd, char **line);

#endif
