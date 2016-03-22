/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 17:00:19 by nhuber            #+#    #+#             */
/*   Updated: 2016/03/21 12:03:56 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];	
	int		ret;
	static t_list	*head;

	while (*line != NULL && fd >= 0 && (ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		if (ft_strstr(buf, "\n") != NULL)
		{
			*line = gnl_found(fd, buf, &head);
			return (1);
		}
		else if (ret < BUFF_SIZE)
		{
			*line = gnl_eof(fd, buf, &head);
			return (0);
		}
		else
			gnl_build(fd, buf, &head);
	}
	return (-1);
}

char	*gnl_found(int fd, char *buf, t_list **head)
{
	char	*end;
	char	*begin;
	char	*str;
	t_list	*elem;

	if (!(begin = ft_strnew(BUFF_SIZE)))
		return (NULL);
	end = ft_strstr(buf, "\n");
	begin = ft_strncpy(begin, buf, (ft_strlen(buf) - ft_strlen(end)));
	if ((elem = gnl_build(fd, begin, head)) != NULL)
	{
		str = ft_strstr(elem->content, "-");
		begin = ft_strdup(str);
		++begin;
		ft_bzero(elem->content, elem->content_size);
		gnl_build(fd, ++end, head);
	}
	return (begin);
}

char	*gnl_eof(int fd, char *buf, t_list **head)
{
	t_list	*elem;
	char	*ret;

	if ((elem = gnl_build(fd, buf, head)) != NULL)
	{
		ret = ft_strstr(elem->content, "-");
		++ret;
		return (ret);
	}
	else
		return (ft_strdup(buf));
}

t_list	*gnl_build(int fd, char *str, t_list **head)
{
	char	*s1;
	char	*s2;
	size_t	len;
	t_list	*elem;

	s1 = ft_itoa(fd);
	len = ft_strlen(s1);
	elem = *head;
	while (elem && ft_strncmp(elem->content, s1, len))
		elem = elem->next;
	if (elem == NULL)
	{
		if (!(s2 = (char *)ft_memalloc(len + ft_strlen(str) + 2)))
		{
			free(s1);
			return (NULL);
		}
		s2 = ft_strcat(s1, "-");
		s2 = ft_strcat(s2, str);
		ft_lstaddback(head, ft_lstnew(s2, ft_strlen(s2)));
		return (NULL);
	}
	else
	{
		s2 = ft_strjoin(elem->content, str);
		elem->content = s2;
		elem->content_size = ft_strlen(s2);
	}
	free(s1);
	return (elem);
}
