#include <stdio.h>

int main(void)
{
	int a = 5, b = 24;
	int* juso;
	int* pa = &a, * pb = &b;	// 포인터 타입 (int*) (int[])

	//  * == &
	// (*pa)[10]
	// &pa
	// (pb!=&b) ? 'a' : 'b'
	// 1. &b					-> b의 주소
	// 2. pb != b의 주소		-> 거짓
	// 3. (pb!=&b) ? 'a' : 'b'	-> 'b'

	if ( a != **&pa )	// &pa != &&a -> pa == &a -> *pa == a
	{
		printf("%d\n", **&pa);
	}
	else
	{
		printf("%d\n", **&pb);
	}

	// 우선순위가 무조건은 아니다.
	// 연산자는 자료형에 따라서 달라진다.
	// 주소값: 곱하기 나누기는 안 된다.
	// 단, 더하기 빼기는 된다.
	printf("result: %d\n", 8 * *pa % ++ * *&pb);
	// 8 * *pa % ++ * * &pb
	// *pa			-> a의 값
	// 8 * (a의 값)	-> 40
	// &pb			-> pb의 주소 값
	// * (pb의 주소 값)	-> pb == &b ( b의 주소 값 )
	// * (b의 주소 값)		-> b의 값
	// ++ ( b의 값 )		-> ( b에 1이 더해지고 ) b 
	// 40 % 25

	*( juso = &b ) *= *pb;
	// &b	-> b의 주소
	// juso = b의 주소	-> b의 주소
	// *(b의주소)	-> b의 값
	// *pb	-> b의 값
	// b의 값 *= b의 값 -> (b * b)

	printf("%d\n", *juso);
	printf("%d\n", b);

	return 0;
}