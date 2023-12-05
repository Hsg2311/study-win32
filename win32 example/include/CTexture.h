#pragma once
#include "CRes.h"

class CTexture : public CRes
{
public:
	CTexture( );
	~CTexture( );

private:
	HDC m_dc;
	HBITMAP m_hBit;
};
