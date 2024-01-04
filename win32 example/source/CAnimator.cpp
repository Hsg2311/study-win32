#include "pch.h"
#include "CAnimator.h"

#include "CAnimation.h"

CAnimator::CAnimator( )
	: m_pCurAnim{ nullptr }
	, m_pOwner{ nullptr }
	, m_repeat{ false }
{
}

CAnimator::~CAnimator( )
{
	Safe_Delete_Map( m_mapAnim );
}

void CAnimator::update( )
{
	if ( m_pCurAnim != nullptr )
	{
		m_pCurAnim->update( );

		if ( m_repeat && m_pCurAnim->IsFinish( ) )
		{
			m_pCurAnim->SetFrame( 0 );
		}
	}
}

void CAnimator::render( HDC _dc )
{
	if ( m_pCurAnim != nullptr )
	{
		m_pCurAnim->render( _dc );
	}
}

void CAnimator::CreateAnimation( const std::wstring& _name, CTexture* _pTex, Vec2 _LT, 
								Vec2 _sliceSize, Vec2 _step, float _duration, UINT _frameCount )
{
	CAnimation* pAnim = FindAnimation( _name );
	assert( pAnim == nullptr );
		
	pAnim = new CAnimation;

	pAnim->SetName( _name );
	pAnim->m_pAnimator = this;
	pAnim->Create( _pTex, _LT, _sliceSize, _step, _duration, _frameCount );

	m_mapAnim.insert( std::make_pair( _name, pAnim ) );
}

CAnimation* CAnimator::FindAnimation( const std::wstring& _name )
{
	std::map<std::wstring, CAnimation*>::iterator iter = m_mapAnim.find( _name );

	if ( iter == m_mapAnim.end( ) )
	{
		return nullptr;
	}

	return iter->second;
}

void CAnimator::Play( const std::wstring& _name, bool _repeat )
{
	m_pCurAnim = FindAnimation( _name );
	m_repeat = _repeat;
}
