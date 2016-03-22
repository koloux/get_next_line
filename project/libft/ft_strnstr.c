/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 10:30:53 by nhuber            #+#    #+#             */
/*   Updated: 2016/03/07 13:40:49 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*little == '\0')
		return ((char *)big);
	while (big[i] != '\0' && i < n)
	{
		j = 0;
		while (little[j] == big[i + j] && little[j] && (i + j) <= n)
		{
			j++;
			if (j == ft_strlen(little))
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}
