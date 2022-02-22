/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 01:38:47 by pfuchs            #+#    #+#             */
/*   Updated: 2022/02/15 21:23:23 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math.h"

#include "output.h"
#include "ft_putnbr.h"

#include "stdio.h"

int	exception(int n1, char op)
{
	if (n1 == 0)
	{
		if (op == '/')
		{
			write_str("Stop : division by zero\n");
			return (1);
		}
		if (op == '%')
		{
			write_str("Stop : modulo by zero\n");
			return (1);
		}
	}
	return (0);
}

int	do_op(int n0, int n1, char op)
{
	int							i;
	const struct s_operation	operation[5] = {
	{'+', addition},
	{'-', substraction},
	{'*', multiplication},
	{'/', division},
	{'%', modulo}};

	if (exception(n1, op))
		return (1);
	i = 0;
	while (i < 5)
	{
		if (op == operation[i].op)
		{
			ft_putnbr(operation[i].func(n0, n1));
			write_str("\n");
			return (0);
		}
		i++;
	}
	return (2);
}
