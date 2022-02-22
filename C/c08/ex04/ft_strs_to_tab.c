/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 21:24:15 by pfuchs            #+#    #+#             */
/*   Updated: 2022/02/13 20:09:50 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	str_length(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*strc_cpy(char *str)
{
	int		i;
	char	*output;

	i = 0;
	output = (char *)malloc(str_length(str) + 1);
	if (output == 0)
		return (0);
	while (str[i])
	{
		output[i] = str[i];
		i++;
	}
	output[i] = 0;
	return (output);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int					i;
	struct s_stock_str	*stock;

	stock = malloc(sizeof(struct s_stock_str) * (ac + 1));
	if (stock == 0)
		return (0);
	i = 0;
	while (i < ac)
	{
		stock[i].size = str_length(av[i]);
		stock[i].str = strc_cpy(av[i]);
		stock[i].copy = strc_cpy(av[i]);
		i++;
	}
	stock[i].str = 0;
	return (stock);
}
