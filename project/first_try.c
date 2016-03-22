/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 11:05:15 by nhuber            #+#    #+#             */
/*   Updated: 2016/03/20 17:00:00 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int const fd, char **line)
{
	int		ret;
	char		buf[BUFF_SIZE + 1];
	char		*end;
	char		*new;
	static t_list	*head;
	t_list		*elem;

	//verify if there s not already an elem with a char * containing a \n
	while (fd >= 0 && (ret = read(fd , buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		printf("buf :%s\n", buf);
		if ((end = ft_strstr(buf, "\n")) != NULL)
		{
			end++;
			if (!(new = ft_memalloc(BUFF_SIZE + 1)))
				return (-1);
			new = ft_strncpy(new, buf, (ft_strlen(buf) - ft_strlen(end)));
			if ((elem = gnl_build(fd, new, &head)) != NULL)
			{
				printf("elem->content :%s\n", elem->content);
				new = ft_strstr(elem->content, "-");
				*line = ++new;
				end = ft_strstr(new, "\n");
				elem->content = ft_strjoin(ft_itoa(fd), end);
			}
			else
				*line = new;
			return (1);
		}
		else if (ret < BUFF_SIZE)
		{
			if ((elem = gnl_build(fd, buf, &head)) != NULL)
			{
				*line = elem->content;
			}
			else
				*line = ft_strdup(buf);
			return (0);
		}
		else
			gnl_build(fd, buf, &head);
	}
	return (-1);
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
