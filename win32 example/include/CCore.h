#pragma once

class CCore
{
	SINGLETON( CCore );

public:
	int init( HWND _hWnd, POINT _ptResolution );
	void progress( );
	HWND GetHWND( ) { return m_hWnd; }

private:
	HWND m_hWnd;				// 메인 윈도우 핸들
	POINT m_ptResolution;		// 메인 윈도우 해상도
	HDC m_hDC;					// 메인 윈도우 DC

	HBITMAP m_hBit;
	HDC m_memDC;

	void update( );
	void render( );
};
