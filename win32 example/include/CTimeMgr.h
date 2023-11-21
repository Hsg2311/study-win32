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

	double m_dDT;			// ������ ���� �ð��� (Delta Time : 1�����Ӵ� �ð�)
	double m_dAcc;			// 1�� üũ�� ���� DT ���� �ð�
	UINT m_iCallCount;		// �Լ� ȣ�� Ƚ��
	UINT m_iFPS;			// �ʴ� ȣ�� Ƚ��
};
