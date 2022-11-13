#include <stdio.h>

int main(void)
{
	int temp;	// 임시 저장 공간
	int size = 5;

	for ( int i = 0; i < 5; i++ )	// i: [ 0 ~ 4 ]
	{
		arr[i] = i + 1;
	}	// 초기화

	for ( int i = 0; i < 5; i++ )	// i: [ 0 ~ 4 ]
	{
		printf("arr[%d]: %d\n", i, arr[i]);
	}	// 출력 

	// 뒤집기
	// e d c b a
	// 0 1 2 3 4
	// 
	// 0 1 2 3 4 5
	for ( int i = 0; i < size / 2; i++ )
	{
		temp = arr[i];				// 앞 부분 저장
		arr[i] = arr[size - 1 - i];	// 앞 부분에 뒷 부분 값 대입
		arr[size - 1 - i] = temp;	// 뒷 부분에 앞 부분 값 대입 ( temp )
	} // a b a

	// a b c
	// a b a
	// c b a
	// 
	// a b c d

	int a, b, c, d;
	int temp;	// 저장공간

	int square[3][3] = {
		{1, 2, 3},	// 3 2 1
		{4, 5, 6},
		{7, 8, 9}
	};

	for ( int y = 0; y < 3; y++ )	// 높이
	{
		for ( int x = 0; x < 3; x++ )	// 너비
		{
			printf("%d ", square[y][x]);	// [0][0] ~ [1][1]
		}	// 한 줄
		printf("\n");
	}	// 하나의 사각형

	// 이차원 배열 출력

	/*
	1 2
	3 4

	4 3
	2 1

	a b c d
	a d
	[0][0] [1][1]

	*/

	return 0;
}
/*
 1 2 3
 4 5 6
 7 8 9

 정사각형

 1. 90도
 1 4 7
 2 5 8
 3 6 9

 2. 위 아래
 7 8 9
 1 2 3
 4 5 6

 3. 오 왼
 3 1 2
 6 4 5
 9 7 8

 4. 뒤집기
 7 8 9
 4 5 6
 1 2 3

 5. 한칸씩 밀기 ( 22.01.03 )
 9 1 2
 3 4 5
 6 7 8

*/