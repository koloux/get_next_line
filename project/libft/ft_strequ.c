/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 22:05:55 by nhuber            #+#    #+#             */
/*   Updated: 2016/03/04 11:22:45 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	unsigned int	i;
	int				dif;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[i] && s2[i])
	{
		dif = s1[i] - s2[i];
		if (ft_isalpha(s1[i]) && ft_isalpha(s2[i])
				&& dif != 0)
			return (0);
		i++;
	}
	return (1);
}
