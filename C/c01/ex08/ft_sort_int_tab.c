/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 18:45:53 by pfuchs            #+#    #+#             */
/*   Updated: 2022/02/04 18:20:51 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	bubblesort(int *start, int *end)
{
	int	*runner;
	int	no_change;

	if (start == end)
		return ;
	runner = start;
	no_change = 1;
	while (1)
	{
		if (*runner > *(runner + 1))
		{
			no_change = 0;
			swap(runner, runner + 1);
		}
		runner++;
		if (runner == end - 1)
		{
			if (no_change)
				return ;
			runner = start;
			no_change = 1;
		}
	}
}

void	ft_sort_int_tab(int *tab, int size)
{
	bubblesort(tab, tab + size);
}
