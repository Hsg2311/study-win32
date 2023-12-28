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

	virtual void update( );
	virtual void finalupdate( );
	virtual void render( HDC _dc );

public:
	// ��� �Լ��� ����� �����ϸ� inline ó����
	void AddObjcet( CObject* _pObj, GROUP_TYPE _eType )
	{ 
		m_arrObj[ (UINT)_eType ].push_back( _pObj );
	}

	const std::vector<CObject*>& GetGroupObject( GROUP_TYPE _eType )
	{
		return m_arrObj[ (UINT)_eType ];
	}

	void DeleteGroup( GROUP_TYPE _eTarget );
	void DeleteAll( );

private:
	std::vector<CObject*> m_arrObj[ (UINT)GROUP_TYPE::EOE ];	// ������Ʈ�� ���� �� ������ ���͸�	�׷� ������ŭ ����
	std::wstring m_SceneName;
};
