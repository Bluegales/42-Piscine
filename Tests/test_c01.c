/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   potato_test_c01.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 13:09:40 by pfuchs            #+#    #+#             */
/*   Updated: 2022/02/04 10:37:15 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/select.h>
#include <poll.h>

#if __has_include ("ex00/ft_ft.c")
#	include "ex00/ft_ft.c"
#	define ex00 1
#else
#	define ex00 0
void ft_ft(int *nbr){}
#endif

#if __has_include ("ex01/ft_ultimate_ft.c")
#	include "ex01/ft_ultimate_ft.c"
#	define ex01 1
#else
#	define ex01 0
void ft_ultimate_ft(int *********nbr){}
#endif

#if __has_include ("ex02/ft_swap.c")
#	include "ex02/ft_swap.c"
#	define ex02 1
#else
#	define ex02 0
void ft_swap(int *a, int *b){}
#endif

#if __has_include ("ex03/ft_div_mod.c")
#	include "ex03/ft_div_mod.c"
#	define ex03 1
#else
#	define ex03 0
void ft_div_mod(void){}
#endif

#if __has_include ("ex04/ft_ultimate_div_mod.c")
#	include "ex04/ft_ultimate_div_mod.c"
#	define ex04 1
#else
#	define ex04 0
void ft_ultimate_div_mod(int *a, int *b){}
#endif

#if __has_include ("ex05/ft_putstr.c")
#	include "ex05/ft_putstr.c"
#	define ex05 1
#else
#	define ex05 0
void ft_putstr(char *str){}
#endif

#if __has_include ("ex06/ft_strlen.c")
#	include "ex06/ft_strlen.c"
#	define ex06 1
#else
#	define ex06 0
int ft_strlen(char *str){}
#endif

#if __has_include ("ex07/ft_rev_int_tab.c")
#	include "ex07/ft_rev_int_tab.c"
#	define ex07 1
#else
#	define ex07 0
void ft_rev_int_tab(int *tab, int size){}
#endif

#if __has_include ("ex08/ft_sort_int_tab.c")
#	include "ex08/ft_sort_int_tab.c"
#	define ex08 1
#else
#	define ex08 0
void ft_sort_int_tab(int *tab, int size){}
#endif

void write_string(char* string){
	while(*string)
	{
		write(1,string++,1);
	}
}

void norminette_tests()
{
	write_string("==================================================\n");
	write_string("                    NORM TESTS");
	write_string("\n==================================================\n");
	system("norminette */*");
}

void potato_test_header(int n)
{
	n += '0';
	write_string("                  POTATO TEST EX0");
	write(2,&n,1);
	write_string("\n");
}

int stdout_bk = 0;
int stolen[2];

void steal_std(){
   pipe(stolen);
   dup2(stolen[1], fileno(stdout));
}

void restore_std(){
	if (!stdout_bk)
		return;
		
	dup2(stdout_bk, fileno(stdout));
}

int test_answer(char* answer){

	int length = strlen(answer);
	char buf[length+10];

	int retval = fcntl( stolen[0], F_SETFL, fcntl(stolen[0], F_GETFL) | O_NONBLOCK);   	
	
   	int size = read(stolen[0], buf, length+1); 
	   
	if (size == -1 && length == 0)
		return 1;	

	if (size != length)
		return 0;
	   	   
	buf[length] = 0;
	answer[length] = 0;
	
	if(strcmp(buf, answer)){
		return 0; // 0 = ERROR
	} else {
		return 1; // 1 = OK
	}
}

void write_score(int correct){
	if (correct){
		write_string("OK!\n");
	} else {
		write_string("\n=======ERROR======\n");
	}
}

