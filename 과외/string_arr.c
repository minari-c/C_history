#include <stdio.h>
//char dummy[10] = "appleapple";	// ������ �ս�	-> NULL(�ǹ̰� ���� ���� �־ �ս� ����)
	// NULL ���ڰ� ���� ��� ��� ����ϴٰ�.
	// �ǵ��̸� �� �Ǵ� ������ ������ ���α׷��� �����.
	// �ѱ�, ���� ���� �����ڵ� ��� ( 2byte ) 
	// [0110 0001] �ƽ�Ű�ڵ� ( 1byte )					-> aa
	// [ 0110 0001 0110 0001 ] �����ڵ�( 2byte )		-> (24,929)
//"appleapple";
// 1. ����ڰ� ""�ӿ� �Է��� ���ڿ��� �迭 ������ �о��
// 2. ������ ����ϴٸ� ���ڿ� ���� \0�� �־���
// appleapple\0\0\0\0\0
// ���� ���� 10ĭ���δ� ���� �� ���� -> �ź�

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