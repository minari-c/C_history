/*
 data_type:
 ��ǻ�� ���ο��� �ڷḦ ǥ���ϴ� ���

 ���� ( ���, ����, 0 )
 int( 32bit == 4byte ), short, long, long long

 �Ǽ� ( ���, ����, 0.0 )
 float( 32bit == 4byte ), double( 64bit == 4byte ), long double

 ���� ( ASCII code )
 char

 �ּ� ( address )
 *
 ex) (char*)

 ���� ����:
 data_type �����̸�;

 ex) float a;

 1byte == 8bit ( 2^8 )
 0, 1 == 1bit ( 2^1 )
*/


/*
������ �ּ�
*/

// �����ּ�

#include <stdio.h>	// ǥ������� �������

int main(void)	// main�Լ� (���α׷��� ������)
{
	double a, b;	// a(8ĭ), b(8ĭ)
	scanf("%f %f", &a, &b);	// 10.1\n10.1

	// a == 10.1
	// b == 10.1
	printf("%f %f", a, b);

	return 0;
}