int main(){	
	stdout_bk = dup(fileno(stdout));
	norminette_tests();
	write_string("==================================================\n");
	write_string("                    POTATO TESTS");
	write_string("\n==================================================\n");
	
	if (ex00){
		potato_test_header(0);
		int test = 2;
		ft_ft(&test);
		write_score(test == 42);
	} else {
		write_string("no ex00\n");
	}

	if (ex01){
		potato_test_header(1);
		int test0 = 2;
		int* test1 = &test0;
		int** test2 = &test1;
		int*** test3 = &test2;
		int**** test4 = &test3;
		int***** test5 = &test4;
		int****** test6 = &test5;
		int******* test7 = &test6;
		int******** test8 = &test7;
		int********* test9 = &test8;
		ft_ultimate_ft(test9);
		write_score(test0 == 42);
	} else {
		write_string("no ex01\n");
	}

	if (ex02){
		potato_test_header(2);
		int test = 2;
		int test1 = 5;
		ft_swap(&test, &test1);
		write_score(test == 5 && test1 == 2);
	} else {
		write_string("no ex02\n");
	}

	if (ex03){
		potato_test_header(3);
		int test = 10;
		int test1 = 3;
		int test2;
		int test3;
		ft_div_mod(test, test1, &test2, &test3);
		write_score(test2 == (test / test1) && test3 == (test % test1));
		test = 20;
		test1 = -3;
		ft_div_mod(test, test1, &test2, &test3);
		write_score(test2 == (test / test1) && test3 == (test % test1));
		test = -20;
		test1 = 3;
		ft_div_mod(test, test1, &test2, &test3);
		write_score(test2 == (test / test1) && test3 == (test % test1));
		test = -20;
		test1 = -3;
		ft_div_mod(test, test1, &test2, &test3);
		write_score(test2 == (test / test1) && test3 == (test % test1));
	} else {
		write_string("no ex03\n");
	}

	if (ex04){
		potato_test_header(4);
		int old_test_0 = 10;
		int test0 = 10;
		int old_test_1 = 3;
		int test1 = 3;
		ft_ultimate_div_mod(&test0, &test1);
		write_score(old_test_0/old_test_1 == test0 && old_test_0%old_test_1 == test1);
		old_test_0 = -10;
		test0 = -10;
		old_test_1 = 3;
		test1 = 3;
		ft_ultimate_div_mod(&test0, &test1);
		write_score(old_test_0/old_test_1 == test0 && old_test_0%old_test_1 == test1);
		old_test_0 = 10;
		test0 = 10;
		old_test_1 = -3;
		test1 = -3;
		ft_ultimate_div_mod(&test0, &test1);
		write_score(old_test_0/old_test_1 == test0 && old_test_0%old_test_1 == test1);
		old_test_0 = -10;
		test0 = -10;
		old_test_1 = -3;
		test1 = -3;
		ft_ultimate_div_mod(&test0, &test1);
		write_score(old_test_0/old_test_1 == test0 && old_test_0%old_test_1 == test1);
	} else {
		write_string("no ex04\n");
	}

	if (ex05){
		potato_test_header(5);
		{
			char answer[] = "POTATO!!!";
			steal_std();
			ft_putstr(answer);
			int correct = test_answer(answer);
			restore_std();
			write_score(correct);	
		}
		{
			char answer[] = "";
			steal_std();
			ft_putstr(answer);
			int correct = test_answer(answer);
			restore_std();
			write_score(correct);	
		}
	} else {
		write_string("no ex05\n");
	}

	if (ex06){
		potato_test_header(6);
		char test[] = "POTATO!!!";
		write_score(ft_strlen(test) == 9);
		char test2[] = "";
		write_score(ft_strlen(test2) == 0);
	} else {
		write_string("no ex06\n");
	}

	if (ex07){
		potato_test_header(7);
		int a0[] = {1,2,3,4,5,6};
		ft_rev_int_tab(a0, 6);
		int a1 = 42;
		ft_rev_int_tab(&a1, 0);
		int a2[] = {1,2,3,4,5,6,7};
		ft_rev_int_tab(a2, 7);
		if (a0[0] == 6 && a0[1] == 5 && a0[2] == 4 && a0[3] == 3 && a0[4] == 2 && a0[5] == 1)
			write_score(1);
		if (a2[0] == 7 && a2[1] == 6 && a2[2] == 5 && a2[3] == 4 && a2[4] == 3 && a2[5] == 2 && a2[6] == 1)
			write_score(1);
		if (a1 == 42)
			write_score(1);
	} else {
		write_string("no ex07\n");
	}
	
	if (ex08){
		potato_test_header(8);
		int a0[] = {6,2,0,-1,2,-1};
		ft_sort_int_tab(a0, 6);
		int a1 = 42;
		ft_sort_int_tab(&a1, 0);
		if (a0[0] == -1 && a0[1] == -1 && a0[2] == 0 && a0[3] == 2 && a0[4] == 2 && a0[5] == 6)
			write_score(1);
		if (a1 == 42)
			write_score(1);
	} else {
		write_string("no ex08\n");
	}
}