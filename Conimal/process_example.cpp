#include "pre_cmp_h.h"

#ifndef _MY_DEBUG
#define _MY_DEBUG
#endif

#ifndef PROCESS_NAME
#define PROCESS_NAME "notepad"
#endif

#ifndef PHOTO_PROCESS_NAME
#define PHOTO_PROCESS_NAME "mspaint"
#endif
//Microsoft.Photos.exe

#ifndef PROCESS_EXTENSION
#define PROCESS_EXTENSION  PROCESS_NAME + ".exe" 
#endif

#ifndef PHOTO_PROCESS_EXTENSION
#define PHOTO_PROCESS_EXTENSION  PHOTO_PROCESS_NAME + ".exe" 
#endif

#ifndef PHOTO_RESOURCE
#define PHOTO_RESOURCE " C:\\Users\\MinyaRi\\Desktop\\nero.png"
#endif

#ifndef PHOTO_COMMAND
#define PHOTO_COMMAND "mspaint.exe C:\\Users\\MinyaRi\\Desktop\\nero.png"
#endif

#ifndef LPROCESS_NAME
#define LPROCESS_NAME _T("notepad")
#endif

#ifndef LMASTER_WINDOW_NAME
#define LMASTER_WINDOW_NAME _T("master_note")
#endif

#ifndef LSLAVE_WINDOW_NAME 
#define LSLAVE_WINDOW_NAME _T("slave_note")
#endif

void open_notepad( void );

int main( void )
{
	DWORD aProcesses[1024], cbNeeded, cProcesses;

	if (!EnumProcesses( aProcesses, sizeof( aProcesses ), &cbNeeded )) { return 1; }

	open_notepad();

	return 0;
}

void open_notepad( void )
{
	// LPDWORD lpd_temp = (LPDWORD)malloc( sizeof( DWORD ) * 17 );
	LPWINDOWPLACEMENT lpwndpl_temp = (LPWINDOWPLACEMENT)malloc( sizeof( WINDOWPLACEMENT ) );
	RECT rect;
	STARTUPINFO si_master, si_slave;
	PROCESS_INFORMATION pi_master, pi_slave;
	HWND win_h;
	TCHAR command_master[] = _T( PROCESS_NAME );
	TCHAR command_slave[] = _T( PHOTO_COMMAND );

	memset( &si_master, 0, sizeof( si_master ) ); memset( &si_slave, 0, sizeof( si_slave ) );
	memset( &pi_master, 0, sizeof( pi_master ) ); memset( &pi_slave, 0, sizeof( pi_slave ) );

	GetStartupInfoW( &si_master ); GetStartupInfoW( &si_slave );

	CreateProcess( NULL, command_master, NULL, NULL, FALSE, 0, NULL, NULL, &si_master, &pi_master );
	Sleep( 100 );
	HWND master_window_handle = GetWinHandle( pi_master.dwProcessId );
	// HWND master_window_handle = FindWindow( LPROCESS_NAME, NULL );

	CreateProcess( NULL, command_slave, NULL, NULL, FALSE, 0, NULL, NULL, &si_slave, &pi_slave );
	Sleep( 100 );
	HWND slave_window_handle = GetWinHandle( pi_slave.dwProcessId );
	// HWND slave_window_handle = FindWindowW( LPROCESS_NAME, NULL );

	_tprintf( _T( "pi_master.dwProcessId  = %d\n" ), pi_master.dwProcessId );
	_tprintf( _T( "pi_slave.dwProcessId  = %d\n" ), pi_slave.dwProcessId );

	_tprintf( _T( "master_window_handle = %p\n" ), master_window_handle ); _tprintf( _T( "slave_window_handle = %p\n" ), slave_window_handle );
	// https://blog.naver.com/tipsware/221547634772
	LONG_PTR master_originalWndProc = GetWindowLongPtrW( master_window_handle, GWLP_WNDPROC );
	SetWindowLongPtr( master_window_handle, GWLP_WNDPROC, (LONG_PTR)DefWindowProcW );

	LONG_PTR slave_originalWndProc = GetWindowLongPtrW( slave_window_handle, GWLP_WNDPROC );
	SetWindowLongPtr( slave_window_handle, GWLP_WNDPROC, (LONG_PTR)DefWindowProcW );

	SetWindowPos(
			master_window_handle, HWND_TOP,
			200, 300,
			200, 300, SWP_SHOWWINDOW
	);
	SetWindowPos(
			slave_window_handle, HWND_TOP,
			180, 250,
			180, 250, SWP_SHOWWINDOW
	);

	SetWindowTextW( master_window_handle, LMASTER_WINDOW_NAME ); Sleep( 200 );
	SetWindowTextW( slave_window_handle, LSLAVE_WINDOW_NAME ); Sleep( 200 );

	while ((master_window_handle = GetWinHandle( pi_master.dwProcessId )) != NULL)
	// while ((master_window_handle = FindWindowW( LPROCESS_NAME, LMASTER_WINDOW_NAME )) != NULL)
	{
		Sleep( 0.1 );

		if (GetWindowPlacement( master_window_handle, lpwndpl_temp ))
		{
			SetWindowPos(
			slave_window_handle, HWND_TOP,
			lpwndpl_temp->rcNormalPosition.left, lpwndpl_temp->rcNormalPosition.top - 250,
			200, 300, SWP_NOSIZE
			);
			// cout << "set pos\n";
		}
		else { cout << "master destroyed\n"; }

		Sleep( 0.1 );
	}

	SetWindowLongPtrW( master_window_handle, GWLP_WNDPROC, master_originalWndProc );
	SetWindowLongPtrW( slave_window_handle, GWLP_WNDPROC, slave_originalWndProc );

	CloseHandle( pi_slave.hProcess );
	CloseHandle( pi_slave.hThread );

	CloseHandle( pi_master.hProcess );
	CloseHandle( pi_master.hThread );

	// free( lpd_temp );
}


