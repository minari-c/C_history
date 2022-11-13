#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void sort_rotto(int[6]);	// ���� �ð���

void make_rotto(int[6]);

void make_rotto_paper(int[5][6]);	// ���� �ð���

void print_rotto(int[6]);

void print_rotto_paper(int[5][6]);	// ���� �ð���

void rotto_machine(int);

int rotto_seller(int, int);			// �ݾ�, ������ ���

int main(void)
{
	int money, buy_count;
	srand((unsigned int)time(NULL));

	printf("���� �Է��ϼ���: ");
	scanf("%d", &money);

	printf("������ ����� �Է��ϼ���: ");
	scanf("%d", &buy_count);

	printf("������ �����ϰ� ���� ��: %d��", rotto_seller(money, buy_count));

	return 0;
}

void sort_rotto(int rotto[6])
{
	int min, temp;
	// a <-> b
	// temp = a
	// a = b
	// b = temp
	// 0�� ���� ������: ���� ���� ��
	// 1 6 5 4 3 2 
	// 0: 1
	// 0: 2
	for ( int i = 0; i < 5; i++ )	// i: 0 ~ 4, �ּҰ��� ���ȣ
	{
		for ( int j = i + 1; j < 6; j++ )
		{
			if ( rotto[i] > rotto[j] )
			{
				temp = rotto[i];
				rotto[i] = rotto[j];
				rotto[j] = temp;
			}
		}
	}
}

void make_rotto(int arr[6])
{
	int rotto_numbers[45];	//	0 ~ 44
	int max_rotto = 45, rand_num;

	for ( int i = 0; i < max_rotto; i++ )
	{
		rotto_numbers[i] = i + 1;
	}

	for ( int i = 0; i < 6; i++ )
	{
		rand_num = ( rand() % max_rotto ) + 1 - 1;
		arr[i] = rotto_numbers[rand_num];

		rotto_numbers[rand_num] = rotto_numbers[max_rotto - 1];
		rotto_numbers[max_rotto - 1] = -1;
		max_rotto -= 1;
	}

	sort_rotto(arr);	// �ζ� ���� �� ����� ���� ���ش�.
}

void make_rotto_paper(int arr[5][6])
{
	for ( int i = 0; i < 5; i++ )
	{
		make_rotto(arr[i]);
	}
}

void print_rotto(int arr[6])
{
	for ( int i = 0; i < 6; i++ )
	{
		printf("%2d ", arr[i]);
	}
}

void print_rotto_paper(int arr[5][6])
{
	printf("\n============================\n");
	for ( int i = 0; i < 5; i++ )	// i: 0 ~ 4
	{
		print_rotto(arr[i]);
		printf("\n");
	}
	printf("============================\n");
}

void rotto_machine(int paper_count)	// ���ϴ� �����ŭ ���
{
	int paper[5][6]; // [0 ~ 4] [0 ~ 5] ����ִ� �ζ� ����

	for ( int i = 0; i < paper_count; i++ )	// �갡 ������ �� �ִ¸�ŭ ���� ���� ������ֱ�
	{
		printf("������ �� %d�� �����߽��ϴ�.\n", paper_count);

		make_rotto_paper(paper);

		printf("\n%d��° ����", i + 1);
		print_rotto_paper(paper);
	}
}

int rotto_seller(int money, int buy_count)	// ���ǹ� ���� ( ��� )
{
	// int paper_count = 0;
	int total_buy_money = ( 5000 * buy_count );

	printf("%d���� ������ %d���Դϴ�.\n", buy_count, total_buy_money);

	if ( money >= total_buy_money )// ���Ű���
	{
		// paper_count = money / 5000;	// ���� ���Ű����� ���� ������ �ִ���

		money -= total_buy_money;

		rotto_machine(buy_count);
	}
	else					// ���� �Ұ���(����)
	{
		printf("���� ������ �ִ� �����δ� ������ ������ �� �����ϴ�.\n");
	}

	return money;
}

/*
 �ζ�:
 ��ȣ: 1 ~ 45
 ��ȣ 6�� -> �ζ� �ϳ�
 �ߺ��� ����.

 �ζ� �ϳ��� ��������� ����ϴ� ��������

*/

// 1. ���� ������ �ִ� ���� �����ؼ� �������� ���ϸ� �� ���� ������ �� �ְ�
// 2. ���� �� ���ڰ� ���� ������� �ٸ纸��