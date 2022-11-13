#include <iostream>
#include <tchar.h>

#include <Windows.h>



int _tmain (void)
{
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	memset(&si, 0, sizeof(si));
	memset(&pi, 0, sizeof(pi));

	// �޸��� ���� ����
	// TCHAR -> L"" -> wide charter
	// _T -> �����ڵ� ���ڿ� define ���ο� ���� L"", ""�� ������.
	TCHAR command[] = TEXT("notepad.exe");

	// �̷��� �����ϸ� a.txt ���� �޸������� �����մϴ�.
	//TCHAR command[] = TEXT("notepad.exe C:\\Users\\Kim\\Desktop\\��������\\a.txt");

	if (CreateProcess(NULL, command, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi))
	{
		// pi.hProcess ������ ���μ��� �ڵ�, pi.hThread ������ ���μ��� ������ �ڵ�
		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);
	}

	return 0;
}