// CCreate.cpp: 구현 파일
//

#include "pch.h"
#include "CreateCircle.h"
#include "afxdialogex.h"
#include "CCreate.h"


// CCreate 대화 상자

IMPLEMENT_DYNAMIC(CCreate, CDialogEx)

CCreate::CCreate(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

CCreate::~CCreate()
{
}

void CCreate::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CCreate, CDialogEx)
END_MESSAGE_MAP()


// CCreate 메시지 처리기
