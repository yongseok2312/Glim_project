
// glimProjectDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "glimProject.h"
#include "glimProjectDlg.h"
#include "afxdialogex.h"
#include <iostream>
using namespace std;



#ifdef _DEBUG
#define new DEBUG_NEW
#endif


class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnLoad1();
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CglimProjectDlg 대화 상자



CglimProjectDlg::CglimProjectDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_GRIMPROJECT_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON2);
}

void CglimProjectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CglimProjectDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_TEST, &CglimProjectDlg::OnBnClickedBtnTest)
	ON_BN_CLICKED(IDC_BTN_LOAD3, &CglimProjectDlg::OnBnClickedBtnLoad3)
	ON_BN_CLICKED(IDC_BTM_RESET, &CglimProjectDlg::OnBnClickedBtmReset)
	ON_BN_CLICKED(IDC_BTN_LOAD4, &CglimProjectDlg::OnBnClickedBtnsave)
	ON_BN_CLICKED(IDC_BTN_TEST3, &CglimProjectDlg::OnBnClickedBtnAction)
END_MESSAGE_MAP()


// CglimProjectDlg 메시지 처리기

BOOL CglimProjectDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();


	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.
	m_staticCenter.SubclassDlgItem(IDC_STATIC_CENTER, this);

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	CRect clientRect;
	GetClientRect(&clientRect);

	// 대화 상자 크기와 위치 설정
	int parentDlgWidth = 680;
	int parentDlgHeight = 600;
	MoveWindow(0, 0, parentDlgWidth, parentDlgHeight);

	int x = 0;
	int y = 50; 

	// DRAWCIRCLE 대화 상자를 생성하고 표시합니다.
	m_pDlgImage = new DRAWCIRCLE;
	m_pDlgImage->Create(IDD_DRAW, this);

	m_pDlgImage->MoveWindow(x, y, 680, 600);
	m_pDlgImage->ShowWindow(SW_SHOW);


	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CglimProjectDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CglimProjectDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CglimProjectDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CglimProjectDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	if (m_pDlgImage)		delete m_pDlgImage;
	if (m_pDlgImgReuslt)	delete m_pDlgImgReuslt;
}
CString g_strFileImage;

void CglimProjectDlg::OnBnClickedBtnTest()
{
	int txtnum = GetDlgItemInt(IDC_BTN_NUM);

	// 이미지의 포인터 가져오기
	unsigned char* fm = (unsigned char*)m_pDlgImage->m_Image.GetBits();

	int nWidth = m_pDlgImage->m_Image.GetWidth();
	int nHeight = m_pDlgImage->m_Image.GetHeight();
	int nPitch = m_pDlgImage->m_Image.GetPitch();

	srand((unsigned)time(NULL));

	
	for (int j = 0; j < txtnum; j++) {
		int nRadius = rand()%100;

		memset(fm, 0xff, nWidth * nHeight); // 0xff로 초기화

		// 랜덤 원 그리기
		int nMaxX = nWidth - 2 * nRadius;
		int nMaxY = nHeight - 2 * nRadius;

		// 원이 화면을 벗어나지 않도록 좌표를 조정합니다.
		int nSttX = rand() % (nMaxX + 1);
		int nSttY = rand() % (nMaxY + 1);

		drawCircle(fm, nSttX, nSttY, nRadius, 0); // 0xff는 흰색으로 설정

		g_strFileImage.Format(_T("C:\\Sources\\Glim_project\\과제 1\\GlimProject\\image%d.bmp"), j);
		m_pDlgImage->m_Image.Save(g_strFileImage);

		m_pDlgImage->Invalidate(); // 이미지 컨트롤을 새로 고침
		m_pDlgImage->UpdateWindow(); // 즉시 화면 업데이트

		Sleep(500); // 0.5초 대기
	}
}

void CglimProjectDlg::drawCircle(unsigned char* fm, int x, int y, int nRadius, int nGray) {
	int nCenterX = x + nRadius;
	int nCenterY = y + nRadius;
	int nWidth = m_pDlgImage->m_Image.GetWidth();
	int nHeight = m_pDlgImage->m_Image.GetHeight();
	int nPitch = m_pDlgImage->m_Image.GetPitch();


	for (int j = y; j < y + nRadius * 2; j++) {
		for (int i = x; i < x + nRadius * 2; i++) {
			if (isInCircle(i, j, nCenterX, nCenterY, nRadius)) {
				if (i >= 0 && i < nWidth && j >= 0 && j < nHeight) { // 이미지 범위 검사
					fm[j * nPitch + i] = nGray;
				}
			}
		}
	}
}

bool CglimProjectDlg::isInCircle(int i, int j, int nCenterX, int nCenterY, int nRadius) {
	double dX = i - nCenterX;
	double dY = j - nCenterY;
	double dDist = dX * dX + dY * dY;

	return dDist <= nRadius * nRadius;
}


