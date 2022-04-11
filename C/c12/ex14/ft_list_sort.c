/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 01:58:45 by pfuchs            #+#    #+#             */
/*   Updated: 2022/02/17 01:04:49 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_swap_data(t_list *t1, t_list *t2)
{
	void	*temp;

	temp = t1->data;
	t1->data = t2->data;
	t2->data = temp;
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
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
