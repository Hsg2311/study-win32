#include "pch.h"
#include "CMissile.h"

#include "CTimeMgr.h"

CMissile::CMissile( )
	: m_fTheta{ M_PI_2 }
	, m_vDir{ 1.f, 1.f }
{
}

CMissile::~CMissile( )
{
}

void CMissile::update( )
{
	Vec2 vPos = GetPos( );

	//vPos.x += ( 600.f * cosf( m_fTheta ) ) * fDT;
	//vPos.y -= ( 600.f * sinf( m_fTheta ) ) * fDT;

	vPos.x += ( 600.f * m_vDir.x ) * fDT;
	vPos.y += ( 600.f * m_vDir.y ) * fDT;

	SetPos( vPos );
}

void CMissile::render( HDC _dc )
{
	Vec2 vMissilePos = GetPos( );
	Vec2 vMissileScale = GetScale( );

	Ellipse( _dc, (int)( vMissilePos.x - vMissileScale.x / 2.f ), (int)( vMissilePos.y - vMissileScale.y / 2.f ),
		(int)( vMissilePos.x + vMissileScale.x / 2.f ), (int)( vMissilePos.y + vMissileScale.y / 2.f ) );
}
