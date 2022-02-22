/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 01:26:38 by pfuchs            #+#    #+#             */
/*   Updated: 2022/02/02 01:26:40 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	contains_char(char *array, char number, int max)
{
	int	i;

	i = 0;
	while (i != max)
	{
		if (array[i] >= number)
			return (1);
		i++;
	}
	return (0);
}

void	write_array(char *array, int max)
{
	int	i;

	i = 0;
	while (i <= max && array[i] == '0' + i)
	{
		i++;
	}
	if (i <= max)
		write(1, ", ", 2);
	write(1, array, max + 1);
}

void	resursive_combinations(char *array, int index, int max)
{
	int	i;

	i = index;
	while (i <= 9)
	{
		if (!contains_char(array, i + '0', index))
		{
			array[index] = i + '0';
			if (index != max)
				resursive_combinations(array, index + 1, max);
			if (index == max)
				write_array (array, max);
		}
		i++;
	}
}

void	ft_print_combn(int n)
{
	char	numbers[9];

	if (n < 1 || n > 9)
		return ;
	resursive_combinations(numbers, 0, n - 1);
}
