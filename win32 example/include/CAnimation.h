#pragma once

class CAnimator;
class CTexture;

struct tAnimFrm
{
	Vec2 LT;
	Vec2 slice;
	Vec2 offset;
	float duration;
};

class CAnimation
{
public:
	CAnimation( );
	~CAnimation( );

	void update( );
	void render( HDC _dc );
	void Create( CTexture* _pTex, Vec2 _LT, Vec2 _sliceSize, Vec2 _step, float _duration, UINT _frameCount );

	const std::wstring& GetName( ) { return m_Name; }
	bool IsFinish( ) { return m_finish; }
	void SetFrame( int _frameIdx )
	{
		m_finish = false;
		m_curFrm = _frameIdx;
		m_AccTime = 0.f;
	}

	tAnimFrm& GetFrame( int _idx ) { return m_vecFrm[ _idx ]; }
	UINT GetMaxFrame( ) { return (UINT)m_vecFrm.size( ); }


private:
	void SetName( const std::wstring& _name ) { m_Name = _name; }

private:
	std::wstring m_Name;
	CAnimator* m_pAnimator;
	CTexture* m_pTex;					// Animation이 사용하는 텍스쳐
	std::vector<tAnimFrm> m_vecFrm;		// 모든 프레임 정보
	int m_curFrm;						// 현재 프레임
	float m_AccTime;

	bool m_finish;						// 애니메이션 끝 도달 여부

	friend class CAnimator;
};
