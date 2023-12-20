#include "pch.h"
#include "CCollisionMgr.h"

#include "CSceneMgr.h"
#include "CScene.h"
#include "CObject.h"
#include "CCollider.h"

CCollisionMgr::CCollisionMgr( )
	: m_arrCheck{ }
{

}

CCollisionMgr::~CCollisionMgr( )
{

}

void CCollisionMgr::update( )
{
	for ( UINT iRow = 0; iRow < (UINT)GROUP_TYPE::EOE; ++iRow )
	{
		for ( UINT iCol = iRow; iCol < (UINT)GROUP_TYPE::EOE; ++iCol )
		{
			if ( m_arrCheck[ iRow ] & ( 1 << iCol ) )
			{
				CollisionGroupUpdate( (GROUP_TYPE)iRow, (GROUP_TYPE)iCol );
			}
		}
	}
}

void CCollisionMgr::CheckGroup( GROUP_TYPE lhs, GROUP_TYPE rhs )
{
	// �� ���� ���� �׷� Ÿ���� ������,
	// ū ���� ��(��Ʈ)�� ���

	UINT iRow = (UINT)lhs;
	UINT iCol = (UINT)rhs;

	if ( iCol < iRow )
	{
		iRow = (UINT)rhs;
		iCol = (UINT)lhs;
	}

	if ( m_arrCheck[ iRow ] & ( 1 << iCol ) )
	{
		m_arrCheck[ iRow ] &= ~( 1 << iCol );
	}
	else
	{
		m_arrCheck[ iRow ] |= ( 1 << iCol );
	}
}

void CCollisionMgr::CollisionGroupUpdate( GROUP_TYPE lhs, GROUP_TYPE rhs )
{
	CScene* pCurScene = CSceneMgr::GetInst( )->GetCurScene( );

	const std::vector<CObject*>& vecLeft = pCurScene->GetGroupObject( lhs );
	const std::vector<CObject*>& vecRight = pCurScene->GetGroupObject( rhs );

	for ( size_t i = 0; i < vecLeft.size( ); ++i )
	{
		// �浹ü�� �������� ���� ���
		if ( vecLeft[ i ]->GetCollider( ) == nullptr )
		{
			continue;
		}

		for ( size_t j = 0; j < vecRight.size( ); ++j )
		{
			// �浹ü�� ���ų�, �ڱ� �ڽŰ��� �浹�� ���
			if ( vecRight[ j ]->GetCollider( ) == nullptr 
				|| vecLeft[ i ]->GetCollider( ) == vecRight[ j ]->GetCollider( ) )
			{
				continue;
			}

			if ( IsCollision( vecLeft[ i ]->GetCollider( ), vecRight[ j ]->GetCollider( ) ) )
			{

			}
			else
			{

			}
		}
	}
}

bool CCollisionMgr::IsCollision( CCollider* _pLeftColl, CCollider* _pRightColl )
{
	return false;
}