void CglimProjectDlg::OnBnClickedBtnLoad3()
{
	CFileDialog dlg(TRUE, _T("bmp"), NULL, OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST, _T("Bitmap Files (*.bmp)|*.bmp||"));
	if (dlg.DoModal() == IDOK)
	{
		g_strFileImage = dlg.GetPathName();

		if (!m_pDlgImage->m_Image.IsNull())
		{
			m_pDlgImage->m_Image.Destroy();
		}

		HRESULT hr = m_pDlgImage->m_Image.Load(g_strFileImage);
		if (FAILED(hr))
		{
			CString errorMsg;
			return;
		}

		m_pDlgImage->UpdateDisplay();

		unsigned char* fm = (unsigned char*)m_pDlgImage->m_Image.GetBits();
		int nWidth = m_pDlgImage->m_Image.GetWidth();
		int nHeight = m_pDlgImage->m_Image.GetHeight();
		int nPitch = m_pDlgImage->m_Image.GetPitch();

		int nTh = 0x01; 

		int nSumX = 0;
		int nSumY = 0;
		int nCount = 0;

		double dMaxRadius = 0.0;
		double dCenterX = 0.0;
		double dCenterY = 0.0;

		for (int j = 0; j < nHeight; j++) {
			for (int i = 0; i < nWidth; i++) {
				if (fm[j * nPitch + i] == 0x00) { 
					nSumX += i;
					nSumY += j;
					nCount++;
				}
			}
		}

		// 중심 좌표 계산
		if (nCount > 0) {
			dCenterX = (double)nSumX / nCount;
			dCenterY = (double)nSumY / nCount;
		}

		// 중심으로부터의 최대 거리 계산
		for (int j = 0; j < nHeight; j++) {
			for (int i = 0; i < nWidth; i++) {
				if (fm[j * nPitch + i] == 0x00) { 
					double dDist = sqrt((i - dCenterX) * (i - dCenterX) + (j - dCenterY) * (j - dCenterY));
					if (dDist > dMaxRadius) {
						dMaxRadius = dDist;
					}
				}
			}
		}

		CString strCenter;
		strCenter.Format(_T("(%.2f, %.2f), %.2f"), dCenterX, dCenterY, dMaxRadius/2);

		SetDlgItemText(IDC_STATIC_CENTER, strCenter);

		int edgeX = static_cast<int>(dCenterX + dMaxRadius);
		int edgeY = static_cast<int>(dCenterY);
		drawLine(fm, static_cast<int>(dCenterX), static_cast<int>(dCenterY), edgeX, edgeY, 0xFF);

		m_pDlgImage->Invalidate();
		m_pDlgImage->UpdateWindow();
	}
}


void CglimProjectDlg::drawLine(unsigned char* fm, int x1, int y1, int x2, int y2, int color)
{
	int dx = abs(x2 - x1);
	int dy = abs(y2 - y1);
	int sx = (x1 < x2) ? 1 : -1;
	int sy = (y1 < y2) ? 1 : -1;
	int err = dx - dy;

	while (true) {
		if (validImagPos(x1, y1)) {
			fm[y1 * m_pDlgImage->m_Image.GetPitch() + x1] = color;
		}

		if (x1 == x2 && y1 == y2) break;
		int e2 = err * 2;
		if (e2 > -dy) { err -= dy; x1 += sx; }
		if (e2 < dx) { err += dx; y1 += sy; }
	}
}

void CglimProjectDlg::OnBnClickedBtmReset()
{
	int nWidth = m_pDlgImage->m_Image.GetWidth();
	int nHeight = m_pDlgImage->m_Image.GetHeight();
	unsigned char* fm = (unsigned char*)m_pDlgImage->m_Image.GetBits();

	for (int y = 0; y < nHeight; y++)
	{
		for (int x = 0; x < nWidth; x++)
		{
			fm[y * m_pDlgImage->m_Image.GetPitch() + x] = 0xFF;
		}
	}

	m_pDlgImage->Invalidate(); 
	m_pDlgImage->UpdateWindow(); 
}


void CglimProjectDlg::OnBnClickedBtnsave()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	g_strFileImage.Format(_T("C:\\Sources\\Glim_project\\과제 1\\GlimProject\\circle_center.bmp"));
	m_pDlgImage->m_Image.Save(g_strFileImage);
}


void CglimProjectDlg::OnBnClickedBtnAction()
{
	
	moverect();

	g_strFileImage.Format(_T("C:\\Sources\\Glim_project\\과제 1\\GlimProject\\circle_action.bmp"));
	m_pDlgImage->m_Image.Save(g_strFileImage);
}

void CglimProjectDlg::moverect()
{
	static int nSttX = 0;
	static int nSttY = 0;
	int nGray = 80;
	int nWidth = m_pDlgImage->m_Image.GetWidth();
	int nHeight = m_pDlgImage->m_Image.GetHeight();
	int nPitch = m_pDlgImage->m_Image.GetPitch();
	int nRadius = 20;

	unsigned char* fm = (unsigned char*)m_pDlgImage->m_Image.GetBits();


	drawCircle(fm, nSttX, nSttY, nRadius, 0xff);

	drawCircle(fm, ++nSttX, ++nSttY, nRadius, nGray);



	m_pDlgImage->Invalidate();
	m_pDlgImage->UpdateWindow();
}

BOOL CglimProjectDlg::validImagPos(int x, int y) {
	int nWidth = m_pDlgImage->m_Image.GetWidth();
	int nHeight = m_pDlgImage->m_Image.GetHeight();

	CRect rect(0, 0, nWidth, nHeight); // 영역 생성

	return rect.PtInRect(CPoint(x, y));	// 포인트 안에 들어가면 True 안들어가면 False
}

