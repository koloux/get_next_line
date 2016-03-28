/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 10:32:36 by nhuber            #+#    #+#             */
/*   Updated: 2016/03/28 17:52:17 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "project/get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(int ac, char **av)
{

	int	fd;
	char	*line;
	int	nb = 1;
	int	ret;

	(void)ac;
	line = malloc(sizeof(char) * 81);
	line[80] = '\0';
	fd = open(av[1], O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0 && nb < 4)
	{
		printf(" FD :%d line %d:%s", fd, nb++, line);
		printf("\n-----------------%d------------------\n", ret);
	}
	return (0);
}
