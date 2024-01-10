#include "pch.h"
#include "CTile.h"

#include "CTexture.h"

CTile::CTile( )
	: m_pTileTex{ nullptr }
	, m_idx{ 3 }
{
	SetScale( Vec2{ TILE_SIZE,TILE_SIZE } );
}

CTile::~CTile( )
{
}

void CTile::update( )
{

}

void CTile::render( HDC _dc )
{
	if ( m_pTileTex == nullptr || m_idx == -1 )
		return;

	UINT width = m_pTileTex->Width( );
	UINT height = m_pTileTex->Height( );

	UINT maxCol = width / TILE_SIZE;
	UINT maxRow = height / TILE_SIZE;

	UINT curRow = m_idx / maxCol;
	UINT curCol = m_idx / maxCol;

	// 이미지 범위를 벗어난 인덱스
	if ( maxRow <= curRow )
		assert( nullptr );

	Vec2 renderPos = CCamera::GetInst( )->GetRenderPos( GetPos( ) );
	Vec2 scale = GetScale( );

	Rectangle( _dc
		, (int)( renderPos.x )
		, (int)( renderPos.y )
		, (int)( renderPos.x + scale.x )
		, (int)( renderPos.y + scale.y ) );

	BitBlt( _dc
		, (int)( renderPos.x )
		, (int)( renderPos.y )
		, (int)( scale.x )
		, (int)( scale.y )
		, m_pTileTex->GetDC( )
		, curCol * TILE_SIZE
		, curRow * TILE_SIZE
		, SRCCOPY );
}
