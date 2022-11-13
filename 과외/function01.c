#include <stdio.h>

void add(int a, int b)	// return이 void인 경우는 출력을 내부에서 해줄 때
{
	printf("%d", a + b);
}

int add(int a, int b)	// 대게는 return에 따라서 함수의 기능과 이름이 정해진다.
{
	return a + b;
}

int add(void)
{
	int a, b;
	scanf("%d %d", &a, &b);

	return a + b;
}

void add(void);

void print_int(int )

int main(void)
{
	for (int i = 2; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{

		}
	}
}

void add(void)
{
	int a, b;
	scanf("%d %d", &a, &b);

	printf("%d", a + b);
}

void print_dan(int dan)		// return -> 해당하는 단의 출력
{
	// dan * i = ..
}

void print_gugudan(void)	// 1 ~ 9단
{
	for (int i = 1; i <= 9; i++)
	{
		print_dan(i);
	}
}

// print_gugudan { print_dan() * 9번 }
/*
 동전 교환기:

 입력은 동전을 교환할 금액(정수)
 출력은 동전의 개수(정수)

 ex) 4500원 -> 7

 메인함수:
 4500원은 500원 7개로 바꿀 수 있습니다. (출력 내용)
*/


/*
 print_gugudan:
	print_dan(1):
		1 * i = ..
	print_dan(2):
		2 * i = ..
	print_dan(3):
		3 * i = ..
	...
	print_dan(9):
		9 * i = ..


*/

/*
 함수: 하나의 기능 단위

 프로젝트가 커지면, 프로그램이 커지면

 ex)
 int: 정수 ( 음수, 0, 양수 )
 허수를 실제로 구현해야할 때
 -> 내가 현실에 있는 걸 컴퓨터 위에서 구현하기 위해서 
 -> 복잡한 관계를 가지는 프로그램을 만들어야 함.

 1. 유지보수의 용이성	( 모듈 단위의 테스트 혹은 교체가 가능 )
 2. 구조화의 용이성     ( 내가 어떤 프로그램을 체계적으로 구성할 수 있음 )
 3. 직관성의 증가       ( 현실과 유사한 구조를 가지게끔 구현할 수 있다. )


 void: 임의로 정해진 타입
 -> 비어있다



 int, float 현실에 있는 타입

 함수의 매개변수가 단인 함수
 해당 단의 구구단을 3 by 3으로 출력한다.
 print_dan
 
*/
