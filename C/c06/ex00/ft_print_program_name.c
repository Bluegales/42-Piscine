/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 12:14:56 by pfuchs            #+#    #+#             */
/*   Updated: 2022/02/09 17:11:13 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	length;

	length = 0;
	while (argv[0][length] && argc)
	{
		length++;
	}
	write(1, argv[0], length);
	write(1, "\n", 1);
}
