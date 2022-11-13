#include <stdio.h>

int total_price(int, int, int);
int pay(int, int);
void available_buy(int);

int main(void)
{
    int money;     // ���� ������ �ִ� ��, ��ǰ1, 2, 3
    int total_purchase, change; // �� ���űݾ�, �ܵ�

    printf("���� ������ �ִ� �ݾ�:");
    scanf("%d", &money);

    printf("==================�ܵ��� ���� ��� Ȯ��=================\n");
    for (int cream = 1; cream < 8; cream++)
    {
        for (int shrimp = 1; shrimp < 6; shrimp++)
        {
            for (int cola = 1; cola < 9; cola++)
            {
                total_purchase = total_price(cream, shrimp, cola);  // �����ϰ��� �ϴ� ��ǰ ������ ��
                change = pay(money, total_purchase);                // ������ ������ �غ���.

                printf("%d, %d, %d, %5d��\t", cream, shrimp, cola, change);


                available_buy(change);                              // ���Ű� �������� �Ǵ��Ѵ�.
                
                {
                    if (cola == 4)  // ����
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
    if (change >= 0)    // �Ž��� ��
    {
        printf("[o]");
    }
    else
    {
        printf("[x]");
    }

    printf("\n");
}