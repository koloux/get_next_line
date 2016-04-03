/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 11:06:10 by nhuber            #+#    #+#             */
/*   Updated: 2016/03/31 18:03:15 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# define BUFF_SIZE 32

typedef struct		s_llst
{
	void			*content;
	size_t			content_size;
	struct s_llst	*next;
	int				fd;
}					t_gnl;

int					get_next_line(int const fd, char **line);
int					gnl_build(int fd, char *buf, t_gnl **head);
t_gnl				*gnl_search(int fd, t_gnl **head);
char				*gnl_trim(int fd, t_gnl **head);

#endif
