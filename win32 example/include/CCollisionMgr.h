#pragma once

class CCollisionMgr
{
	SINGLETON( CCollisionMgr );

public:
	void update( );
	void CheckGroup( GROUP_TYPE lhs, GROUP_TYPE rhs );
	void Reset( ) { memset( m_arrCheck, 0, sizeof( UINT ) * (UINT)GROUP_TYPE::END_OF_ENUM_CLASS ); }

private:
	UINT m_arrCheck[ (UINT)GROUP_TYPE::END_OF_ENUM_CLASS ];
};
