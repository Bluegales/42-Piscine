/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 01:57:53 by pfuchs            #+#    #+#             */
/*   Updated: 2022/02/16 19:11:06 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*previous;
	t_list	*current;
	t_list	*next;

	if (!*begin_list)
		return ;
	previous = 0;
	current = *begin_list;
	next = current->next;
	current->next = 0;
	while (next)
	{
		previous = current;
		current = next;
		next = next->next;
		current->next = previous;
	}
	*begin_list = current;
}
