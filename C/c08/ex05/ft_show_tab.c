/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 10:39:33 by pfuchs            #+#    #+#             */
/*   Updated: 2022/02/13 00:05:43 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>

void	ft_putnbr(int nb)
{
	int	i;

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 10);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
	}
	i = nb % 10 + '0';
	write(1, &i, 1);
}

void	write_stock(struct s_stock_str *stock)
{
	char	*str;
	int		i;

	str = stock->str;
	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
	write(1, "\n", 1);
	ft_putnbr(stock->size);
	write(1, "\n", 1);
	str = stock->copy;
	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
	write(1, "\n", 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	if (par == 0)
		return ;
	while (par->str)
	{
		write_stock(par);
		par++;
	}
}
