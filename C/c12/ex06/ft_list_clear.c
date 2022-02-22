/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 01:57:39 by pfuchs            #+#    #+#             */
/*   Updated: 2022/02/16 19:13:07 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list	*it;
	t_list	*to_free;

	if (!begin_list)
		return ;
	it = begin_list;
	while (it)
	{
		if (it->data)
			free_fct(it->data);
		to_free = it;
		it = it->next;
		free(to_free);
	}
}
