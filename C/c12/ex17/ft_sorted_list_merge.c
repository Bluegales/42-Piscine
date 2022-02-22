/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 01:59:04 by pfuchs            #+#    #+#             */
/*   Updated: 2022/02/17 01:40:04 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*last_element;

	if (!begin_list1)
		return ;
	if (!*begin_list1)
	{
		*begin_list1 = begin_list2;
		return ;
	}
	last_element = *begin_list1;
	while (last_element->next)
	{
		last_element = last_element->next;
	}
	last_element->next = begin_list2;
}

t_list	*ft_list_last(t_list *begin_list)
{
	t_list	*it;

	if (!begin_list)
		return (0);
	it = begin_list;
	while (it->next)
	{
		it = it->next;
	}
	return (it);
}

void	ft_swap_data(t_list *t1, t_list *t2)
{
	void	*temp;

	temp = t1->data;
	t1->data = t2->data;
	t2->data = temp;
}

void	ft_list_sort22(t_list **begin_list, int (*cmp)())
{
	t_list	*it;
	int		unsorted;

	if (!begin_list)
		return ;
	if (!*begin_list)
		return ;
	unsorted = 1;
	while (unsorted)
	{
		it = *begin_list;
		unsorted = 0;
		while (it->next)
		{
			if (cmp(it->data, it->next->data) > 0)
			{
				ft_swap_data(it, it->next);
				unsorted = 1;
			}
			it = it->next;
		}
	}
}

void	ft_sorted_list_merge(t_list **begin_list1,	t_list *begin_list2,
	int (*cmp)())
{
	ft_list_merge(begin_list1, begin_list2);
	ft_list_sort22(begin_list1, cmp);
}
