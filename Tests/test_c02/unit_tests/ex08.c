/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex08.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 19:09:40 by pfuchs            #+#    #+#             */
/*   Updated: 2022/02/05 16:49:57 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *ft_strlowcase(char *str);

#include <stdio.h>
#include <string.h>
#include "../score.h"
#include "../strings.h"
#include "../../ex08/ft_strlowcase.c"

char solution[30];
char to_test[30];

int main()
{
	char *test_return = ft_strlowcase(random);
	write_score(strcmp(random, ft_strlowcase(random)), solution);

	if (test_return != random)
		printf("wrong return!!!!\n");

	write_score(strcmp(up, ft_strlowcase(up)), solution);
	write_score(strcmp(empty, ft_strlowcase(empty)), solution);
	write_score(strcmp(num, ft_strlowcase(num)), solution);
	printf("before   : %s\n", alpha);
	printf("all lower: %s\n", ft_strlowcase(alpha));
	printf("before   : %s\n", random);
	printf("all lower: %s\n", ft_strlowcase(random));
	return 0;
}