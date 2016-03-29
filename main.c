/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 10:32:36 by nhuber            #+#    #+#             */
/*   Updated: 2016/03/29 15:06:30 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "project/get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(int ac, char **av)
{

	int	fd;
	int	fd2;
	int	fd3;
	char	*line;
	int	nb = 1;
	int	ret;

	(void)ac;
	line = malloc(sizeof(char) * 81);
	line[80] = '\0';
	fd = open(av[1], O_RDONLY);
	fd2 = open(av[2], O_RDONLY);
	fd3 = open(av[3], O_RDONLY);
	while (nb < 5)
	{
		ret = get_next_line(fd, &line);
		printf("FD :%d line %d:%s", fd, nb++, line);
		printf("\n-----------------%d------------------\n", ret);
		/*
		ret = get_next_line(fd2, &line);
		printf(" FD :%d line %d:%s", fd2, nb, line);
		printf("\n-----------------%d------------------\n", ret);
		ret = get_next_line(fd3, &line);
		printf(" FD :%d line %d:%s", fd3, nb++, line);
		printf("\n-----------------%d------------------\n", ret);
		*/
	}
	return (0);
}
