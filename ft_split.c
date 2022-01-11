/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 14:41:24 by mmunoz-f          #+#    #+#             */
/*   Updated: 2022/01/11 14:34:24 by mmunoz-f         ###   ########.fr       */
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

static int	ft_add_word(char ***arr, char const *s, const char *set)
{
	size_t	len;
	char	**tmp;
	size_t	i;

	len = 0;
	while ((*arr)[len])
		len++;
	tmp = *arr;
	*arr = (char **)malloc(sizeof(char *) * (len + 2));
	if (!(*arr))
		return (0);
	i = 0;
	while (i < len)
	{
		(*arr)[i] = tmp[i];
		i++;
	}
	len = word_len(s, set);
	(*arr)[i] = ft_substr(s, 0, len);
	(*arr)[i + 1] = 0;
	free(tmp);
	return (len);
}

char	**ft_split(char const *src, const char *set)
{
	char	**arr;
	size_t	i;
	size_t	j;

	if (!src || !set)
		return (0);
	i = 0;
	arr = (char **)malloc(sizeof(char *));
	if (!arr)
		return (0);
	*arr = 0;
	while (src[i])
	{
		if (!(ft_strchr(set, src[i])))
		{
			j = ft_add_word(&arr, &src[i], set);
			if (!j)
				return (0);
			i += j;
		}
		else
			i++;
	}
	return (arr);
}
