// DRAWCIRCLE.cpp: 구현 파일
//

#include "pch.h"
#include "GlimProject.h"
#include "afxdialogex.h"
#include "DRAWCIRCLE.h"
#include "glimProjectDlg.h"


// DRAWCIRCLE 대화 상자

IMPLEMENT_DYNAMIC(DRAWCIRCLE, CDialogEx)

DRAWCIRCLE::DRAWCIRCLE(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DRAW, pParent)
{
	m_pParent = pParent;
}

DRAWCIRCLE::~DRAWCIRCLE()
{
}

void DRAWCIRCLE::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(DRAWCIRCLE, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// DRAWCIRCLE 메시지 처리기

BOOL DRAWCIRCLE::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	MoveWindow(0, 0, 680, 550);


	InitImage();

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

void DRAWCIRCLE::InitImage() {
	int nWidth = 660;
	int nHeight = 505;
	int nBpp = 8;

	m_Image.Create(nWidth, -nHeight, nBpp);
	if (nBpp == 8) {
		static RGBQUAD rgb[256];
		for (int i = 0; i < 256; i++) {
			rgb[i].rgbRed = rgb[i].rgbGreen = rgb[i].rgbBlue = i;
			m_Image.SetColorTable(0, 256, rgb);
		}
	}

	int nPitch = m_Image.GetPitch();
	unsigned char* fm = (unsigned char*)m_Image.GetBits();

	memset(fm, 0xff, nWidth * nHeight);
}


void DRAWCIRCLE::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	if (m_Image) {
		m_Image.Draw(dc, 0, 0);
	}

}

void DRAWCIRCLE::UpdateDisplay() {
	CClientDC dc(this);
	m_Image.Draw(dc, 0, 0);
}