/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 20:29:23 by pfuchs            #+#    #+#             */
/*   Updated: 2022/02/22 02:14:47 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*array_copy;
	int	i;

	array_copy = malloc(sizeof(int) * length);
	if (array_copy == 0)
		return (0);
	i = 0;
	while (i < length)
	{
		array_copy[i] = f(tab[i]);
		i++;
	}
	return (array_copy);
}
