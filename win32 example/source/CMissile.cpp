#include "pch.h"
#include "CMissile.h"

#include "CTimeMgr.h"

CMissile::CMissile( )
	: m_fDir{ 1.f }
{
}

CMissile::~CMissile( )
{
}

void CMissile::update( )
{
	Vec2 vPos = GetPos( );

	vPos.y += fDT * 600.f * m_fDir;

	SetPos( vPos );
}

void CMissile::render( HDC _dc )
{
	Vec2 vMissilePos = GetPos( );
	Vec2 vMissileScale = GetScale( );

	Ellipse( _dc, (int)( vMissilePos.x - vMissileScale.x / 2.f ), (int)( vMissilePos.y - vMissileScale.y / 2.f ),
		(int)( vMissilePos.x + vMissileScale.x / 2.f ), (int)( vMissilePos.y + vMissileScale.y / 2.f ) );
}
