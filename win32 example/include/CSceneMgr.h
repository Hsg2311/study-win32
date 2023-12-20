#pragma once

class CScene;

class CSceneMgr
{
	SINGLETON( CSceneMgr );

public:
	void init( );
	void update( );
	void render( HDC _dc );
	CScene* GetCurScene( ) { return m_pCurScene; }

private:
	CScene* m_arrScene[ (UINT)SCENE_TYPE::EOE ];	// 모든 Scene 목록
	CScene* m_pCurScene;										// 현재 Scene
};
