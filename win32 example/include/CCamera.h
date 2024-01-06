#pragma once

class CObject;

class CCamera
{
	SINGLETON( CCamera );

public:
	void update( );

	void SetLookAt( Vec2 _look )
	{ 
		m_LookAt = _look;

		float moveDist = ( m_LookAt - m_prevLookAt ).Length( );
		m_Speed = moveDist / m_Time;
		m_AccTime = 0.f;
	}
	void SetTarget( CObject* _pTarget ) { m_pTargetObj = _pTarget; }
	Vec2 GetLookAt( ) { return m_curLookAt; }
	Vec2 GetRenderPos( Vec2 _objPos ) { return _objPos - m_Diff; }
	Vec2 GetRealPos( Vec2 _renderPos ) { return _renderPos + m_Diff; }

private:
	void CalcDiff( );

private:
	Vec2 m_LookAt;			// ī�޶� ���� ��ġ
	Vec2 m_curLookAt;		// ���� ��ġ�� ���� ��ġ�� ������ ��ġ

	Vec2 m_prevLookAt;		// ī�޶� ���� ���� ������ ��ġ
	CObject* m_pTargetObj;	// ī�޶� Ÿ�� Object

	Vec2 m_Diff;			// �ػ� �߽� ��ġ�� ī�޶� LookAt ���� ���̰�

	float m_Time;			// ���콺 Ŭ���� ���� ī�޶� ���󰡴µ� �ɸ��� �ð�
	float m_Speed;			// ���콺 Ŭ���� ���� ���󰡴� ī�޶��� �ӷ�
	float m_AccTime;
};
