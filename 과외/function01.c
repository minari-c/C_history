#include <stdio.h>

void add(int a, int b)	// return�� void�� ���� ����� ���ο��� ���� ��
{
	printf("%d", a + b);
}

int add(int a, int b)	// ��Դ� return�� ���� �Լ��� ��ɰ� �̸��� ��������.
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

void print_dan(int dan)		// return -> �ش��ϴ� ���� ���
{
	// dan * i = ..
}

void print_gugudan(void)	// 1 ~ 9��
{
	for (int i = 1; i <= 9; i++)
	{
		print_dan(i);
	}
}

// print_gugudan { print_dan() * 9�� }
/*
 ���� ��ȯ��:

 �Է��� ������ ��ȯ�� �ݾ�(����)
 ����� ������ ����(����)

 ex) 4500�� -> 7

 �����Լ�:
 4500���� 500�� 7���� �ٲ� �� �ֽ��ϴ�. (��� ����)
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
 �Լ�: �ϳ��� ��� ����

 ������Ʈ�� Ŀ����, ���α׷��� Ŀ����

 ex)
 int: ���� ( ����, 0, ��� )
 ����� ������ �����ؾ��� ��
 -> ���� ���ǿ� �ִ� �� ��ǻ�� ������ �����ϱ� ���ؼ� 
 -> ������ ���踦 ������ ���α׷��� ������ ��.

 1. ���������� ���̼�	( ��� ������ �׽�Ʈ Ȥ�� ��ü�� ���� )
 2. ����ȭ�� ���̼�     ( ���� � ���α׷��� ü�������� ������ �� ���� )
 3. �������� ����       ( ���ǰ� ������ ������ �����Բ� ������ �� �ִ�. )


 void: ���Ƿ� ������ Ÿ��
 -> ����ִ�



 int, float ���ǿ� �ִ� Ÿ��

 �Լ��� �Ű������� ���� �Լ�
 �ش� ���� �������� 3 by 3���� ����Ѵ�.
 print_dan
 
*/
