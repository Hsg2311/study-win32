#pragma once

class CObject;

class CScene
{
public:
	CScene( );
	virtual ~CScene( );

	void SetName( const std::wstring& _SceneName ) { m_SceneName = _SceneName; }
	const std::wstring& GetName( ) { return m_SceneName; }

	virtual void Entry( ) = 0;	// �ش� Scene�� ���� �� ȣ��
	virtual void Exit( ) = 0;	// �ش� Scene�� Ż�� �� ȣ��

	void update( );
	void render( HDC _dc );

public:
	// ��� �Լ��� ����� �����ϸ� inline ó����
	void AddObjcet( CObject* _pObj, GROUP_TYPE _eType )
	{ 
		m_arrObj[ (UINT)_eType ].push_back( _pObj );
	}

private:
	std::vector<CObject*> m_arrObj[ (UINT)GROUP_TYPE::END_OF_ENUM_CLASS ];	// ������Ʈ�� ���� �� ������ ���͸�	�׷� ������ŭ ����
	std::wstring m_SceneName;
};
