#pragma once

class CPathMgr
{
	SINGLETON( CPathMgr );

public:
	void init( );
	const wchar_t* GetContentPath( ) { return m_szContentPath; }

private:
	wchar_t m_szContentPath[ 255 ];
};
