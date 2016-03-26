/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 17:00:19 by nhuber            #+#    #+#             */
/*   Updated: 2016/03/26 15:40:36 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];	
	int		ret;
	static gnl_lst	*head;
	char		*tmp;

	while (*line != NULL && (ret = read(fd, buf, BUFF_SIZE)) != 0)
	{
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
		if (gnl_build(fd, buf, ret, &head) == 1)
		{
			*line = gnl_trim(fd, &head);
			return (1);
		}
	}
	if ((tmp = gnl_trim(fd, &head)) != NULL)
		return (1);
	return (0);
}

char	*gnl_trim(int fd, gnl_lst **head)
{
	gnl_lst	*elem;
	char	*bgn;
	char	*end;
	size_t	lend;

	elem = gnl_search(fd, head);
	if (elem == NULL)
		return (NULL);
	end = ft_strstr(elem->content, "\n");
	lend = ft_strlen(++end) + 1;
	bgn = ft_memdup(elem->content, (elem->content_size - lend));
	elem->content = end;
	elem->content_size = ft_strlen(end);
	return (bgn);
}

gnl_lst	*gnl_search(int fd, gnl_lst **head)
{
	gnl_lst	*tmp;

	tmp = *head;
	while (tmp && tmp->fd != fd)
		tmp = tmp->next;
	return (tmp);
}

int	gnl_build(int fd, char *buf, int ret, gnl_lst **head)
{
	gnl_lst	*elem;
	char	*str;

	elem = gnl_search(fd, head);
	if (elem == NULL)
	{
		elem = (gnl_lst *)ft_lstnew(ft_memdup(buf, ret + 1), 
				ret + 1);
		elem->fd = fd;
		ft_lstaddback((t_list **)head, (t_list *)elem);
	}
	else
	{
		str = ft_strjoin(elem->content, buf);
		elem->content = str;
		elem->content_size = ft_strlen(str);
	}
	if (ft_strstr(elem->content, "\n") != NULL)
		return (1);
	return (0);
}
