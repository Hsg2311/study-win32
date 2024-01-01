#pragma once
#include "CObject.h"

class CMonster : public CObject
{
public:
	CMonster( );
	~CMonster( );

	void SetSpeed( float _f ) { m_fSpeed = _f; }
	float GetSpeed( ) { return m_fSpeed; }
	void SetDistance( float _f ) { m_fMaxDistance = _f; }
	void SetMonsterPos( Vec2 _vPos ) { m_vMonsterPos = _vPos; }

	virtual void OnCollisionEnter( CCollider* other );

	CMonster* Clone( ) { return new CMonster{ *this }; }

public:
	virtual void update( );

private:
	Vec2 m_vMonsterPos;
	float m_fSpeed;
	float m_fMaxDistance;
	int m_iDir;	// 1 오른쪽, -1 왼쪽 이동
};
