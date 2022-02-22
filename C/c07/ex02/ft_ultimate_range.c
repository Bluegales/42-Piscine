/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 01:07:39 by pfuchs            #+#    #+#             */
/*   Updated: 2022/02/22 02:11:17 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*new_array;
	int	size;
	int	i;

	if (min >= max)
		return (0);
	size = max - min;
	new_array = (int *)malloc(sizeof(int) * size);
	if (new_array == 0)
	{
		*range = 0;
		return (-1);
	}
	i = 0;
	while (min + i != max)
	{
		new_array[i] = min + i;
		i++;
	}
	*range = new_array;
	return (size);
}
