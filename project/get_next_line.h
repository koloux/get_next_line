/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 11:06:10 by nhuber            #+#    #+#             */
/*   Updated: 2016/03/26 15:04:21 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# define BUFF_SIZE 32

#include <stdio.h>

typedef struct		s_llst
{
	void		*content;
	size_t		content_size;
	struct s_llst	*next;
	int		fd;
}			gnl_lst;

int	get_next_line(int const fd, char **line);
int	gnl_build(int fd, char *buf, int ret, gnl_lst **head);
gnl_lst	*gnl_search(int fd, gnl_lst **head);
char	*gnl_trim(int fd, gnl_lst **head);

#endif
