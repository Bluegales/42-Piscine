/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 14:28:05 by pfuchs            #+#    #+#             */
/*   Updated: 2022/02/14 04:00:08 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"
#include "cat.h"

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc == 1)
	{
		in_out_loop();
		return (0);
	}
	while (i < argc)
	{
		if (argv[i][0] == '-' && argv[i][1] == 0)
			in_out_loop();
		if (cat(argv[i], argv[0]) != 0)
			return (1);
		i++;
	}
	return (0);
}
