/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 19:09:40 by pfuchs            #+#    #+#             */
/*   Updated: 2022/02/05 02:18:55 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_str_is_lowercase(char *str);

#include <stdio.h>
#include <string.h>
#include "../score.h"
#include "../strings.h"
#include "../../ex04/ft_str_is_lowercase.c"

char solution[30];
char to_test[30];

void test(char* string, int n) 
{
	write_score(ft_str_is_lowercase(string) != n, string);
}

int main()
{
	test(random, 0);
	test(alpha, 0);
	test(num, 0);
	test(up, 0);
	test(low, 1);
	test(empty, 1);
}