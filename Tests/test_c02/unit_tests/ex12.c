/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex12.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 19:09:40 by pfuchs            #+#    #+#             */
/*   Updated: 2022/02/05 17:29:16 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void *ft_print_memory(void *addr, unsigned int size);

#include <stdio.h>
#include <string.h>
#include "../score.h"
#include "../strings.h"
#include "../../ex12/ft_print_memory.c"

char* data = "Bonjour les aminches...c est fo u.tout.ce qu on peut faire avec...print_memory....lol.lol. ";

int main()
{
	char* data_it = data;
	int i=0;
    while(*data_it){
        data_it++;
        i++;
    }
    void *test_return = ft_print_memory(data, i+1);
	if (test_return != data)
		printf("wrong return!!!!\n");
	printf("pointer: %p\n", test_return);
	printf("pointer: %p\n", data);

	i = 0;
	char test_ex_12[300];
	while( i < 256 )
	{
		test_ex_12[i] = i;
		i++;
	}
	ft_print_memory(test_ex_12, i);
    return 0;
}
