/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 01:58:58 by pfuchs            #+#    #+#             */
/*   Updated: 2022/02/17 01:41:45 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*my_list;

	my_list = ft_create_elem(data);
	if (*begin_list)
		my_list->next = *begin_list;
	*begin_list = my_list;
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

void	ft_list_sort_33(t_list **begin_list, int (*cmp)())
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

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	ft_list_push_front(begin_list, data);
	ft_list_sort_33(begin_list, cmp);
}
