#include "pch.h"
#include "CSceneMgr.h"

#include "CScene_Start.h"

CSceneMgr::CSceneMgr( )
	: m_arrScene{ }
	, m_pCurScene{ nullptr }
{

}

CSceneMgr::~CSceneMgr( )
{
	// Scene 전부 삭제
	for ( UINT i = 0; i < (UINT)SCENE_TYPE::EOE; ++i )
	{
		if ( nullptr != m_arrScene[ i ] )
		{
			delete m_arrScene[ i ];
		}
	}
}

void CSceneMgr::init( )
{
	// Scene 생성
	m_arrScene[ (UINT)SCENE_TYPE::START ] = new CScene_Start;
	m_arrScene[ (UINT)SCENE_TYPE::START ]->SetName( L"Start Scene" );

	// 현재 Scene 지정
	m_pCurScene = m_arrScene[ (UINT)SCENE_TYPE::START ];
	m_pCurScene->Entry( );
}

void CSceneMgr::update( )
{
	m_pCurScene->update( );
	m_pCurScene->finalupdate( );
}

void CSceneMgr::render( HDC _dc )
{
	m_pCurScene->render( _dc );
}
