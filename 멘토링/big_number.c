#include <stdio.h>

/*
문제:
두 정수 A와 B를 입력받은 다음, A+B를 출력하는 프로그램을 작성하시오.

입력:
첫째 줄에 A와 B가 주어진다. (0 < A,B < 10^10000)

출력:
첫째 줄에 A+B를 출력한다.


가정:
1. 합은 10^10001일 것이다.
2. 정수 입력 순서는 queue의 규칙을 따른다.
	- 따라서 뒤집어서 들어온다.

구현:
가장 앞 쪽에 carry를 위한 자리수를 남기고 계산한다. -> 계산할 때 자리수가 안 맞음

실제 구현:
 디버깅을 편리하게 하기 위해서 합 결과를 담을 배열 c를 선언

 입력 받은 큰 수를 저장하는 a 와 b 배열을 선언
 => 입력 데이터를 %s format으로 저장

 1. 순행으로 더할 경우
	- 12345			[a]
	- 1234			[b]
	자리 수가 맞지 않는 문제가 생김
	sol_1)
		12345
		01234
		=> 문제: 밀어낼 때 너무 큰 수라면 반복이 많아짐
	sol_2)
		12345
		1234
		=> 가장 높은 자리부터 더하는데 a, b 중에 값인 것만 더한다.
		1) a, b의 자리수 길이를 구한다.
			12345: [5]
			 1234: [4]
		2) a 와 b의 길이 차이만큼 a, b 중에 가장 큰 수를 먼저 더한다.
			12345	   : [5]a
			    1	   : [1]b
		   01234(5 + 1): [4]c
		3) c에서 10 이상 것을 자리 올림을 적용해준다.
*/

#define MAX_DIGIT 10003

int main(void)
{
	int c_len = 1, a_len, b_len, c[MAX_DIGIT] = { 0, };
	char a[MAX_DIGIT] = { 0, }, b[MAX_DIGIT] = { 0, };

	scanf("%s %s", a, b);

	for (a_len = 0; a[a_len] != 0; a_len++);
	for (b_len = 0; b[b_len] != 0; b_len++);

	// 12345 1234
	// a_len - b_len

	if (a_len != 0)
		a_len--;
	if (b_len != 0)
		b_len--;
	// for 문에서 측정한 a_len을 index_number형태로 맞춰준다.

	if (a_len > b_len)		// 만약 a 배열의 자리수가 더 크다면
	{
		for (int i = 0; i < a_len - b_len; i++)						// a는 존재하지만 b는 존재하지 않는 c자리수
		{
			c[c_len] += a[i] - '0';									// a를 정수로 바꿔준다.
			c_len++;
		}
		for (int i = 0; i <= b_len; i++)
		{
			c[c_len] += a[i + a_len - b_len] + b[i] - '0' - '0';	// a와 b 를 정수로 바꿔야하기 때문에 - '0'를 2번 빼준다.
			c_len++;
		}
	}
	else if (a_len < b_len)
	{
		for (int i = 0; i < b_len - a_len; i++)
		{
			c[c_len] += b[i] - '0';
			c_len++;
		}
		for (int i = 0; i <= a_len; i++)
		{
			c[c_len] += a[i] + b[i + b_len - a_len] - '0' - '0';
			c_len++;
		}
	}
	else
	{
		for (int i = 0; i <= a_len; i++)
		{
			c[c_len] += a[i] + b[i] - '0' - '0';
			c_len++;
		}
	}

	for (int i = c_len; i > 0; i--)
		if (c[i] >= 10)
		{
			c[i - 1] += 1;
			c[i] -= 10;
		}

	if (c[0] != 0)
		printf("%d", c[0]);
	for (int i = 1; i < c_len; i++)
		printf("%d", c[i]);
}