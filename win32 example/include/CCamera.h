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
	Vec2 m_LookAt;			// 카메라가 보는 위치
	Vec2 m_curLookAt;		// 이전 위치와 현재 위치를 보정한 위치

	Vec2 m_prevLookAt;		// 카메라가 보는 이전 프레임 위치
	CObject* m_pTargetObj;	// 카메라 타겟 Object

	Vec2 m_Diff;			// 해상도 중심 위치와 카메라 LookAt 간의 차이값

	float m_Time;			// 마우스 클릭한 곳을 카메라가 따라가는데 걸리는 시간
	float m_Speed;			// 마우스 클릭한 곳을 따라가는 카메라의 속력
	float m_AccTime;
};
