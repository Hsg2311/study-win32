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

	// 충돌 시점 함수
	void OnCollision( CCollider* other );	// 충돌 중인 경우 호출되는 함수
	void OnCollisionEnter( CCollider* other );	// 충돌 진입 시
	void OnCollisionExit( CCollider* other );	// 충돌 해제 시

private:
	static UINT g_iNextID;

	CObject* m_pOwner;		// collider를 소유하고 있는 오브젝트
	Vec2 m_vOffsetPos;		// 오브젝트로부터 상대적인 위치
	Vec2 m_vFinalPos;		// finalupdate에서 매 프레임마다 계산
	Vec2 m_vScale;			// 충돌체의 크기

	UINT m_ID;				// 충돌체 고유한 ID값
	UINT m_iColl;

	friend class CObject;
};
