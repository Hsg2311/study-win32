#include "pch.h"
#include "CAnimation.h"

#include "CTimeMgr.h"

#include "CAnimator.h"
#include "CTexture.h"
#include "CObject.h"
#include "CCamera.h"

CAnimation::CAnimation( )
	: m_pAnimator{ nullptr }
	, m_pTex{ nullptr }
	, m_curFrm{ 0 }
	, m_AccTime{ 0.f }
	, m_finish{ false }
{
}

CAnimation::~CAnimation( )
{
}

void CAnimation::update( )
{
	if ( m_finish )
		return;

	m_AccTime += fDT;

	if ( m_vecFrm[ m_curFrm ].duration < m_AccTime )
	{
		++m_curFrm;

		if ( m_curFrm >= m_vecFrm.size( ) )
		{
			m_curFrm = -1;
			m_finish = true;
			m_AccTime = 0.f;
			return;
		}

		m_AccTime -= m_vecFrm[ m_curFrm ].duration;
	}
}

void CAnimation::render( HDC _dc )
{
	if ( m_finish )
		return;

	CObject* pObj = m_pAnimator->GetObj( );
	Vec2 objPos = pObj->GetPos( );
	objPos += m_vecFrm[ m_curFrm ].offset;	// Object Position에 offset만큼 추가로 이동한 위치

	objPos = CCamera::GetInst( )->GetRenderPos( objPos );
	
	TransparentBlt( _dc
		, (int)( objPos.x + m_vecFrm[ m_curFrm ].offset.x - m_vecFrm[ m_curFrm ].slice.x / 2.f )
		, (int)( objPos.y + m_vecFrm[ m_curFrm ].offset.y - m_vecFrm[ m_curFrm ].slice.y / 2.f )
		, (int)( m_vecFrm[ m_curFrm ].slice.x )
		, (int)( m_vecFrm[ m_curFrm ].slice.y )
		, m_pTex->GetDC( )
		, (int)( m_vecFrm[ m_curFrm ].LT.x )
		, (int)( m_vecFrm[ m_curFrm ].LT.y )
		, (int)( m_vecFrm[ m_curFrm ].slice.x )
		, (int)( m_vecFrm[ m_curFrm ].slice.y )
		, RGB( 255, 255, 255 )
	);
}

void CAnimation::Create( CTexture* _pTex, Vec2 _LT, Vec2 _sliceSize, Vec2 _step, float _duration, UINT _frameCount )
{
	m_pTex = _pTex;

	tAnimFrm frm{ };
	for ( int i = 0; i < _frameCount; ++i )
	{
		frm.duration = _duration;
		frm.slice = _sliceSize;
		frm.LT = _LT + _step * i;

		m_vecFrm.push_back( frm );
	}
}
