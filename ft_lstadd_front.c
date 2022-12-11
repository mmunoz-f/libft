/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 16:30:21 by marvin            #+#    #+#             */
/*   Updated: 2022/12/11 14:21:42 by mmunoz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **alst, t_list *node)
{
	if (!*alst)
	{
		*alst = node;
		return ;
	}
	*alst = ft_lstfirst(*alst);
	(*alst)->previous = node;
	node->next = *alst;
	*alst = node;
}