// HWND는 Window ID로 보면 되고, CWnd는 m_hWnd(HWND) Wrapper.
// GetWindowThreadProcessId( master_window_handle, lpd_temp );

// GetWindowRect( window_handle, &rect );

// 이렇게 전달하면 a.txt 파일 메모장으로 오픈합니다.
// TCHAR command[] = TEXT( "notepad.exe C:\\Users\\MinyaRi\\source\\repos\\Project3\\Project3\\resource\\a.txt" );

#pragma region lpwndpl_ref
	/*
	typedef struct tagWINDOWPLACEMENT {
	UINT  length;
	UINT  flags;
	UINT  showCmd;
	POINT ptMinPosition;
	POINT ptMaxPosition;
	RECT  rcNormalPosition;
	*/
#pragma endregion

#pragma region get_windows_size
		// pi.hProcess 생성된 프로세스 핸들, pi.hThread 생성된 프로세스 스레드 핸들
		// GetWindowRect( pi.hProcess, &rect );
		/*GetProcessId( pi.hProcess );
		printf( "window_handle = %d\n", pi.hProcess );*/
		// SetWindowPos();
#pragma endregion

#pragma region SETWINDOWPOS_ref
/*
BOOL SetWindowPos(
[in]           HWND hWnd,
[in, optional] HWND hWndInsertAfter,
[in]           int  X,
[in]           int  Y,
[in]           int  cx,
[in]           int  cy,
[in]           UINT uFlags
);
	*/
#pragma endregion

#pragma region HWND_ref
		// http://www.borlandforum.com/impboard/impboard.dll?action=read&db=bcb_qna&no=25856
		/*
		struct HWND__
		{
			int unused;
		}; typedef HWND__ *HWND;

		1.함수에서 CWnd 가 필요한데 HWND밖에 없을 때
		CWnd* pWnd = CWnd::FromHandle(HWND);

		2.HWND가 필요한데 CWnd 밖에 없을때
		HWND hWnd = pWnd->m_hWnd;
		*/
#pragma endregion

#pragma region FIND_WINDOW_ref
	/*
	FindWindowW(
	_In_opt_ LPCWSTR lpClassName,
	_In_opt_ LPCWSTR lpWindowName
	);
	#ifdef UNICODE
	#define FindWindow  FindWindowW
	*/
#pragma endregion 

#pragma region CREATEPROCESS_ref
	/*
	CreateProcessW(
	_In_opt_ LPCWSTR lpApplicationName,
	_Inout_opt_ LPWSTR lpCommandLine,
	_In_opt_ LPSECURITY_ATTRIBUTES lpProcessAttributes,
	_In_opt_ LPSECURITY_ATTRIBUTES lpThreadAttributes,
	_In_ BOOL bInheritHandles,
	_In_ DWORD dwCreationFlags,
	_In_opt_ LPVOID lpEnvironment,
	_In_opt_ LPCWSTR lpCurrentDirectory,
	_In_ LPSTARTUPINFOW lpStartupInfo,
	_Out_ LPPROCESS_INFORMATION lpProcessInformation
	);
	#ifdef UNICODE
	#define CreateProcess  CreateProcessW
	*/
