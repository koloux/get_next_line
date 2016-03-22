/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 09:49:18 by nhuber            #+#    #+#             */
/*   Updated: 2016/03/04 11:25:07 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	unsigned int	i;
	int				dif;

	if (!s1 || !s2)
		return (0);
	i = 0;
	while (s1[i] && s2[i] && i < n)
	{
		dif = s1[i] - s2[i];
		if (ft_isalpha(s1[i]) && ft_isalpha(s2[i])
				&& dif != 0)
			return (0);
		i++;
	}
	return (1);
}
