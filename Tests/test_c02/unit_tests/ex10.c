/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex10.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 19:09:40 by pfuchs            #+#    #+#             */
/*   Updated: 2022/02/05 12:35:47 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int ft_strlcpy(char *dest, char *src, unsigned int size);

#include <stdio.h>
#include <string.h>
#include "../score.h"
#include "../strings.h"
#include "../../ex10/ft_strlcpy.c"

size_t strlcpy(char *dst, const char *src, size_t siz)
{
	char *d = dst;
	const char *s = src;
	size_t n = siz;
	/* Copy as many bytes as will fit */
	if (n != 0) {
		while (--n != 0) {
			if ((*d++ = *s++) == '\0')
				break;
		}
  }
	/* Not enough room in dst, add NUL and traverse rest of src */
	if (n == 0) {
		if (siz != 0)
			*d = '\0';		/* NUL-terminate dst */
		while (*s++)
			;
	}
	return(s - src - 1);	/* count does not include NUL */
}

char solution[30];
char to_test[30];

int compareString(char* first, char* second)
{
	while(*first)
	{
		if (first != second)
		{
			return 0;
		}
		first++;
	}
	return 1;
}

void test(char* string, int n) 
{
	int a = ft_strlcpy(to_test, string, n);
	int b = strlcpy(solution, string, n);
	write_cmp(strcmp(solution, to_test), to_test, solution);
	if (a != b)
		printf("wrong return: %d, %d", a, b);
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