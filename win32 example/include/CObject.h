#pragma once

#include "CCamera.h"

class CCollider;
class CAnimator;

class CObject
{
public:
	CObject( );
	CObject( const CObject& _origin );

	virtual ~CObject( );

	void SetPos( Vec2 _vPos ) { m_vPos = _vPos; }
	void SetScale( Vec2 _vScale ) { m_vScale = _vScale; }

	Vec2 GetPos( ) { return m_vPos; }
	Vec2 GetScale( ) { return m_vScale; }

	void SetName( const std::wstring& _name ) { name = _name; }
	const std::wstring& GetName( ) { return name; }

	void CreateCollider( );
	void CreateAnimator( );

	CCollider* GetCollider( ) { return m_pCollider; }
	CAnimator* GetAnimator( ) { return m_pAnimator; }

	bool IsDead( ) { return !m_bAlive; }

	virtual void OnCollision( CCollider* other ) { }
	virtual void OnCollisionEnter( CCollider* other ) { }
	virtual void OnCollisionExit( CCollider* other ) { }

private:
	void SetDead( ) { m_bAlive = false; }

public:
	virtual void update( ) = 0;
	virtual void finalupdate( ) final;
	virtual void render( HDC _dc );

	void component_render( HDC _dc );

	virtual CObject* Clone( ) = 0;

private:
	std::wstring name;

	Vec2 m_vPos;
	Vec2 m_vScale;

	CCollider* m_pCollider;
	CAnimator* m_pAnimator;

	bool m_bAlive;

	friend class CEventMgr;
};
