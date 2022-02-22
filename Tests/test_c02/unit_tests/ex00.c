/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex00.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 19:09:40 by pfuchs            #+#    #+#             */
/*   Updated: 2022/02/05 16:36:33 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *ft_strcpy(char *dest, char *src);

#include <stdio.h>
#include <string.h>
#include "../score.h"
#include "../strings.h"
#include "../../ex00/ft_strcpy.c"

char solution[30];
char to_test[30];

void test(char* string) 
{
	char *test_return = ft_strcpy(to_test, string);
	strcpy(solution, string);
	if (test_return != to_test)
	{
		printf("wrong return!!!!\n");
		fflush(stdout);
	}	
	write_score(strcmp(solution, to_test), solution);
	write_score(strcmp(solution, to_test), to_test);
}

int main()
{
	test(random);
	test(alpha);
	test(num);
	test(up);
	test(low);
	test(empty);
}