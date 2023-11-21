#pragma once

class CTimeMgr
{
	SINGLETON( CTimeMgr );

public:
	void init( );
	void update( );
	double GetDT( ) { return m_dDT; }
	float GetfDT( ) { return (float)m_dDT; }

private:
	LARGE_INTEGER m_PrevCount;
	LARGE_INTEGER m_CurCount;
	LARGE_INTEGER m_Frequency;

	double m_dDT;			// 프레임 간의 시간값 (Delta Time : 1프레임당 시간)
	double m_dAcc;			// 1초 체크를 위한 DT 누적 시간
	UINT m_iCallCount;		// 함수 호출 횟수
	UINT m_iFPS;			// 초당 호출 횟수
};
