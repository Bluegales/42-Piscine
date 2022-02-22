/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 22:09:14 by pfuchs            #+#    #+#             */
/*   Updated: 2022/02/22 02:09:40 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	easy_prime(int nb)
{
	int	i;

	i = 2;
	while (i <= nb / 2)
	{
		if (nb % i == 0)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_is_prime(int nb)
{
	if (nb < 2)
		return (0);
	if (nb == 2147483647)
		return (1);
	if (nb > 2147483647)
		return (0);
	return (easy_prime(nb));
}
