#include "pch.h"
#include "func.h"

#include "CEventMgr.h"

void CreateObject( CObject* _other, GROUP_TYPE _eGroup )
{
	tEvent evn{ };
	evn.eEvent = EVENT_TYPE::CREATE_OBJECT;
	evn.lParam = (DWORD_PTR)_other;
	evn.wParam = (DWORD_PTR)_eGroup;

	CEventMgr::GetInst( )->AddEvent( evn );
}

void DeleteObject( CObject* _other )
{
	tEvent evn{ };
	evn.eEvent = EVENT_TYPE::DELETE_OBJECT;
	evn.lParam = (DWORD_PTR)_other;

	CEventMgr::GetInst( )->AddEvent( evn );
}
