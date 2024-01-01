#pragma once
#include "CObject.h"

class CMissile : public CObject
{
public:
	CMissile( );
	~CMissile( );

	void SetDir( float _fTheta ) { m_fTheta = _fTheta; }
	void SetDir( Vec2 _vDir )
	{ 
		m_vDir = _vDir;
		m_vDir.Nomalize( );
	}

	CMissile* Clone( ) { return new CMissile{ *this }; }

public:
	virtual void update( );
	virtual void render( HDC _dc );

public:
	virtual void OnCollisionEnter( CCollider* other );

private:
	float m_fTheta;	// 이동 방향(각도), 호도법(라디안 방식)
	Vec2 m_vDir;	// Missile 객체를 중심으로 객체의 방향을 나타내는 벡터 성분으로써 사용
					// 객체의 위치가 (0, 0)이다.
};
