#include <stdio.h>

void set_arr(int[10]);

void print_arr(int[10]);

int main(void)
{
	int arr[10] = { 0, };

	set_arr(arr);

	print_arr(arr);

	return 0;
}

void set_arr(int arr[10])
{
	for ( int i = 0; i < 10; i++ )
	{
		arr[i] = i + 1;
	}
}

void print_arr(int arr[10])
{
	for ( int i = 0; i < 10; i++ )
	{
		printf("%d ", arr[i]);
	}
}

// array -> arr 배열
/*
 같은 자료형이 순차적으로 나열된 구조
 int arr[10];
 { int, int, int, int, ... , int }:
 개수: 10개
 인덱스 넘버: 0 ~ 9

 arr: 배열의 이름 ( 배열을 대표하는 이름 )
 값 -> 배열의 첫번째 원소의 주소

 배열의 원소 값     : { int, int, int, int, ... , int }
 배열 원소의 주소 값: { 0[ ~ 3], 4( ~ 7), 8( ~ 11), ..., 36( ~ 39) }
 배열 원소의 주소 값: { 0, 4, 8, ..., 36 }
 대표 주소인 0번만 있으면 마지막 원소까지 접근할 수 있다.
 -> 장점: 변수 명을 하나로 통일할 수 있다.

 특징:
 1. 순차적으로 나열되어있다. [ 인덱스 넘버 ]
 2. 각 원소의 특징이 사라진다.

 김 - 1번
 이 - 2번
 ...
 황 - 10번
 1번에서 10번까지 와라

 사용 예시:

 자료형
 1. 선언
 2. 초기화
 3. 연산

 선언: ( []는 배열을 의미하는 기호 )
 int array_name[number_of_array];

 초기화:
 1: 선언과 동시에 초기화
 int array_name[number_of_array] = { 0, };
 선언 당시에 초기 값을 넣어주면 초기 값을 제외한 부분은 모두 0으로 초기화된다.

 2: 반복문 활용
 for (int i = 0; i < number_of_array; i++)
 {
	array_name[i] = i + 1;
 }


 문자열: ( 수정 가능한 문자열, 수정 불가능한 문자열 )
 char형 배열

 char string[] = "Hello World!";
 char string[13] = { 'H', 'e', ... , '\0' };
*/