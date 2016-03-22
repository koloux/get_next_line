/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 12:50:10 by nhuber            #+#    #+#             */
/*   Updated: 2016/02/27 16:36:24 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	n;

	n = ft_strlen(src);
	while (len--)
	{
		if (len > n)
			dst[len] = '\0';
		else
			dst[len] = src[len];
	}
	return (dst);
}
