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

public:
	virtual void update( );
	virtual void render( HDC _dc );

private:
	float m_fTheta;	// �̵� ����(����), ȣ����(���� ���)
	Vec2 m_vDir;	// Missile ��ü�� �߽����� ��ü�� ������ ��Ÿ���� ���� �������ν� ���
					// ��ü�� ��ġ�� (0, 0)�̴�.
};
