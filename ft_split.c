/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 14:41:24 by mmunoz-f          #+#    #+#             */
/*   Updated: 2022/01/10 14:10:41 by mmunoz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t	word_len(char const *s, const char *set)
{
	size_t	i;

	i = 0;
	while (s[i] && !ft_strchr(set, s[i]))
		i++;
	return (i);
}

static int	ft_add_word(char ***f, char const *s, const char *set)
{
	size_t	len;
	char	**tmp;
	size_t	i;

	len = 0;
	while ((*f)[len])
		len++;
	tmp = *f;
	*f = (char **)malloc(sizeof(char *) * (len + 2));
	if (!(*f))
		return (0);
	i = 0;
	while (i < len)
	{
		(*f)[i] = tmp[i];
		i++;
	}
	len = word_len(s, set);
	(*f)[i] = ft_substr(s, 0, len);
	(*f)[i + 1] = 0;
	free(tmp);
	return (len);
}

char	**ft_split(char const *src, const char *set)
{
	char	**f;
	size_t	i;
	size_t	j;

	if (!src || !set)
		return (0);
	i = 0;
	f = (char **)malloc(sizeof(char *));
	if (!f)
		return (0);
	*f = 0;
	while (src[i])
	{
		if (!(ft_strchr(set, src[i])))
		{
			j = ft_add_word(&f, &src[i], set);
			if (!j)
				return (0);
			i += j;
		}
		else
			i++;
	}
	return (f);
}
