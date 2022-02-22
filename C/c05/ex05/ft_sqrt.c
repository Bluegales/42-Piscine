/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 21:35:17 by pfuchs            #+#    #+#             */
/*   Updated: 2022/02/22 02:09:11 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int		i;
	long	square;

	i = 0;
	while (i <= 46340)
	{
		square = i * i;
		if (square == nb)
			return (i);
		if (square >= nb)
			return (0);
		i++;
	}
	return (0);
}