#pragma endregion

#pragma region PROCESS_INFORMATION_ref
	/*
	typedef struct _PROCESS_INFORMATION {
	HANDLE hProcess;
	HANDLE hThread;
	DWORD dwProcessId;
	DWORD dwThreadId;
	} PROCESS_INFORMATION, *PPROCESS_INFORMATION, *LPPROCESS_INFORMATION;
	*/
#pragma endregion

#pragma region STARTUPINFOW_ref
	/*
	typedef struct _STARTUPINFOW {
	DWORD   cb;
	LPWSTR  lpReserved;
	LPWSTR  lpDesktop;
	LPWSTR  lpTitle;
	DWORD   dwX;
	DWORD   dwY;
	DWORD   dwXSize;
	DWORD   dwYSize;
	DWORD   dwXCountChars;
	DWORD   dwYCountChars;
	DWORD   dwFillAttribute;
	DWORD   dwFlags;
	WORD    wShowWindow;
	WORD    cbReserved2;
	LPBYTE  lpReserved2;
	HANDLE  hStdInput;
	HANDLE  hStdOutput;
	HANDLE  hStdError;
	} STARTUPINFOW, *LPSTARTUPINFOW;
	#ifdef UNICODE
	typedef STARTUPINFOW STARTUPINFO;
	typedef LPSTARTUPINFOW LPSTARTUPINFO;
	*/
#pragma endregion

//SetWindowDisplayAffinity https://docs.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-setwindowdisplayaffinity

#pragma region CWnd_to_HWND
/*
	1. CWnd->HWND
	CWnd의 멤버 변수를 이용
	ex) CWnd* pcWnd;
	HWND   hWnd;
	hWnd = pcWnd->m_hWnd; // 방법 1
	hWnd = pcWnd->GetSafeHwnd(); // 방법 2

	2. HWND->CWnd
	CWnd 함수인 FromHandle() 을 사용
	ex) CWnd* pcwnd;
	HWND    hWnd;
	pcwnd = CWnd::FromHandle( hWnd );  // CWnd 가 해당  HWND 에 붙어 잇지 않으면 일시적으로 CWnd를 생성하고 핸들에 붙임
*/
#pragma endregion

#pragma region test_code
//	 cProcesses = cbNeeded / sizeof( DWORD );	// Calculate how many process identifiers were returned.
//
//	 Process name and process identifier(PID) for each process.
//	 for (int i = 0; i < cProcesses; i++)
//{
//	 if (aProcesses[i] != 0)
//	{
//		 PrintProcessNameAndID( aProcesses[i] );
//		 Sleep( 100 );
//		 _tprintf( TEXT( "running...\n" ) );
//	}
//}
#pragma endregion

#pragma region PRINT_PROCESS_INFO
		// _tprintf( _T( "before master_window_handle = %p\n" ), master_window_handle );
		// _tprintf( _T( "before master_window_handle = %p\n" ), FindWindowW( LPROCESS_NAME, LMASTER_WINDOW_NAME ) );
		// _tprintf( _T( "before master_window_handle = %p\n" ), GetWinHandle( pi_master.dwProcessId ) );

		/*printf( "GetProcessId( master_window_handle ) = %d\n", GetProcessId( master_window_handle ) );
		printf( "pi_master.dwProcessId = %d\n", pi_master.dwProcessId );

		printf( "GetProcessId( slave_window_handle ) = %d\n", GetProcessId( slave_window_handle ) );
		printf( "pi_slave.dwProcessId = %d\n\n", pi_slave.dwProcessId );*/

		// _tprintf( _T( "after master_window_handle = %p\n\n" ), master_window_handle );
		// _tprintf( _T( "after master_window_handle = %p\n\n" ), FindWindowW( LPROCESS_NAME, LMASTER_WINDOW_NAME ) );
		// _tprintf( _T( "before master_window_handle = %p\n" ), GetWinHandle( pi_master.dwProcessId ) );
#pragma endregion