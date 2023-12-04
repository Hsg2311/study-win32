#include "pch.h"
#include "CPlayer.h"

#include "CSceneMgr.h"
#include "CScene.h"

#include "CKeyMgr.h"
#include "CTimeMgr.h"

#include "CMissile.h"

void CPlayer::update( )
{
	Vec2 vPos = GetPos( );

	if ( KEY_HOLD( KEY::LEFT ) )
	{
		vPos.x -= 300.f * fDT;
	}
	if ( KEY_HOLD( KEY::RIGHT ) )
	{
		vPos.x += 300.f * fDT;
	}
	if ( KEY_HOLD( KEY::UP ) )
	{
		vPos.y -= 300.f * fDT;
	}
	if ( KEY_HOLD( KEY::DOWN ) )
	{
		vPos.y += 300.f * fDT;
	}
	if ( KEY_TAP( KEY::Z ) )
	{
		CreateMissile( );
	}

	SetPos( vPos );
}

void CPlayer::CreateMissile( )
{
	Vec2 vMissilePos = GetPos( );	// GetPos´Â PlayerÀÇ Pos
	vMissilePos.y -= GetScale( ).y / 2.f;

	CMissile* pMissileObj = new CMissile;
	pMissileObj->SetPos( vMissilePos );
	pMissileObj->SetScale( Vec2{ 25.f, 25.f } );
	//pMissileObj->SetDir( 0.f );
	pMissileObj->SetDir( Vec2{ -1.f, -7.f }  );

	CScene* pCurScene =  CSceneMgr::GetInst( )->GetCurScene( );
	pCurScene->AddObjcet( pMissileObj, GROUP_TYPE::DEFAULT );
}
