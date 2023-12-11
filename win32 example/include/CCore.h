#pragma once

class CCore
{
	SINGLETON( CCore );

public:
	int init( HWND _hWnd, POINT _ptResolution );
	void progress( );

	HWND GetMainHWND( ) { return m_hWnd; }
	POINT GetResolution( ) { return m_ptResolution; }
	HDC GetMainDC( ) { return m_hDC; }

	void CreateBrushPen( );

	HBRUSH GetBrush( BRUSH_TYPE _eType ) { return m_arrBrush[ (UINT)_eType ]; }
	HPEN GetPen( PEN_TYPE _eType ) { return m_arrPen[ (UINT)_eType ]; }

private:
	HWND m_hWnd;				// 메인 윈도우 핸들
	POINT m_ptResolution;		// 메인 윈도우 해상도
	HDC m_hDC;					// 메인 윈도우 DC

	HBITMAP m_hBit;
	HDC m_memDC;

	// 자주 사용하는 GDI Object
	HBRUSH m_arrBrush[ (UINT)BRUSH_TYPE::EOE ];
	HPEN m_arrPen[ (UINT)PEN_TYPE::EOE ];
};
