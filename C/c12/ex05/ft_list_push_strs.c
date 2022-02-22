/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 01:57:32 by pfuchs            #+#    #+#             */
/*   Updated: 2022/02/17 01:08:57 by pfuchs           ###   ########.fr       */
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

t_list	*ft_list_push_strs(int size, char **strs)
{
	int		i;
	t_list	*it;

	i = 0;
	it = 0;
	if (size == 0)
		return (0);
	while (i < size)
	{
		ft_list_push_front(&it, strs[i]);
		i++;
	}
	return (it);
}
