#pragma once

class CColider;

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
	// TODO : �浹ü ���� ���� ������ �浹 ���� ���
	UINT m_arrCheck[ (UINT)GROUP_TYPE::EOE ];	// �׷� ���� �浹 üũ ��Ʈ����
};
