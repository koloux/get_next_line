/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 17:38:30 by nhuber            #+#    #+#             */
/*   Updated: 2016/03/04 11:27:36 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	if (*alst == NULL)
		*alst = ft_lstnew(NULL, 0);
	if (*alst && new)
	{
		new->next = *alst;
		*alst = new;
	}
}
