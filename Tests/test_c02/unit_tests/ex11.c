/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex11.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 19:09:40 by pfuchs            #+#    #+#             */
/*   Updated: 2022/02/05 16:52:14 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_putstr_non_printable(char *str);

#include <stdio.h>
#include <string.h>
#include "../score.h"
#include "../strings.h"
#include "../../ex11/ft_putstr_non_printable.c"

char solution[30];
char to_test[30];

int main()
{
	int i = 0;
	char test_ex_11[300];
	while( i < 256 )
	{
		test_ex_11[i] = i + 1;
		i++;
	}
	ft_putstr_non_printable(test_ex_11);
	printf("\n");
}
