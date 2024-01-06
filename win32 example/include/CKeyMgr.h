#pragma once

// 1. 프레임 동기화
// 동일 프레임 내에서 같은 키에 대해, 동일한 이벤트를 가져간다.

// 2. 키 입력 이벤트 처리
// tap, hold, away - 키의 상태값을 부여한다.

enum class KEY_STATE
{
	NONE,	// 눌리지 않았고, 이전에도 눌리지 않은 상태
	TAP,	// 막 누른 시점
	HOLD,	// 누르고 있는
	AWAY,	// 막 뗀 시점
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
	KEY_STATE	eKeyState;	// 키의 상태값
	bool		bPrevPush;	// 이전 프레임에서 눌렸는지 여부
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
