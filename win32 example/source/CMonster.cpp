#include "pch.h"
#include "CMonster.h"

#include "CTimeMgr.h"

CMonster::CMonster( )
	: m_vMonsterPos{ 0.f, 0.f }
	, m_fSpeed{ 200.f }
	, m_fMaxDistance{ 50.f }
	, m_iDir{ 1 }
{

}

CMonster::~CMonster( )
{

}

void CMonster::update( )
{
	Vec2 vMonCurPos = GetPos( );

	// ���� �������� �ʴ� m_fSpeed��ŭ �̵�
	vMonCurPos.x += fDT * m_fSpeed * m_iDir;

	// ��ȸ �Ÿ� ���ط��� �Ѿ���� Ȯ��
	float fDiff = abs( m_vMonsterPos.x - vMonCurPos.x ) - m_fMaxDistance;
	if ( 0.f < fDiff )
	{
		// ���� ����
		m_iDir *= -1;
		vMonCurPos.x += fDiff * m_iDir;
	}

	SetPos( vMonCurPos );
}
