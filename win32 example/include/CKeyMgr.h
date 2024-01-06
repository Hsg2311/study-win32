#pragma once

// 1. ������ ����ȭ
// ���� ������ ������ ���� Ű�� ����, ������ �̺�Ʈ�� ��������.

// 2. Ű �Է� �̺�Ʈ ó��
// tap, hold, away - Ű�� ���°��� �ο��Ѵ�.

enum class KEY_STATE
{
	NONE,	// ������ �ʾҰ�, �������� ������ ���� ����
	TAP,	// �� ���� ����
	HOLD,	// ������ �ִ�
	AWAY,	// �� �� ����
};

enum class KEY
{
	LEFT,
	RIGHT,
	UP,
	DOWN,

	Q,
	W,
	E,
	R,
	T,
	Y,
	U,
	I,
	O,
	P,
	A,
	S,
	D,
	F,
	G,
	H,
	J,
	K,
	L,
	Z,
	X,
	C,
	V,
	B,
	N,
	M,

	ALT,
	CTRL,
	LSHIFT,
	SPACE,
	ENTER,
	ESC,

	LBTN,
	RBTN,

	END_OF_ENUM_CLASS,
};

struct tKeyInfo
{
	KEY_STATE	eKeyState;	// Ű�� ���°�
	bool		bPrevPush;	// ���� �����ӿ��� ���ȴ��� ����
};

class CKeyMgr
{
	SINGLETON( CKeyMgr );

public:
	void init( );
	void update( );

	KEY_STATE GetKeyState( KEY _eKey ) { return m_vecKey[ (UINT)_eKey ].eKeyState; }
	Vec2 GetMousePos( ) { return m_CurMousePos; }

private:
	std::vector<tKeyInfo> m_vecKey;
	Vec2 m_CurMousePos;
};
