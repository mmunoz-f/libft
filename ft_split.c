/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 14:41:24 by mmunoz-f          #+#    #+#             */
/*   Updated: 2021/03/10 21:45:39 by mmunoz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t	word_len(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static int	ft_add_word(char ***f, char const *s, char c)
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
	// printf("|%zu|", len);
	len = word_len(s, c);
	// printf("%zu%s\n", i, s);
	(*f)[i] = ft_substr(s, 0, len);
	// printf("'%s'", *f[0]);
	(*f)[i + 1] = 0;
	// exit(-1);
	free(tmp);
	return (len);
}

char		**ft_split(char const *s, char c)
{
	char	**f;
	size_t	i;
	size_t	j;

	if (!s)
		return (0);
	i = 0;
	f = (char **)malloc(sizeof(char *));
	if (!f)
		return (0);
	*f = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			j = ft_add_word(&f, &s[i], c);
			fflush(stdout);
			if (!j)
				return (0);
			i += j;
		}
		else
			i++;
	}
	return (f);
}
