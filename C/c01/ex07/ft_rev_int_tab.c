/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 15:15:40 by pfuchs            #+#    #+#             */
/*   Updated: 2022/02/22 01:56:50 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	reverse_recursive(int *front, int *back)
{
	int	temp;

	temp = *front;
	*front = *back;
	*back = temp;
	if (front != back && front + 1 != back)
		reverse_recursive(++front, --back);
}

void	ft_rev_int_tab(int *tab, int size)
{
	if (size == 0)
		return ;
	reverse_recursive(tab, tab + size - 1);
}
