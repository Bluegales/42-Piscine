/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 01:00:45 by pfuchs            #+#    #+#             */
/*   Updated: 2022/02/15 21:23:45 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_atoi.h"
#include "do_op.h"
#include "output.h"

int	main(int argc, char **argv)
{
	int		nbr0;
	int		nbr1;
	char	op;

	if (argc != 4)
		return (0);
	nbr0 = ft_atoi(argv[1]);
	nbr1 = ft_atoi(argv[3]);
	if (argv[2][1] == 0)
	{
		op = argv[2][0];
		if (op == '+' || op == '-' || op == '*' || op == '/' || op == '%')
		{
			do_op(nbr0, nbr1, op);
			return (0);
		}
	}
	write_str("0\n");
	return (0);
}
