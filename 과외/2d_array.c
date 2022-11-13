#include <stdio.h>

int main(void)
{
	int num = 97;
	int arr[2] = { 0, };
	int tdarr[2][2] = { { 1, 2 }, { 3, 4 } };

	printf("%d", tdarr[0][0]);

	// printf("%d %d\n", tdarr[0] [0], tdarr[0] [1]);
	// printf("%d %d\n", tdarr[1] [0], tdarr[1] [1]);

	// printf("%d %d %d", sizeof(tdarr), sizeof(tdarr[0]), sizeof(&tdarr[0][0]));

	return 0;
}

// arr[0], arr[1]
	// 메모리 공간에는 타입이 없다.
	// 메모리 공간은 타입에 따라서 변하지 않는다.
	// 값을 읽고 쓰는 방법에 차이일 뿐이다.
	// OS가 메모리를 관리하는데
	// OS는 단지 메모리 4칸을 준 거고
	// 우리가 타입에 따라서 읽고 쓰는 방법을 다르게 하는 것 뿐이다.


	// tdarr[0] == &tdarr[0][0];	// 값은 같으나 타입이 다른 경우를 주의

	// arr 1차원 배열						-> 변수이름	-> 특징이 들어간다.
	// &arr[0] 배열의 첫번째 원소의 주소값  -> 값		-> 값 그 자체

	// printf("%p %p\n", arr, &arr[0]);
	// printf("%d %d\n\n", sizeof(arr), sizeof(&arr[0]));

	// printf("%p %p %p\n", tdarr, tdarr[0], &tdarr[0][0]);
	// printf("%d %d %d", sizeof(tdarr), sizeof(tdarr[0]), sizeof(&tdarr[0][0]));

	// printf("\n%d", sizeof(&tdarr[0][0]));

	// printf("%d", sizeof(tdarr) / sizeof(int));
	// 1차원 배열은 [ int, int, int, int ] 첫 번째 공간의 주소를 담는다.
	// 2차원 배열은 [ int[2], int[2] ] 첫 번째 공간의 주소를 담는다.
/*
 a랑 b가 같다는 것은
 1. 데이터 값이 같다
 2. 데이터 자료형이 같다
 -> 이 두가지를 모두 만족해야 한다.
*/

/*
 진수 한 칸에 들어갈 수 있는 숫자의 개수에 따라서 나뉜다.

 2진수: 0 또는 1

 10진수: 0 ~ 9

 16진수: 0 ~ 9 A b c d e f
 -> 대부분 주소에 많이 사용

 int arr[3] = { 1, 2, 3 };	// 배열 상수형 포인터(주소 자료형)

	printf("%p\n%p\n%p\n%p", arr, &arr[0], &arr[1], &arr[2]);
*/
/*
 1차원
 2차원

 차원: dimension [ D ]
 ex) n차원 -> nd

 기하적인 의미
 
 1차원: 선
 2차원: 면
 3차원: 공간


*/