#include "pch.h"
#include "CCollider.h"

#include "CObject.h"

#include "CCore.h"

UINT CCollider::g_iNextID = 0;

CCollider::CCollider( )
	: m_pOwner{ nullptr }
	, m_ID{ g_iNextID++ }
	, m_iColl{ 0 }
{
}

CCollider::~CCollider( )
{
}

CCollider::CCollider( const CCollider& other )
	: m_pOwner{ nullptr }
	, m_vOffsetPos{ other.m_vOffsetPos }
	, m_vScale{ other.m_vScale }
	, m_ID{ g_iNextID++ }
	, m_iColl{ 0 }
{
}

void CCollider::finalupdate( )
{
	// Object의 위치를 따라간다.
	Vec2 vObjectPos =  m_pOwner->GetPos( );
	m_vFinalPos = vObjectPos + m_vOffsetPos;

	assert( 0 <= m_iColl );
}

void CCollider::render( HDC _dc )
{
	HPEN ePen = CCore::GetInst( )->GetPen( PEN_TYPE::GREEN );

	if ( m_iColl )
	{
		ePen = CCore::GetInst( )->GetPen( PEN_TYPE::RED );
	}

	HPEN hDefaultPen = (HPEN)SelectObject( _dc, ePen );

	HBRUSH hHollowBrush = CCore::GetInst( )->GetBrush( BRUSH_TYPE::HOLLOW );
	HBRUSH hDefaultBrush = (HBRUSH)SelectObject( _dc, hHollowBrush );

	Rectangle( _dc
		, (int)( m_vFinalPos.x - m_vScale.x / 2.f )
		, (int)( m_vFinalPos.y - m_vScale.y / 2.f )
		, (int)( m_vFinalPos.x + m_vScale.x / 2.f )
		, (int)( m_vFinalPos.y + m_vScale.y / 2.f ) );

	SelectObject( _dc, hDefaultPen );
	SelectObject( _dc, hDefaultBrush );
}

void CCollider::OnCollision( CCollider* other )
{
}

void CCollider::OnCollisionEnter( CCollider* other )
{
	++m_iColl;
}

void CCollider::OnCollisionExit( CCollider* other )
{
	--m_iColl;
}
