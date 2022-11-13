/*
 data_type:
 컴퓨터 내부에서 자료를 표현하는 방법

 정수 ( 양수, 음수, 0 )
 int( 32bit == 4byte ), short, long, long long

 실수 ( 양수, 음수, 0.0 )
 float( 32bit == 4byte ), double( 64bit == 4byte ), long double

 문자 ( ASCII code )
 char

 주소 ( address )
 *
 ex) (char*)

 변수 선언:
 data_type 변수이름;

 ex) float a;

 1byte == 8bit ( 2^8 )
 0, 1 == 1bit ( 2^1 )
*/


/*
여러줄 주석
*/

// 한줄주석

#include <stdio.h>	// 표준입출력 헤더파일

int main(void)	// main함수 (프로그램의 시작점)
{
	double a, b;	// a(8칸), b(8칸)
	scanf("%f %f", &a, &b);	// 10.1\n10.1

	// a == 10.1
	// b == 10.1
	printf("%f %f", a, b);

	return 0;
}

