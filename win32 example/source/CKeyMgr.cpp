#include "pch.h"
#include "CKeyMgr.h"

int g_arrVK[ (int)KEY::END_OF_ENUM_CLASS ] =
{
	VK_LEFT,
	VK_RIGHT,
	VK_UP,
	VK_DOWN,

	'Q',
	'W',
	'E',
	'R',
	'T',
	'Y',
	'U',
	'I',
	'O',
	'P',
	'A',
	'S',
	'D',
	'F',
	'G',
	'H',
	'J',
	'K',
	'L',
	'Z',
	'X',
	'C',
	'V',
	'B',
	'N',
	'M',

	VK_MENU,
	VK_CONTROL,
	VK_LSHIFT,
	VK_SPACE,
	VK_RETURN,
	VK_ESCAPE
};

CKeyMgr::CKeyMgr( )
{

}

CKeyMgr::~CKeyMgr( )
{

}

void CKeyMgr::init( )
{
	for ( int i = 0; i < (int)KEY::END_OF_ENUM_CLASS; ++i )
	{
		m_vecKey.push_back( tKeyInfo{ KEY_STATE::NONE, false } );
	}
}

void CKeyMgr::update( )
{
	// - 윈도우 포커싱 알아내기 -
	// GetFocus함수는 사용자가 실행시킨 프로그램의 윈도우 중 어느 것이라도 포커싱 되어있으면,
	// 그 윈도우의 HWND를 반환해 주고, 그렇지 않다면 nullptr을 반환해 준다.
	//
	// 만약 메인 윈도우의 포커싱에 대해서만 알아내고 싶다면,
	// CCore.h를 include한 뒤, GetMainHWND함수를 통해 메인 윈도우 핸들을 얻어온다.
	// 그러고 나서 GetFocus함수로 얻어온 HWND와 비교해 메인 윈도우가 포커싱 되어있는지 확인하면 된다.

	HWND hWnd = GetFocus( );

	// 윈도우 포커싱 중일 때, 키 이벤트 동작
	if ( nullptr != hWnd )
	{
		for ( int i = 0; i < (int)KEY::END_OF_ENUM_CLASS; ++i )
		{
			// 키가 눌려있다.
			if ( GetAsyncKeyState( g_arrVK[ i ] ) & 0x8000 )
			{
				if ( m_vecKey[ i ].bPrevPush )
				{
					// 이전에도 눌려있었다.
					m_vecKey[ i ].eKeyState = KEY_STATE::HOLD;
				}
				else
				{
					// 이전에는 안 눌려있었다.
					m_vecKey[ i ].eKeyState = KEY_STATE::TAP;
				}

				m_vecKey[ i ].bPrevPush = true;
			}

			// 키가 안 눌려있다.
			else
			{
				if ( m_vecKey[ i ].bPrevPush )
				{
					// 이전에는 눌려있었다.
					m_vecKey[ i ].eKeyState = KEY_STATE::AWAY;
				}
				else
				{
					// 이전에도 안 눌려있었다.
					m_vecKey[ i ].eKeyState = KEY_STATE::NONE;
				}

				m_vecKey[ i ].bPrevPush = false;
			}
		}
	}
	
	// 윈도우 포커싱 해제 상태
	else
	{
		for ( int i = 0; i < (int)KEY::END_OF_ENUM_CLASS; ++i )
		{
			m_vecKey[ i ].bPrevPush = false;

			if ( KEY_STATE::TAP == m_vecKey[ i ].eKeyState || KEY_STATE::HOLD == m_vecKey[ i ].eKeyState )
			{
				m_vecKey[ i ].eKeyState = KEY_STATE::AWAY;
			}
			else if ( KEY_STATE::AWAY == m_vecKey[ i ].eKeyState )
			{
				m_vecKey[ i ].eKeyState = KEY_STATE::NONE;
			}
		}
	}
}