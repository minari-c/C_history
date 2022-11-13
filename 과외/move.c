/*
 C��� (��ǻ�Ϳ� ������ �ϱ� ���ؼ� => ��ǻ������ ���� ��Ű�� ���ؼ�)
 1. �������� (������ �Ʒ���, ���ʿ��� ����������)
 2. �Լ��� ���α׷��� (��������� ����� �и���)
	-�Լ�: �ϳ��� ����� ������ ���(����)

 ���α׷� �̸�:  move
 10 ~ 15 * 10 ~ 15ĭ�� ũ�⸦ ������ ���簢�� map���� 
 item�� �̵���Ű�� ���� ����

 ���α׷� �Լ� ��
 [1] void menu_display(void)
	- �ܼ� �޴� ���

 [2] char input_direction(void)	(w == ��, a == ����, s == �Ʒ�,  d == ������)
	- ����ڷκ��� ������ �޾� ��ȯ
		1) ������ �޾�
		2) ��ȯ

 [3] void move_item(char)
	- ���⿡ ���� item�� ��ġ�� ������Ʈ

 [4] void display_result(void)
	- ���� ����Ѵ�.

 y = x
 ...
 [x == 1] -> [y == 1]
 -> x�� �Է�, y�� ���
 �Է¿� ���� ����� �������� �� -> �Լ�
 �Է¿� �ݵ�� ����� �����ϴ�  -> �Լ�


 ��ȯ�� �Լ��̸�(�Ű�����, ...)
 -> �Է��� �������ε� ����� �ϳ�
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

void menu_display(void);	// ����

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

void menu_display(void)		// ���Ǳ�
{
	printf("--------------------menu_display()--------------------\n");
	printf("������ ������ �߿� �ϳ��� �Է��Ͽ� item�� �����̼���:\n\n");
	printf("W: ���� �̵�\n");
	printf("A: ���������� �̵�\n");
	printf("S: �Ʒ��� �̵�\n");
	printf("D: �������� �̵�\n");
}

char input_direction(void)	// (w == ��, a == ����, s == �Ʒ�,  d == ������)
{
	char dir;			// �ӽ� ���� ����
	printf("�̵��� ������ �Է����ּ���: ");
	scanf("%c", &dir);	// ����ڰ� �Է��� �����͸� ��Ҵ�.

	return dir;
}

void move_item(char dir)
{
	int x_dif = 0, y_dif = 0;

	switch (dir)
	{
	case UP:	// ��
		y_dif = +1;
		break;
	case LEFT:	// ����
		x_dif = -1;
		break;
	case DOWN:	// �Ʒ�
		y_dif = -1;
		break;
	case RIGHT:	// ������
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
	
	for (int col = 9; col >= 0; col--)	// �� �ϳ���
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
