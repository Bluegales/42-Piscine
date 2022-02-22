/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 01:57:26 by pfuchs            #+#    #+#             */
/*   Updated: 2022/02/16 19:07:50 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*my_list;
	t_list	*it;

	my_list = ft_create_elem(data);
	if (*begin_list == 0)
	{
		*begin_list = my_list;
		return ;
	}
	it = *begin_list;
	while (it->next)
	{
		it = it->next;
	}
	it->next = my_list;
}
