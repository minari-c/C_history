#include <stdio.h>

int main(void)
{
	int a = 10, b;

	char str[] = "apple";	// { 'a', 'p', 'p', 'l', 'e', '\0' }
	char rev_temp[6];
	
	'A';	// 65
	'B';	// 66

	'a';	// 97
	'b';	// 98

	// { 'a', 'p', 'p', 'l', 'e', '\0' }: i
	// { 'e', 'l', 'p', 'p', 'a', '\0' }: j
	// i == 0, j == 4 - 0
	// i == 1, j == 4 - 1
	// i == 2, j == 4 - 2

	// 실제로 값을 뒤집기

	// 출력만 뒤집어서 하기

	//str[0] = 'b';			// { 'b', 'p', 'p', 'l', 'e', '\0' }

	//str[5] = 'f';			// { 'b', 'p', 'p', 'l', 'e', 'f' }

	//printf("%s", str);

	// printf("%s", str);

	// str[3] = NULL;
	// str[3] = '\0';

	// printf("%s", str);

	// printf("%c", str[4]);

	// 문자열 == 단어?
	// app\0
	// null문자 \0

	return 0;
}

// c언어의 데이터
// 정수, 실수
