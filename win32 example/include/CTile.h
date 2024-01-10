#pragma once
#include "CObject.h"

class CTexture;

class CTile : public CObject
{
public:
	CTile( );
	~CTile( );

private:
	virtual void update( );
	virtual void render( HDC _dc );

	CTile* Clone( ) { return new CTile{ *this }; }

public:
	void SetTexture( CTexture* _pTex ) { m_pTileTex = _pTex; }

private:
	CTexture* m_pTileTex;
	int m_idx;
};
