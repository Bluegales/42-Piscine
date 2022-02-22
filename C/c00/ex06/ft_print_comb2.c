/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 01:26:24 by pfuchs            #+#    #+#             */
/*   Updated: 2022/02/02 01:26:26 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	write_2_numbers(int i, int j)
{
	char	numbers[5];

	numbers[0] = i / 10 + '0';
	numbers[1] = i % 10 + '0';
	numbers[2] = ' ';
	numbers[3] = j / 10 + '0';
	numbers[4] = j % 10 + '0';
	write (1, numbers, 5);
	if (i != 98 || j != 99)
	{
		write(1, ", ", 2);
	}
}

void	ft_print_comb2(void)
{
	int	i;
	int	j;

	i = 0;
	while (i <= 99)
	{
		j = i + 1;
		while (j <= 99)
		{
			write_2_numbers(i, j);
			j++;
		}
		i++;
	}	
}
