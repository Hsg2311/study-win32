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
	CScene* m_arrScene[ (UINT)SCENE_TYPE::EOE ];	// ��� Scene ���
	CScene* m_pCurScene;										// ���� Scene
};
