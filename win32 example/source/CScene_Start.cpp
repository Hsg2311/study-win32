#include "pch.h"
#include "CScene_Start.h"

#include "CObject.h"
#include "CPlayer.h"
#include "CMonster.h"

#include "CCore.h"

void CScene_Start::Entry( )
{
	// Object 추가
	CObject* pObj = new CPlayer;
	pObj->SetPos( Vec2{ 640.f, 384.f } );
	pObj->SetScale( Vec2{ 100.f, 100.f } );
	AddObjcet( pObj, GROUP_TYPE::DEFAULT );

	// Monster Object 추가
	int iMonCount = 10;
	float fMoveDist = 50.f;
	float ObjScale = 50.f;

	Vec2 vResolution = CCore::GetInst( )->GetResolution( );
	float fTerm = ( vResolution.x - (( fMoveDist + ObjScale / 2.f ) * 2.f )) / (float)( iMonCount - 1 );

	CMonster* pMonsterObj = nullptr;

	for ( int i = 0; i < iMonCount; ++i )
	{
		pMonsterObj = new CMonster;
		pMonsterObj->SetPos( Vec2{ ( fMoveDist + ObjScale / 2.f ) + (float)i * fTerm, 50.f } );
		pMonsterObj->SetMonsterPos( pMonsterObj->GetPos( ) );
		pMonsterObj->SetDistance( fMoveDist );
		pMonsterObj->SetScale( Vec2{ ObjScale, ObjScale } );
		AddObjcet( pMonsterObj, GROUP_TYPE::DEFAULT );
	}
}

void CScene_Start::Exit( )
{

}
