/*
 C언어 (컴퓨터와 소통을 하기 위해서 => 컴퓨터한테 일을 시키기 위해서)
 1. 절차지향 (위에서 아래로, 왼쪽에서 오른쪽으로)
 2. 함수형 프로그래밍 (모듈형으로 기능이 분리됨)
	-함수: 하나의 기능을 가지는 모듈(단위)

 프로그램 이름:  move
 10 ~ 15 * 10 ~ 15칸의 크기를 가지는 정사각형 map에서 
 item을 이동시키는 것을 구현

 프로그램 함수 명세
 [1] void menu_display(void)
	- 단순 메뉴 출력

 [2] char input_direction(void)	(w == 위, a == 왼쪽, s == 아래,  d == 오른쪽)
	- 사용자로부터 방향을 받아 반환
		1) 방향을 받아
		2) 반환

 [3] void move_item(char)
	- 방향에 따라서 item의 위치를 업데이트

 [4] void display_result(void)
	- 맵을 출력한다.

 y = x
 ...
 [x == 1] -> [y == 1]
 -> x를 입력, y를 출력
 입력에 따라 출력이 정해지는 게 -> 함수
 입력에 반드시 출력이 존재하는  -> 함수


 반환형 함수이름(매개변수, ...)
 -> 입력은 여러개인데 출력은 하나
*/

/*
 (0, 2) (2, 1) (2, 2)
 (0, 1) (1, 1) (2, 1)
 (0, 0) (1, 0) (2, 0)

 10 by 10
*/
#include <stdio.h>

#define UP 'W'
#define LEFT 'A'
#define DOWN 'S'
#define RIGHT 'D'

int x = 2, y = 3;

void menu_display(void);	// 선언구

char input_direction(void);

void move_item(char);

void display_result(void);

int main(void)
{
	while (1)
	{
		display_result();

		menu_display();

		move_item(input_direction());

		display_result();
	}
}

void menu_display(void)		// 정의구
{
	printf("--------------------menu_display()--------------------\n");
	printf("다음의 영문자 중에 하나를 입력하여 item을 움직이세요:\n\n");
	printf("W: 위로 이동\n");
	printf("A: 오른쪽으로 이동\n");
	printf("S: 아래로 이동\n");
	printf("D: 왼쪽으로 이동\n");
}

char input_direction(void)	// (w == 위, a == 왼쪽, s == 아래,  d == 오른쪽)
{
	char dir;			// 임시 저장 공간
	printf("이동할 방향을 입력해주세요: ");
	scanf("%c", &dir);	// 사용자가 입력한 데이터를 담았다.

	return dir;
}

void move_item(char dir)
{
	int x_dif = 0, y_dif = 0;

	switch (dir)
	{
	case UP:	// 위
		y_dif = +1;
		break;
	case LEFT:	// 왼쪽
		x_dif = -1;
		break;
	case DOWN:	// 아래
		y_dif = -1;
		break;
	case RIGHT:	// 오른쪽
		x_dif = +1;
		break;
	}

	x += x_dif;
	y += y_dif;
}

void display_result(void)
{
	for (int i = 0; i < 12; i++) printf("*");
	printf("\n");
	
	for (int col = 9; col >= 0; col--)	// 줄 하나씩
	{
		printf("*");
		for (int row = 1; row < 11; row++)
		{
			if (x != row || y != col) // x == row && y == col -> x != row || y != col 
				printf(" ");
			else
				printf("#");
		}
		printf("*\n");
	}

	for (int i = 0; i < 12; i++) printf("*");
	printf("\n");

	printf("x_position: %d, y_position: %d\n", x, y);
}
