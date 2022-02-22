/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 19:09:40 by pfuchs            #+#    #+#             */
/*   Updated: 2022/02/05 16:40:20 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *ft_strncpy(char *dest, char *src, unsigned int n);

#include <stdio.h>
#include <string.h>
#include "../score.h"
#include "../strings.h"
#include "../../ex01/ft_strncpy.c"

char solution[30];
char to_test[30];

void test(char* string, int n) 
{
	char *test_return = strncpy(solution, string, n);
	ft_strncpy(to_test, string, n);
	if (test_return != solution)
		printf("wrong return!!!!\n");
	write_cmp(strcmp(solution, to_test), to_test, solution);
}

void testn(char * string)
{
	test(string, 5);
	test(string, 10);
	test(string, 15);
	test(string, 20);
}

int main()
{
	testn(random);
	testn(alpha);
	testn(num);
	testn(up);
	testn(low);
	testn(empty);
}