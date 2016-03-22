/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bitsetfour.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 11:00:32 by nhuber            #+#    #+#             */
/*   Updated: 2016/03/07 13:35:49 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bitsetfour(unsigned int *i, unsigned int val, unsigned int index)
{
	int	n;

	n = *i;
	n = (n & ~(15 << index * 4)) | (val << index * 4);
	*i = n;
}
