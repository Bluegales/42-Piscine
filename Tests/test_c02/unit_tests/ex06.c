/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex06.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 19:09:40 by pfuchs            #+#    #+#             */
/*   Updated: 2022/02/05 02:30:07 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_str_is_printable(char *str);

#include <stdio.h>
#include <string.h>
#include "../score.h"
#include "../strings.h"
#include "../../ex06/ft_str_is_printable.c"

char solution[30];
char to_test[30];

void test(char* string, int n) 
{
	write_score(ft_str_is_printable(string) != n, string);
}

int main()
{
	test(random, 1);
	test(alpha, 1);
	test(num, 1);
	test(up, 1);
	test(low, 1);
	test(empty, 1);
	char non_print[] = {1, 'a', 'b'};
	char non_print2[] = {'a', 'a', 1};
	test(non_print, 0);
	test(non_print2, 0);
}