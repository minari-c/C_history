#include <stdio.h>

int total_price(int, int, int);
int pay(int, int);
void available_buy(int);

int main(void)
{
    int money;     // 내가 가지고 있는 돈, 물품1, 2, 3
    int total_purchase, change; // 총 구매금액, 잔돈

    printf("내가 가지고 있는 금액:");
    scanf("%d", &money);

    printf("==================잔돈이 남는 경우 확인=================\n");
    for (int cream = 1; cream < 8; cream++)
    {
        for (int shrimp = 1; shrimp < 6; shrimp++)
        {
            for (int cola = 1; cola < 9; cola++)
            {
                total_purchase = total_price(cream, shrimp, cola);  // 구매하고자 하는 물품 가격의 합
                change = pay(money, total_purchase);                // 실제로 결제를 해본다.

                printf("%d, %d, %d, %5d원\t", cream, shrimp, cola, change);


                available_buy(change);                              // 구매가 가능한지 판단한다.
                
                {
                    if (cola == 4)  // 무시
                        printf("\n");
                }
            }
            printf("\n");
        }
    }

    return 0;
}

int total_price(int cream_count, int shrimp_count, int cola_count)
{
    
    return (cream_count * 500) + (shrimp_count * 700) + (cola_count * 400);
}

int pay(int money, int total_purchase)
{   
    return money - total_purchase;
}

void available_buy(int change)
{
    if (change >= 0)    // 거스름 돈
    {
        printf("[o]");
    }
    else
    {
        printf("[x]");
    }

    printf("\n");
}