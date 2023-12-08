#pragma once
#include "CRes.h"

class CTexture : public CRes
{
public:
	CTexture( );
	~CTexture( );

	void Load( const std::wstring& _strFilePath );

private:
	HDC m_dc;
	HBITMAP m_hBit;
};
