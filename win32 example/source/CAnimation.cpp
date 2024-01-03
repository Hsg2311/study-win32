#include "pch.h"
#include "CAnimation.h"

#include "CAnimator.h"
#include "CTexture.h"

CAnimation::CAnimation( )
	: m_pAnimator{ nullptr }
	, m_pTex{ nullptr }
{
}

CAnimation::~CAnimation( )
{
}

void CAnimation::update( )
{
}

void CAnimation::render( HDC _dc )
{
}

void CAnimation::Create( CTexture* _pTex, Vec2 _LT, Vec2 _sliceSize, Vec2 _step, float _duration, UINT _frameCount )
{
	m_pTex = _pTex;

	tAnimFrm frm{ };
	for ( UINT i = 0; i < _frameCount; ++i )
	{
		frm.duration = _duration;
		frm.slice = _sliceSize;
		frm.LT = _LT + _step * i;

		m_vecFrm.push_back( frm );
	}
}
