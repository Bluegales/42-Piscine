/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 01:26:17 by pfuchs            #+#    #+#             */
/*   Updated: 2022/02/02 01:26:20 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	write_3_digits(int i, int j, int k)
{
	char	numbers[4];

	numbers[0] = i + '0';
	numbers[1] = j + '0';
	numbers[2] = k + '0';
	numbers[3] = '\n';
	write(1, numbers, 3);
	if (i != 7 || j != 8 || k != 9)
	{
		write(1, ", ", 2);
	}
}

void	ft_print_comb(void)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	while (i < 10)
	{
		j = i + 1;
		while (j < 10)
		{
			k = j + 1;
			while (k < 10)
			{
				write_3_digits(i, j, k);
				k++;
			}
			j++;
		}
		i++;
	}
}
