#pragma once

class CAnimator;
class CTexture;

struct tAnimFrm
{
	Vec2 LT;
	Vec2 slice;
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

private:
	void SetName( const std::wstring& _name ) { m_Name = _name; }

private:
	std::wstring m_Name;
	CAnimator* m_pAnimator;
	CTexture* m_pTex;					// Animation�� ����ϴ� �ؽ���
	std::vector<tAnimFrm> m_vecFrm;		// ��� ������ ����

	friend class CAnimator;
};
