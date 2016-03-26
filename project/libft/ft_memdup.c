/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 21:31:04 by nhuber            #+#    #+#             */
/*   Updated: 2016/03/24 21:44:56 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memdup(const void *src, size_t n)
{
	void *dst;

	if (src == NULL || n == 0)
		return (NULL);
	if (!(dst = ft_memalloc(n)))
		return (NULL);
	else
		ft_memcpy(dst, src, n);
	return (dst);
}
