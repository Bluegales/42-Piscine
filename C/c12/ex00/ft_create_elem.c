/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 18:16:19 by pfuchs            #+#    #+#             */
/*   Updated: 2022/02/16 19:06:34 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

#include <stdlib.h>

t_list	*ft_create_elem(void *data)
{
	t_list	*my_list;

	my_list = malloc(sizeof(t_list));
	if (my_list == 0)
		return (0);
	my_list->data = data;
	my_list->next = 0;
	return (my_list);
}
