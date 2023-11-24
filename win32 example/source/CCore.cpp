#include "pch.h"
#include "CCore.h"

#include "CTimeMgr.h"
#include "CKeyMgr.h"

CCore::CCore( )
	: m_hWnd{ 0 }
	, m_ptResolution{ 0, 0 }
	, m_hDC{ 0 }
	, m_hBit{ 0 }
	, m_memDC{ 0 }
{

}

CCore::~CCore( )
{
	ReleaseDC( m_hWnd, m_hDC );

	DeleteDC( m_memDC );
	DeleteObject( m_hBit );
}

int CCore::init( HWND _hWnd, POINT _ptResolution )
{
	m_hWnd = _hWnd;
	m_ptResolution = _ptResolution;

	// 해상도 크기에 맞게 윈도우 크기 조정
	RECT rt = { 0, 0, m_ptResolution.x, m_ptResolution.y };
	AdjustWindowRect( &rt, WS_OVERLAPPEDWINDOW, true );
	SetWindowPos( m_hWnd, nullptr, 100, 100, rt.right - rt.left, rt.bottom - rt.top, 0 );

	m_hDC = GetDC( m_hWnd );

	// 더블 버퍼링 용도의 비트맵과 DC 생성
	m_hBit = CreateCompatibleBitmap( m_hDC, m_ptResolution.x, m_ptResolution.y );
	m_memDC = CreateCompatibleDC( m_hDC );

	HBITMAP hDefaultBit = (HBITMAP)SelectObject( m_memDC, m_hBit );
	DeleteObject( hDefaultBit );

	// Manager 초기화
	CTimeMgr::GetInst( )->init( );
	CKeyMgr::GetInst( )->init( );

	return S_OK;
}

void CCore::progress( )
{
	// Manager update
	CTimeMgr::GetInst( )->update( );
	CKeyMgr::GetInst( )->update( );

	update( );

	render( );
}

void CCore::update( )
{

}

void CCore::render( )
{

}