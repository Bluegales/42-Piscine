/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 01:58:30 by pfuchs            #+#    #+#             */
/*   Updated: 2022/02/17 01:20:51 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	remove_if_long(t_list *it, void *data_ref,
	int (*cmp)(), void (*free_fct)(void *))
{
	t_list	*last_element;
	t_list	*to_free;

	last_element = it;
	it = it->next;
	while (it)
	{
		if (cmp(it->data, data_ref) == 0)
		{
			to_free = it;
			it = it->next;
			free_fct(to_free->data);
			free(to_free);
		}
		else
		{
			last_element->next = it;
			last_element = it;
			it = it->next;
		}
	}
}

void	ft_list_remove_if(t_list **begin_list, void *data_ref,
	int (*cmp)(), void (*free_fct)(void *))
{
	t_list	*it;
	t_list	*to_free;

	if (!begin_list)
		return ;
	if (!*begin_list)
		return ;
	it = *begin_list;
	while (it && cmp(it->data, data_ref) == 0)
	{
		to_free = it;
		it = it->next;
		free_fct(to_free->data);
		free(to_free);
	}
	*begin_list = it;
	remove_if_long(it, data_ref, cmp, free_fct);
}
