#pragma once

class CCollider;

union COLLIDER_ID
{
	struct
	{
		UINT Left_ID;
		UINT Right_ID;
	};
	ULONGLONG ID;
};

class CCollisionMgr
{
	SINGLETON( CCollisionMgr );

public:
	void update( );
	void CheckGroup( GROUP_TYPE lhs, GROUP_TYPE rhs );
	void Reset( ) { memset( m_arrCheck, 0, sizeof( UINT ) * (UINT)GROUP_TYPE::EOE ); }

private:
	void CollisionGroupUpdate( GROUP_TYPE lhs, GROUP_TYPE rhs );
	bool IsCollision( CCollider* _pLeftColl, CCollider* _pRightColl );

private:
	std::map<ULONGLONG, bool> m_mapCollInfo;		// 충돌체 간의 이전 프레임 충돌 정보
	UINT m_arrCheck[ (UINT)GROUP_TYPE::EOE ];	// 그룹 간의 충돌 체크 매트릭스
};
