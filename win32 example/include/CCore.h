#pragma once

class CCore
{
	SINGLETON( CCore );

public:
	int init( HWND _hWnd, POINT _ptResolution );
	void progress( );
	HWND GetMainHWND( ) { return m_hWnd; }
	POINT GetResolution( ) { return m_ptResolution; }

private:
	HWND m_hWnd;				// ���� ������ �ڵ�
	POINT m_ptResolution;		// ���� ������ �ػ�
	HDC m_hDC;					// ���� ������ DC

	HBITMAP m_hBit;
	HDC m_memDC;
};
