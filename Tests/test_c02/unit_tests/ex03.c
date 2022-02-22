/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex03.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 19:09:40 by pfuchs            #+#    #+#             */
/*   Updated: 2022/02/05 02:17:56 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_str_is_numeric(char *str);

#include <stdio.h>
#include <string.h>
#include "../score.h"
#include "../strings.h"
#include "../../ex03/ft_str_is_numeric.c"

char solution[30];
char to_test[30];

void test(char* string, int n) 
{
	write_score(ft_str_is_numeric(string) != n, string);
}

int main()
{
	test(random, 0);
	test(alpha, 0);
	test(num, 1);
	test(up, 0);
	test(low, 0);
	test(empty, 1);
}