#include <stdio.h>
//char dummy[10] = "appleapple";	// 데이터 손실	-> NULL(의미가 없을 수도 있어서 손실 가능)
	// NULL 문자가 끝에 없어서 계속 출력하다가.
	// 건들이면 안 되는 공간에 닿으면 프로그램이 멈춘다.
	// 한글, 한자 등은 유니코드 사용 ( 2byte ) 
	// [0110 0001] 아스키코드 ( 1byte )					-> aa
	// [ 0110 0001 0110 0001 ] 유니코드( 2byte )		-> (24,929)
//"appleapple";
// 1. 사용자가 ""속에 입력한 문자열을 배열 공간에 읽어옴
// 2. 공간이 충분하다면 문자열 끝에 \0을 넣어줌
// appleapple\0\0\0\0\0
// 내가 가진 10칸으로는 넣을 수 없어 -> 거부

int main(void)
{
	char stu_name_list[4][10] = {
		"apple",			// stu_num = 0
		"cat",				// stu_num = 1
		"dog",				// stu_num = 2
		"appleappl"			// stu_num = 3
	};

	for ( int stu_num = 0; stu_num < 4; stu_num++ )
	{
		for ( int i = 0; i < 10; i++ )
		{
			printf("%3d ", stu_name_list[stu_num][i]);
		}
		printf("\n");
	}

	printf("\n");

	for ( int stu_num = 0; stu_num < 4; stu_num++ )
	{
		for ( int i = 0; i < 10; i++ )
		{
			printf("%c ", stu_name_list[stu_num][i]);
		}
		printf("\n");
	}

	return 0;
}