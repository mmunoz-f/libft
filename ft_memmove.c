/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 10:45:42 by marvin            #+#    #+#             */
/*   Updated: 2022/01/10 18:24:06 by mmunoz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*a;
	const char	*b;

	a = dest;
	b = src;
	if (!dest && !src)
		return (0);
	if (dest < src)
	{
		ft_memcpy(dest, src, n);
		return (dest);
	}
	i = 0;
	while (n--)
	{
		a[n] = b[n];
		i++;
	}
	return (a);
}
