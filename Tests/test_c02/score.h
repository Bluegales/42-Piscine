#include <stdio.h>
#include <unistd.h>

void potato_test_header(int n)
{
	n += '0';
	printf("                  POTATO TEST EX0");
	write(2,&n,1);
	printf("\n");
}

void write_score(int error, char* answer){
	if (!error){
		printf("OK!\n");
	} else {
		printf("\n=======ERROR======\n");
		printf("%s",answer);
		printf("\n");
	}
}

void write_cmp(int error, char* answer, char* correct){
	if (!error){
		printf("OK!\n");
	} else {
		printf("\n=======ERROR======\n");
		printf("You    : %s",answer);
		printf("\n");
		printf("Correct: %s",correct);
		printf("\n");
	}
}