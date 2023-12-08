#pragma once

class CTexture;

class CResMgr
{
	SINGLETON( CResMgr );

public:
	CTexture* LoadTexture( const std::wstring& _strKey, const std::wstring& _strRelativePath );
	CTexture* FindTexture( const std::wstring& _strKey );

private:
	std::map<std::wstring, CTexture*> m_mapTex;
};
