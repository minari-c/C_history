#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void sort_rotto(int[6]);	// 다음 시간에

void make_rotto(int[6]);

void make_rotto_paper(int[5][6]);	// 다음 시간에

void print_rotto(int[6]);

void print_rotto_paper(int[5][6]);	// 다음 시간에

void rotto_machine(int);

int rotto_seller(int, int);			// 금액, 구매할 장수

int main(void)
{
	int money, buy_count;
	srand((unsigned int)time(NULL));

	printf("돈을 입력하세요: ");
	scanf("%d", &money);

	printf("구매할 장수를 입력하세요: ");
	scanf("%d", &buy_count);

	printf("복권을 구매하고 남은 돈: %d원", rotto_seller(money, buy_count));

	return 0;
}

void sort_rotto(int rotto[6])
{
	int min, temp;
	// a <-> b
	// temp = a
	// a = b
	// b = temp
	// 0번 값을 정해줌: 가장 작은 값
	// 1 6 5 4 3 2 
	// 0: 1
	// 0: 2
	for ( int i = 0; i < 5; i++ )	// i: 0 ~ 4, 최소값의 방번호
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

	sort_rotto(arr);	// 로또 값을 다 만들고 정렬 해준다.
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

void rotto_machine(int paper_count)	// 원하는 장수만큼 출력
{
	int paper[5][6]; // [0 ~ 4] [0 ~ 5] 비어있는 로또 종이

	for ( int i = 0; i < paper_count; i++ )	// 얘가 구매할 수 있는만큼 복권 만들어서 출력해주기
	{
		printf("복권을 총 %d장 구매했습니다.\n", paper_count);

		make_rotto_paper(paper);

		printf("\n%d번째 복권", i + 1);
		print_rotto_paper(paper);
	}
}

int rotto_seller(int money, int buy_count)	// 복권방 주인 ( 계산 )
{
	// int paper_count = 0;
	int total_buy_money = ( 5000 * buy_count );

	printf("%d장의 복권은 %d원입니다.\n", buy_count, total_buy_money);

	if ( money >= total_buy_money )// 구매가능
	{
		// paper_count = money / 5000;	// 몇장 구매가능한 돈을 가지고 있는지

		money -= total_buy_money;

		rotto_machine(buy_count);
	}
	else					// 구매 불가능(그지)
	{
		printf("현재 가지고 있는 돈으로는 복권을 구매할 수 없습니다.\n");
	}

	return money;
}

/*
 로또:
 번호: 1 ~ 45
 번호 6개 -> 로또 하나
 중복이 없음.

 로또 하나가 만들어지고 출력하는 과정까지

*/

// 1. 내가 가지고 있는 돈이 부족해서 구매하지 못하면 더 적게 구매할 수 있게
// 2. 조금 더 예쁘게 복권 입출력을 꾸며보기