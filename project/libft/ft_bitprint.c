/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bitprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/05 17:22:15 by nhuber            #+#    #+#             */
/*   Updated: 2016/03/07 13:35:38 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bitprint(unsigned int nb)
{
	int	i;
	int	sp;

	sp = 1;
	i = 8 * sizeof(nb) - 1;
	while (i >= 0)
	{
		(nb & (1 << i)) ? ft_putchar('1') : ft_putchar('0');
		i--;
		if (sp % 4 == 0)
			ft_putchar(' ');
		sp++;	
	}
	ft_putchar('\n');
}
