/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 17:00:19 by nhuber            #+#    #+#             */
/*   Updated: 2016/03/30 15:56:57 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];	
	int		ret;
	int		builder;
	static gnl_lst	*head;

	while ((ret = read(fd, buf, BUFF_SIZE)) != 0)
	{
		if (ret < 0 || fd < 0 || line == NULL)
			return (-1);
		buf[ret] = '\0';
		if ((builder = gnl_build(fd, buf, &head)) == 1)
		{
			*line = gnl_trim(fd, &head);
			return (1);
		}
		if (builder == -1)
			return (-1);
	}
	if ((*line = gnl_trim(fd, &head)) != NULL)
		return (1);
	return (0);
}

char	*gnl_trim(int fd, gnl_lst **head)
{
	gnl_lst	*elem;
	char	*bgn;
	char	*end;
	size_t	len;

	elem = gnl_search(fd, head);
	if (elem->content == NULL)
		return (NULL);
	if ((end = ft_strstr(elem->content, "\n")) != NULL)
	{
		if (!(end = ft_strdup(end)))
			return (NULL);
		len = elem->content_size - ft_strlen(end);
		if (!(bgn = ft_strsub(elem->content, 0, len - 1)))
			return (NULL);
		free((*elem).content);
		elem->content = (ft_strlen(++end) == 0) ? NULL : ft_strdup(end);
		elem->content_size = ft_strlen(end) + 1;
	}
	else
	{
		if (!(bgn = ft_strdup(elem->content)))
			return (NULL);
		free((*elem).content);
		elem->content = NULL;
		elem->content_size = 0;
	}
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

int	gnl_build(int fd, char *buf, gnl_lst **head)
{
	gnl_lst	*elem;
	char	*str;
	
	elem = gnl_search(fd, head); 
	if (elem == NULL)
	{
		if (!(elem = (gnl_lst *)ft_lstnew(buf, (ft_strlen(buf) + 1))))
			return (-1);
		elem->fd = fd;
		ft_lstaddback((t_list **)head, (t_list *)elem);
	}
	else
	{
		if (!(str = ft_strjoin(elem->content, buf)))
			return (-1);
		free((*elem).content);
		elem->content = str;
		elem->content_size = ft_strlen(str) + 1;
	}
	if (ft_strstr(elem->content, "\n") != NULL)
		return (1);
	return (0);
}
