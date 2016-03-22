/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 09:09:08 by nhuber            #+#    #+#             */
/*   Updated: 2016/02/27 17:43:24 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	n;

	n = ft_strlen(s) + 1;
	while (n--)
	{
		if ((*(s + n)) == (char)c)
			return ((char *)s + n);
	}
	return (NULL);
}
