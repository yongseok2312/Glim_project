
// gPrj.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CgPrjApp:
// �� Ŭ������ ������ ���ؼ��� gPrj.cpp�� �����Ͻʽÿ�.
//

class CgPrjApp : public CWinApp
{
public:
	CgPrjApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CgPrjApp theApp;