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
	// �޸� �������� Ÿ���� ����.
	// �޸� ������ Ÿ�Կ� ���� ������ �ʴ´�.
	// ���� �а� ���� ����� ������ ���̴�.
	// OS�� �޸𸮸� �����ϴµ�
	// OS�� ���� �޸� 4ĭ�� �� �Ű�
	// �츮�� Ÿ�Կ� ���� �а� ���� ����� �ٸ��� �ϴ� �� ���̴�.


	// tdarr[0] == &tdarr[0][0];	// ���� ������ Ÿ���� �ٸ� ��츦 ����

	// arr 1���� �迭						-> �����̸�	-> Ư¡�� ����.
	// &arr[0] �迭�� ù��° ������ �ּҰ�  -> ��		-> �� �� ��ü

	// printf("%p %p\n", arr, &arr[0]);
	// printf("%d %d\n\n", sizeof(arr), sizeof(&arr[0]));

	// printf("%p %p %p\n", tdarr, tdarr[0], &tdarr[0][0]);
	// printf("%d %d %d", sizeof(tdarr), sizeof(tdarr[0]), sizeof(&tdarr[0][0]));

	// printf("\n%d", sizeof(&tdarr[0][0]));

	// printf("%d", sizeof(tdarr) / sizeof(int));
	// 1���� �迭�� [ int, int, int, int ] ù ��° ������ �ּҸ� ��´�.
	// 2���� �迭�� [ int[2], int[2] ] ù ��° ������ �ּҸ� ��´�.
/*
 a�� b�� ���ٴ� ����
 1. ������ ���� ����
 2. ������ �ڷ����� ����
 -> �� �ΰ����� ��� �����ؾ� �Ѵ�.
*/

/*
 ���� �� ĭ�� �� �� �ִ� ������ ������ ���� ������.

 2����: 0 �Ǵ� 1

 10����: 0 ~ 9

 16����: 0 ~ 9 A b c d e f
 -> ��κ� �ּҿ� ���� ���

 int arr[3] = { 1, 2, 3 };	// �迭 ����� ������(�ּ� �ڷ���)

	printf("%p\n%p\n%p\n%p", arr, &arr[0], &arr[1], &arr[2]);
*/
/*
 1����
 2����

 ����: dimension [ D ]
 ex) n���� -> nd

 �������� �ǹ�
 
 1����: ��
 2����: ��
 3����: ����


*/