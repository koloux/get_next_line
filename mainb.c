/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 12:45:51 by bchaleil          #+#    #+#             */
/*   Updated: 2016/03/29 15:22:23 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "project/get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

void	ft_readi(int fd)
{
	char	*line;
	int		r;

	while ((r = get_next_line(fd, &line)) > 0)
	{
		printf("r = %d line : |%s|\n", r, line);
		free(line);
	}
	printf("r = %d line : |%s|\n", r, line);
}

int		main(int ac, char **av)
{
	int fd;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		ft_readi(fd);
	}
	else
		ft_readi(0);
	return (0);
}
