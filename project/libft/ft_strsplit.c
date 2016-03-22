/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 17:27:10 by nhuber            #+#    #+#             */
/*   Updated: 2016/03/04 11:26:05 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	countstr(char const *s, char c)
{
	size_t		count;
	size_t		word;

	count = 0;
	word = 0;
	while (*s)
	{
		if (word == 1 && *s == c)
			word = 0;
		if (word == 0 && *s != c)
		{
			word = 1;
			count++;
		}
		s++;
	}
	return (count);
}

static size_t	wordlen(char const *s, char c)
{
	size_t		count;

	count = 0;
	while (*s != c && *s)
	{
		count++;
		s++;
	}
	return (count);
}

char			**ft_strsplit(char const *s, char c)
{
	char			**str;
	size_t			n;
	unsigned int	i;

	n = countstr(s, c);
	if (!(str = (char **)malloc(sizeof(char *) * (n + 1))))
		return (NULL);
	i = 0;
	while (n--)
	{
		while (*s == c && *s)
			s++;
		str[i] = ft_strsub(s, 0, wordlen(s, c));
		if (!str[i])
			return (NULL);
		s += wordlen(s, c);
		i++;
	}
	str[i] = NULL;
	return (str);
}
