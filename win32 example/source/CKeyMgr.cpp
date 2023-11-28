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
	// - ������ ��Ŀ�� �˾Ƴ��� -
	// GetFocus�Լ��� ����ڰ� �����Ų ���α׷��� ������ �� ��� ���̶� ��Ŀ�� �Ǿ�������,
	// �� �������� HWND�� ��ȯ�� �ְ�, �׷��� �ʴٸ� nullptr�� ��ȯ�� �ش�.
	//
	// ���� ���� �������� ��Ŀ�̿� ���ؼ��� �˾Ƴ��� �ʹٸ�,
	// CCore.h�� include�� ��, GetMainHWND�Լ��� ���� ���� ������ �ڵ��� ���´�.
	// �׷��� ���� GetFocus�Լ��� ���� HWND�� ���� ���� �����찡 ��Ŀ�� �Ǿ��ִ��� Ȯ���ϸ� �ȴ�.

	HWND hWnd = GetFocus( );

	// ������ ��Ŀ�� ���� ��, Ű �̺�Ʈ ����
	if ( nullptr != hWnd )
	{
		for ( int i = 0; i < (int)KEY::END_OF_ENUM_CLASS; ++i )
		{
			// Ű�� �����ִ�.
			if ( GetAsyncKeyState( g_arrVK[ i ] ) & 0x8000 )
			{
				if ( m_vecKey[ i ].bPrevPush )
				{
					// �������� �����־���.
					m_vecKey[ i ].eKeyState = KEY_STATE::HOLD;
				}
				else
				{
					// �������� �� �����־���.
					m_vecKey[ i ].eKeyState = KEY_STATE::TAP;
				}

				m_vecKey[ i ].bPrevPush = true;
			}

			// Ű�� �� �����ִ�.
			else
			{
				if ( m_vecKey[ i ].bPrevPush )
				{
					// �������� �����־���.
					m_vecKey[ i ].eKeyState = KEY_STATE::AWAY;
				}
				else
				{
					// �������� �� �����־���.
					m_vecKey[ i ].eKeyState = KEY_STATE::NONE;
				}

				m_vecKey[ i ].bPrevPush = false;
			}
		}
	}
	
	// ������ ��Ŀ�� ���� ����
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