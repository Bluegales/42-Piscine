/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 00:10:07 by pfuchs            #+#    #+#             */
/*   Updated: 2022/02/22 02:15:00 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;

	if (length < 2)
		return (1);
	i = 0;
	while (i < length - 1 && f(tab[i], tab[i + 1]) <= 0)
	{
		i++;
	}
	if (i == length - 1)
		return (1);
	i = 0;
	while (i < length - 1 && f(tab[i], tab[i + 1]) >= 0)
	{
		i++;
	}
	if (i == length - 1)
		return (1);
	return (0);
}
