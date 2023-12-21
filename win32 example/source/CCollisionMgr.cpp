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
	// 더 작은 값의 그룹 타입을 행으로,
	// 큰 값을 열(비트)로 사용

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

	std::map<ULONGLONG, bool>::iterator iter;

	for ( size_t i = 0; i < vecLeft.size( ); ++i )
	{
		// 충돌체를 보유하지 않은 경우
		if ( vecLeft[ i ]->GetCollider( ) == nullptr )
		{
			continue;
		}

		for ( size_t j = 0; j < vecRight.size( ); ++j )
		{
			// 충돌체가 없거나, 자기 자신과의 충돌인 경우
			if ( vecRight[ j ]->GetCollider( ) == nullptr 
				|| vecLeft[ i ]->GetCollider( ) == vecRight[ j ]->GetCollider( ) )
			{
				continue;
			}

			CCollider* pLeftColl = vecLeft[ i ]->GetCollider( );
			CCollider* pRightColl = vecRight[ j ]->GetCollider( );
			
			// 두 충돌체 조합 아이디 생성
			COLLIDER_ID combi;
			combi.Left_ID = pLeftColl->GetID( );
			combi.Right_ID = pRightColl->GetID( );

			iter = m_mapCollInfo.find( combi.ID );

			// 충돌 정보가 미등록 상태인 경우 등록(충돌 여부:false)
			if ( iter == m_mapCollInfo.end( ) )
			{
				m_mapCollInfo.insert( std::make_pair( combi.ID, false ) );
				iter = m_mapCollInfo.find( combi.ID );
			}


			if ( IsCollision( pLeftColl, pRightColl ) )
			{
				// 현재 충돌 중이다.

				if ( iter->second )
				{
					// 이전에도 충돌하고 있었다.
					pLeftColl->OnCollision( pRightColl );
					pRightColl->OnCollision( pLeftColl );
				}
				else
				{
					// 이제 막 충돌했다.
					pLeftColl->OnCollisionEnter( pRightColl );
					pRightColl->OnCollisionEnter( pLeftColl );
					iter->second = true;
				}
			}
			else
			{
				// 현재 충돌하고 있지 않다.

				if ( iter->second )
				{
					// 이전에는 충돌하고 있었다.
					pLeftColl->OnCollisionExit( pRightColl );
					pRightColl->OnCollisionExit( pLeftColl );
					iter->second = false;
				}
			}
		}
	}
}

bool CCollisionMgr::IsCollision( CCollider* _pLeftColl, CCollider* _pRightColl )
{
	Vec2 vLeftPos = _pLeftColl->GetFinalPos( );
	Vec2 vLeftScale = _pLeftColl->GetScale( );

	Vec2 vRightPos = _pRightColl->GetFinalPos( );
	Vec2 vRightScale = _pRightColl->GetScale( );

	if ( abs( vLeftPos.x - vRightPos.x  ) < ( vLeftScale.x + vRightScale.x ) / 2.f
		&& abs( vLeftPos.y - vRightPos.y ) < ( vLeftScale.y + vRightScale.y ) / 2.f )
	{
		return true;
	}

	return false;
}
