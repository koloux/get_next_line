/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 11:22:04 by nhuber            #+#    #+#             */
/*   Updated: 2016/03/04 11:30:59 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *s1;
	unsigned char *s2;

	s1 = (unsigned char *)dst;
	s2 = (unsigned char *)src;
	if (s1 > s2)
	{
		s1 += len;
		s2 += len;
		while (len--)
			*--s1 = *--s2;
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
