// DlgImage.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "gPrj.h"
#include "DlgImage.h"
#include "afxdialogex.h"
#include "gPrjDlg.h"

// CDlgImage 대화 상자입니다.

IMPLEMENT_DYNAMIC(CDlgImage, CDialogEx)

CDlgImage::CDlgImage(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DLGIMAGE, pParent)
{
	m_pParent = pParent;
}

CDlgImage::~CDlgImage()
{
}

void CDlgImage::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgImage, CDialogEx)
	ON_BN_CLICKED(IDC_BTN_UP_PARENT, &CDlgImage::OnBnClickedBtnUpParent)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CDlgImage 메시지 처리기입니다.


void CDlgImage::OnBnClickedBtnUpParent()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	static int n = MAX_POINT;
	CgPrjDlg *pDlg = (CgPrjDlg*)m_pParent;
	pDlg->callFunc(n++);
}



BOOL CDlgImage::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	MoveWindow(0, 0, 640, 480);


	InitImage();
	
	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}



void CDlgImage::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	if (m_Image) {
		m_Image.Draw(dc,0, 0);
	}

	drawData(&dc);
	// 그리기 메시지에 대해서는 CDialogEx::OnPaint()을(를) 호출하지 마십시오.
}

void CDlgImage::InitImage() {
	int nWidth = 640;
	int nHeight = 480;
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


void CDlgImage::drawData(CDC* pDC) {
	CRect rect;
	CPen  pen;
	pen.CreatePen(PS_SOLID, 3, COLOR_YELLOW);  // 색상 변경 (팬, 두께 , 색상)
	CPen* pOldPen = pDC->SelectObject(&pen); // 현재 펜 저장
	for (int i = 0; i < m_nDataCount; i++) {
		rect.SetRect(m_ptData[i],m_ptData[i]);
		rect.InflateRect(2, 2);
		pDC->Ellipse(rect);
	}

	pDC->SelectObject(pOldPen); // 마무리 할 때 펜 저장
}