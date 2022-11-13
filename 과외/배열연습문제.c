#include <stdio.h>

int main(void)
{
	int temp;	// �ӽ� ���� ����
	int size = 5;

	for ( int i = 0; i < 5; i++ )	// i: [ 0 ~ 4 ]
	{
		arr[i] = i + 1;
	}	// �ʱ�ȭ

	for ( int i = 0; i < 5; i++ )	// i: [ 0 ~ 4 ]
	{
		printf("arr[%d]: %d\n", i, arr[i]);
	}	// ��� 

	// ������
	// e d c b a
	// 0 1 2 3 4
	// 
	// 0 1 2 3 4 5
	for ( int i = 0; i < size / 2; i++ )
	{
		temp = arr[i];				// �� �κ� ����
		arr[i] = arr[size - 1 - i];	// �� �κп� �� �κ� �� ����
		arr[size - 1 - i] = temp;	// �� �κп� �� �κ� �� ���� ( temp )
	} // a b a

	// a b c
	// a b a
	// c b a
	// 
	// a b c d

	int a, b, c, d;
	int temp;	// �������

	int square[3][3] = {
		{1, 2, 3},	// 3 2 1
		{4, 5, 6},
		{7, 8, 9}
	};

	for ( int y = 0; y < 3; y++ )	// ����
	{
		for ( int x = 0; x < 3; x++ )	// �ʺ�
		{
			printf("%d ", square[y][x]);	// [0][0] ~ [1][1]
		}	// �� ��
		printf("\n");
	}	// �ϳ��� �簢��

	// ������ �迭 ���

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

 ���簢��

 1. 90��
 1 4 7
 2 5 8
 3 6 9

 2. �� �Ʒ�
 7 8 9
 1 2 3
 4 5 6

 3. �� ��
 3 1 2
 6 4 5
 9 7 8

 4. ������
 7 8 9
 4 5 6
 1 2 3

 5. ��ĭ�� �б� ( 22.01.03 )
 9 1 2
 3 4 5
 6 7 8

*/