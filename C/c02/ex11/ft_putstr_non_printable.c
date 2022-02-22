/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 12:36:18 by pfuchs            #+#    #+#             */
/*   Updated: 2022/02/22 02:03:23 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	write_non_printable(char c)
{
	unsigned char	unsigned_c;
	char			output[3];

	unsigned_c = c;
	output[0] = '\\';
	if (c >= 32 && c != 127)
	{
		write(1, &c, 1);
	}
	else
	{
		output[1] = "0123456789abcdef"[unsigned_c / 16];
		output[2] = "0123456789abcdef"[unsigned_c % 16];
		write(1, output, 3);
	}
	return ;
}

void	ft_putstr_non_printable(char *str)
{
	while (*str)
	{
		write_non_printable(*str);
		str++;
	}
}
