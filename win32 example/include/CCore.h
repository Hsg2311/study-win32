#pragma once

class CCore
{
	SINGLETON( CCore );

public:
	int init( HWND _hWnd, POINT _ptResolution );
	void progress( );
	HWND GetHWND( ) { return m_hWnd; }

private:
	HWND m_hWnd;				// ���� ������ �ڵ�
	POINT m_ptResolution;		// ���� ������ �ػ�
	HDC m_hDC;					// ���� ������ DC

	HBITMAP m_hBit;
	HDC m_memDC;

	void update( );
	void render( );
};
