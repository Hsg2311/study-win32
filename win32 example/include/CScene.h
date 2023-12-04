#pragma once

class CObject;

class CScene
{
public:
	CScene( );
	virtual ~CScene( );

	void SetName( const std::wstring& _SceneName ) { m_SceneName = _SceneName; }
	const std::wstring& GetName( ) { return m_SceneName; }

	virtual void Entry( ) = 0;	// 해당 Scene에 진입 시 호출
	virtual void Exit( ) = 0;	// 해당 Scene을 탈출 시 호출

	void update( );
	void render( HDC _dc );

public:
	// 멤버 함수를 헤더에 구현하면 inline 처리됨
	void AddObjcet( CObject* _pObj, GROUP_TYPE _eType )
	{ 
		m_arrObj[ (UINT)_eType ].push_back( _pObj );
	}

private:
	std::vector<CObject*> m_arrObj[ (UINT)GROUP_TYPE::END_OF_ENUM_CLASS ];	// 오브젝트를 저장 및 관리할 벡터를	그룹 개수만큼 선언
	std::wstring m_SceneName;
};
