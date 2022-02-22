/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 01:26:32 by pfuchs            #+#    #+#             */
/*   Updated: 2022/02/22 01:56:55 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	fill_digit(int nb, char *pointer)
{
	if (nb % 10 < 0)
	{
		*pointer = (nb % 10) * -1 + '0';
	}
	else
	{
		*pointer = (nb % 10) + '0';
	}
}

void	ft_putnbr(int nb)
{
	int		i;
	char	digits[10];

	if (nb == 0)
	{
		write(1, "0", 1);
		return ;
	}
	if (nb <= 0)
		write(1, "-", 1);
	i = 0;
	while (nb != 0)
	{
		fill_digit(nb, &(digits[i]));
		nb /= 10;
		i++;
	}
	while (i > 0)
	{
		i--;
		write(1, digits + i, 1);
	}
}
