#include "pch.h"
#include "CPlayer.h"

#include "CSceneMgr.h"
#include "CScene.h"

#include "CKeyMgr.h"
#include "CTimeMgr.h"

#include "CMissile.h"

#include "CResMgr.h"
#include "CTexture.h"
#include "CCollider.h"
#include "CAnimator.h"
#include "CAnimation.h"

CPlayer::CPlayer( )
{
	// Texture 로딩하기
	//m_pTex = CResMgr::GetInst( )->LoadTexture( L"PlayerTexture", L"texture\\idle\\cuphead_idle_0001.bmp" );

	CreateCollider( );
	GetCollider( )->SetOffsetPos( Vec2{ 0.f, 0.f } );
	GetCollider( )->setScale( Vec2{ 70.f, 100.f } );

	// Texture 로딩하기
	CTexture* m_pTex = CResMgr::GetInst( )->LoadTexture( L"PlayerTexture", L"texture\\idle\\cuphead_idle_v2.bmp" );
	CreateAnimator( );
	GetAnimator( )->CreateAnimation( L"Idle", m_pTex, Vec2{ 0.f, 0.f }, Vec2{ 100.f, 155.f }, Vec2{ 100.f, 0.f }, 0.07f, 8 );
	GetAnimator( )->Play( L"Idle", true );

	CAnimation* pAnim = GetAnimator( )->FindAnimation( L"Idle" );
	for ( int i = 0; i < pAnim->GetMaxFrame( ); ++i )
	{
		pAnim->GetFrame( i ).offset = Vec2{ 0.f, -30.f };
	}
}

CPlayer::~CPlayer( )
{

}

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

	GetAnimator( )->update( );
}

void CPlayer::render( HDC _dc )
{
	// 컴포넌트(충돌체, etc...)가 있는 경우 렌더
	component_render( _dc );
}

void CPlayer::CreateMissile( )
{
	Vec2 vMissilePos = GetPos( );	// GetPos는 Player의 Pos
	vMissilePos.y -= GetScale( ).y / 2.f;

	CMissile* pMissileObj = new CMissile;
	pMissileObj->SetName( L"Projectile_P" );
	pMissileObj->SetPos( vMissilePos );
	pMissileObj->SetScale( Vec2{ 25.f, 25.f } );
	//pMissileObj->SetDir( 0.f );
	pMissileObj->SetDir( Vec2{ 0.f, -1.f }  );

	CreateObject( pMissileObj, GROUP_TYPE::PROJECTILE_P );
}
