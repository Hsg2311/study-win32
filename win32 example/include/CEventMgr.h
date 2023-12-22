#pragma once

struct tEvent
{
	EVENT_TYPE eEvent;
	DWORD_PTR lParam;	// �ַ�� �÷����� ���� ��ó���⿡�� �ڷ����� ũ�⸦ ������ �� �ִ� �ڷ��� ���
	DWORD_PTR wParam;
};

class CEventMgr
{
	SINGLETON( CEventMgr );

public:
	void update( );
	void AddEvent( const tEvent& _event ) { m_vecEvent.push_back( _event ); }

private:
	std::vector<tEvent> m_vecEvent;
	std::vector<CObject*> m_vecDead;

	void Execute( const tEvent& _event );
};
