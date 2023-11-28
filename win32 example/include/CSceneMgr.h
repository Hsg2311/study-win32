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
	CScene* m_arrScene[ (UINT)SCENE_TYPE::END_OF_ENUM_CLASS ];	// ��� Scene ���
	CScene* m_pCurScene;										// ���� Scene
};
