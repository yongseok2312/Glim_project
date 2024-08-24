// CDraw.cpp: 구현 파일
//

#include "pch.h"
#include "CreateCircle.h"
#include "afxdialogex.h"
#include "CDraw.h"


// CDraw 대화 상자

IMPLEMENT_DYNAMIC(CDraw, CDialogEx)

CDraw::CDraw(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

CDraw::~CDraw()
{
}

void CDraw::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDraw, CDialogEx)
END_MESSAGE_MAP()


// CDraw 메시지 처리기
