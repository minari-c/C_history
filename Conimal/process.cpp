#include <iostream>
#include <tchar.h>

#include <Windows.h>



int _tmain (void)
{
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	memset(&si, 0, sizeof(si));
	memset(&pi, 0, sizeof(pi));

	// 메모장 실행 예제
	// TCHAR -> L"" -> wide charter
	// _T -> 유니코드 문자열 define 여부에 따라서 L"", ""로 나뉜다.
	TCHAR command[] = TEXT("notepad.exe");

	// 이렇게 전달하면 a.txt 파일 메모장으로 오픈합니다.
	//TCHAR command[] = TEXT("notepad.exe C:\\Users\\Kim\\Desktop\\전략내용\\a.txt");

	if (CreateProcess(NULL, command, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi))
	{
		// pi.hProcess 생성된 프로세스 핸들, pi.hThread 생성된 프로세스 스레드 핸들
		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);
	}

	return 0;
}