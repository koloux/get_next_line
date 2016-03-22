/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 10:53:55 by nhuber            #+#    #+#             */
/*   Updated: 2016/03/04 11:24:29 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	while ((s1[i] || s2[i]) && n)
	{
		if ((unsigned char)s1[i] == (unsigned char)s2[i])
		{
			i++;
			n--;
		}
		else
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	return (0);
}
