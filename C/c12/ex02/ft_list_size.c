/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 01:57:14 by pfuchs            #+#    #+#             */
/*   Updated: 2022/02/16 19:07:17 by pfuchs           ###   ########.fr       */
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
