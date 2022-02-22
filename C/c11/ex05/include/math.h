/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 01:47:52 by pfuchs            #+#    #+#             */
/*   Updated: 2022/02/15 21:25:49 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_H
# define MATH_H

typedef int	(*t_math)(int, int);

struct	s_operation{
	char	op;
	t_math	func;
};

int	addition(int a, int b);
int	substraction(int a, int b);
int	multiplication(int a, int b);
int	division(int a, int b);
int	modulo(int a, int b);

#endif