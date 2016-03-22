/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 21:02:23 by nhuber            #+#    #+#             */
/*   Updated: 2016/03/04 11:30:12 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *)src;
	s2 = (unsigned char *)dst;
	i = 0;
	while (i < n)
	{
		if ((*s2++ = *s1++) == (unsigned char)c)
			return (s2);
		i++;
	}
	return (NULL);
}
