#include "pch.h"
#include "CPlayer.h"

#include "CSceneMgr.h"
#include "CScene.h"

#include "CKeyMgr.h"
#include "CTimeMgr.h"

#include "CMissile.h"

#include "CPathMgr.h"
#include "CTexture.h"

CPlayer::CPlayer( )
	: m_pTex{ nullptr }
{
	// Texture 로딩하기
	m_pTex = new CTexture;

	std::wstring strFilePath = CPathMgr::GetInst( )->GetContentPath( );
	strFilePath += L"texture\\cuphead_idle_0001.bmp";
	m_pTex->Load( strFilePath );
}

CPlayer::~CPlayer( )
{
	if ( nullptr != m_pTex )
	{
		delete m_pTex;
	}
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
}

void CPlayer::render( HDC _dc )
{
	int iWidth = (int)m_pTex->Width( );
	int iHeight = (int)m_pTex->Height( );

	Vec2 vPos = GetPos( );

	//BitBlt( _dc
	//	, (int)( vPos.x - (float)( iWidth / 2 ) )
	//	, (int)( vPos.y - (float)( iHeight / 2 ) )
	//	, iWidth, iHeight
	//	, m_pTex->GetDC( )
	//	, 0, 0, SRCCOPY );

	TransparentBlt( _dc
		, (int)( vPos.x - (float)( iWidth / 2 ) )
		, (int)( vPos.y - (float)( iHeight / 2 ) )
		, iWidth, iHeight
		, m_pTex->GetDC( )
		, 0, 0, iWidth, iHeight
		, RGB( 255, 0, 255 ) );
}

void CPlayer::CreateMissile( )
{
	Vec2 vMissilePos = GetPos( );	// GetPos는 Player의 Pos
	vMissilePos.y -= GetScale( ).y / 2.f;

	CMissile* pMissileObj = new CMissile;
	pMissileObj->SetPos( vMissilePos );
	pMissileObj->SetScale( Vec2{ 25.f, 25.f } );
	//pMissileObj->SetDir( 0.f );
	pMissileObj->SetDir( Vec2{ 0.f, -1.f }  );

	CScene* pCurScene =  CSceneMgr::GetInst( )->GetCurScene( );
	pCurScene->AddObjcet( pMissileObj, GROUP_TYPE::DEFAULT );
}
