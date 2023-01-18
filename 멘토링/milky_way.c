#include <stdio.h>
#include <stdlib.h>

/*
첫째 줄에 N이 주어진다. N은 3의 거듭제곱이다. 즉 어떤 정수 k에 대해 N=3k이며, 이때 1 ≤ k < 8이다.
***
* *
***

*/

void square(char* s_point, int square_edge, int* const per_col, char star)
{
	if (square_edge == 1)
	{
		for (int col = 0; col < 3; col++)
		{
			for (int row = 0; row < 3; row++)
			{
				*(s_point + ((*per_col) * col) + row) = star;
				
				if (row == 1 && col == 1)
					*(s_point + ((*per_col) * col) + row) = ' ';
			}
		}
		return;
	}
	else
	{
		for (int col = 0; col < 3; col++)
		{
			for (int row = 0; row < 3; row++)
			{
				if (row == 1 && col == 1)
					square(s_point + (*per_col * col * square_edge) + (square_edge * row), square_edge / 3, per_col, ' ');
				else
					square(s_point + (*per_col * col * square_edge) + (square_edge * row), square_edge / 3, per_col, star);
			}
		}
	}
}

int main(void)
{
	int us_in;
	int map_cnt;
	char* milky_way;
	scanf("%d", &us_in);

	map_cnt = us_in * us_in;
	milky_way = (int*)malloc(sizeof(int) * map_cnt);

	square(milky_way, us_in / 3, &us_in, '*');

	for (int col = 0; col < us_in; col++)
	{
		for (int row = 0; row < us_in; row++)
			printf("%c", *(milky_way + (us_in * col) + row));
		printf("\n");
	}
}
