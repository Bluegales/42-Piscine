/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 01:58:52 by pfuchs            #+#    #+#             */
/*   Updated: 2022/02/16 20:19:18 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	t_list	*it;
	int		count;

	if (!begin_list)
		return (0);
	count = 1;
	it = begin_list;
	while (it->next)
	{
		it = it->next;
		count++;
	}
	return (count);
}

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int	i;

	i = 0;
	if (!begin_list)
		return (0);
	if (nbr == 0)
		return (begin_list);
	while (begin_list->next)
	{
		begin_list = begin_list->next;
		i++;
		if (i == nbr)
			return (begin_list);
	}
	return (0);
}

void	ft_list_swap(t_list *begin_list, int n0, int n1)
{
	t_list	*t0;
	t_list	*t1;
	void	*temp;

	t0 = ft_list_at(begin_list, n0);
	t1 = ft_list_at(begin_list, n1);
	temp = t0->data;
	t0->data = t1->data;
	t1->data = temp;
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	int		front;
	int		last;

	if (begin_list)
		return ;
	front = 0;
	last = ft_list_size(begin_list) - 1;
	while (front < last)
	{
		ft_list_swap(begin_list, front, last);
		front++;
		last--;
	}
}
