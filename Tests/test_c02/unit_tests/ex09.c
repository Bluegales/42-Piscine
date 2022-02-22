/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex09.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 19:09:40 by pfuchs            #+#    #+#             */
/*   Updated: 2022/02/05 16:49:31 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *ft_strcapitalize(char *str);

#include <stdio.h>
#include <string.h>
#include "../score.h"
#include "../strings.h"
#include "../../ex09/ft_strcapitalize.c"

char solution[30];
char to_test[30];

int main()
{
	char ex_09_test[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
	char ex_09_solution[] = "Salut, Comment Tu Vas ? 42mots Quarante-Deux; Cinquante+Et+Un";
	char *test_return = ft_strcapitalize(ex_09_test);
	if (test_return != ex_09_test)
		printf("wrong return!!!!\n");
	write_cmp(strcmp(ex_09_test, ex_09_solution), ex_09_test, ex_09_solution);
}