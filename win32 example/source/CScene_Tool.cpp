#include "pch.h"
#include "CScene_Tool.h"

#include "CKeyMgr.h"
#include "CTile.h"

#include "CCore.h"
#include "CResMgr.h"

CScene_Tool::CScene_Tool( )
{
}

CScene_Tool::~CScene_Tool( )
{
}

void CScene_Tool::Entry( )
{
	CTexture* pTileTex = CResMgr::GetInst( )->LoadTexture( L"Tile", L"texture\\tile\\TILE.bmp" );

	// 타일 생성
	for ( int i = 0; i < 5; ++i )
	{
		for ( int j = 0; j < 5; ++j )
		{
			CTile* pTile = new CTile{ };

			pTile->SetPos( Vec2{ (int)( j * TILE_SIZE ), (int)( i * TILE_SIZE ) } );
			pTile->SetTexture( pTileTex );

			AddObjcet( pTile, GROUP_TYPE::TILE );
		}
	}

	// Camera Look 지정
	Vec2 vResolution = CCore::GetInst( )->GetResolution( );
	CCamera::GetInst( )->SetLookAt( vResolution / 2.f );
}

void CScene_Tool::Exit( )
{
}

void CScene_Tool::update( )
{
	CScene::update( );
}
