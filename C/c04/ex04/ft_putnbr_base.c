/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 04:21:23 by pfuchs            #+#    #+#             */
/*   Updated: 2022/02/22 02:07:50 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// checks for valid base, returns 0 when not valid
int	valid_base(char *base, int *length)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] < 32)
			return (0);
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = 0;
		while (base[j])
		{
			if (base[j] == base[i] && i != j)
				return (0);
			j++;
		}
		i++;
	}
	if (i <= 1)
		return (0);
	*length = i;
	return (1);
}

void	recursive_base(long number, int base_size, char *characters)
{
	if (number)
	{
		recursive_base(number / base_size, base_size, characters);
		write(1, characters + (number % base_size), 1);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		base_size;
	long	safe_nbr;

	safe_nbr = nbr;
	if (!valid_base(base, &base_size))
		return ;
	if (safe_nbr == 0)
		write(1, base, 1);
	if (safe_nbr < 0)
	{
		write(1, "-", 1);
		safe_nbr *= -1;
	}
	recursive_base(safe_nbr, base_size, base);
}
