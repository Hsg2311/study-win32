#pragma once
#include "CObject.h"

class CMissile : public CObject
{
public:
	CMissile( );
	~CMissile( );

	void SetDir( bool _bUp )
	{
		if ( _bUp )
		{
			m_fDir = -1.f;
		}
		else
		{
			m_fDir = 1.f;
		}
	}

public:
	virtual void update( );
	virtual void render( HDC _dc );

private:
	float m_fDir;	// 위, 아래 방향
};
