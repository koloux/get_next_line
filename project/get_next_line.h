/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 11:06:10 by nhuber            #+#    #+#             */
/*   Updated: 2016/03/20 23:24:05 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# define BUFF_SIZE 32

#include <stdio.h>

int	get_next_line(int const fd, char **line);
char	*gnl_found(int fd, char *buf, t_list **head);
char	*gnl_eof(int fd, char *buf, t_list **head);
t_list	*gnl_build(int fd, char *str, t_list **head);

#endif
