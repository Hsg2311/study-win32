#pragma once

class CScene;

class CSceneMgr
{
	SINGLETON( CSceneMgr );

public:
	void init( );
	void update( );
	void render( HDC _dc );

private:
	CScene* m_arrScene[ (UINT)SCENE_TYPE::END_OF_ENUM_CLASS ];	// 모든 Scene 목록
	CScene* m_pCurScene;										// 현재 Scene
};
