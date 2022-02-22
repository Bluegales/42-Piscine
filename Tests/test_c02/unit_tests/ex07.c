/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex07.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 19:09:40 by pfuchs            #+#    #+#             */
/*   Updated: 2022/02/05 16:50:40 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *ft_strupcase(char *str);

#include <stdio.h>
#include <string.h>
#include "../score.h"
#include "../strings.h"
#include "../../ex07/ft_strupcase.c"

char solution[30];
char to_test[30];

int main()
{
	char *test_return = ft_strupcase(random);
	write_score(strcmp(random, ft_strupcase(random)), solution);
	if (test_return != random)
		printf("wrong return!!!!\n");

	write_score(strcmp(up, ft_strupcase(up)), solution);
	write_score(strcmp(empty, ft_strupcase(empty)), solution);
	write_score(strcmp(num, ft_strupcase(num)), solution);
	printf("before   : %s\n", alpha);
	printf("all upper: %s\n", ft_strupcase(alpha));
	printf("before   : %s\n", random);
	printf("all upper: %s\n", ft_strupcase(random));
	return 0;
}