#pragma once

class CObject;

class CCollider
{
public:
	CCollider( );
	~CCollider( );

	CCollider( const CCollider& other );

	CCollider& operator=( const CCollider& other ) = delete;

public:
	void finalupdate( );
	void render( HDC _dc );

public:
	void SetOffsetPos( Vec2 _vPos ) { m_vOffsetPos = _vPos; }
	void setScale( Vec2 _vScale ) { m_vScale = _vScale; }

	Vec2 GetOffsetPos( ) { return m_vOffsetPos; }
	Vec2 GetScale( ) { return m_vScale; }

	Vec2 GetFinalPos( ) { return m_vFinalPos; }

	UINT GetID( ) { return m_ID; }

	// �浹 ���� �Լ�
	void OnCollision( CCollider* other );	// �浹 ���� ��� ȣ��Ǵ� �Լ�
	void OnCollisionEnter( CCollider* other );	// �浹 ���� ��
	void OnCollisionExit( CCollider* other );	// �浹 ���� ��

private:
	static UINT g_iNextID;

	CObject* m_pOwner;		// collider�� �����ϰ� �ִ� ������Ʈ
	Vec2 m_vOffsetPos;		// ������Ʈ�κ��� ������� ��ġ
	Vec2 m_vFinalPos;		// finalupdate���� �� �����Ӹ��� ���
	Vec2 m_vScale;			// �浹ü�� ũ��

	UINT m_ID;				// �浹ü ������ ID��
	UINT m_iColl;

	friend class CObject;
};
