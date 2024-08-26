
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

#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

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
	afx_msg void OnBnClickedBtnLoad();
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BTN_LOAD, &CAboutDlg::OnBnClickedBtnLoad)
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
END_MESSAGE_MAP()


// CglimProjectDlg 메시지 처리기

BOOL CglimProjectDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

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
	int parentDlgWidth = 640;
	int parentDlgHeight = 480;
	MoveWindow(0, 0, parentDlgWidth, parentDlgHeight);

	// DRAWCIRCLE 대화 상자의 크기
	int childDlgWidth = 640;  // 예: 대화 상자의 너비를 400으로 설정
	int childDlgHeight = 430; // 예: 대화 상자의 높이를 300으로 설정

	// 상단에서 100픽셀 떨어진 위치에 대화 상자를 배치하기 위해 y 좌표 계산
	int x = 0;
	int y = 50; // 상단에서 100픽셀 떨어진 위치

	// DRAWCIRCLE 대화 상자를 생성하고 표시합니다.
	m_pDlgImage = new DRAWCIRCLE;
	m_pDlgImage->Create(IDD_DRAW, this);

	// 클라이언트 영역 내에서 상단에서 100픽셀 떨어진 위치로 대화 상자를 배치합니다.
	m_pDlgImage->MoveWindow(x, y, childDlgWidth, childDlgHeight);
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
	if (m_pDlgImage2)	delete m_pDlgImage2;
}


void CglimProjectDlg::OnBnClickedBtnTest()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	unsigned char* fm = (unsigned char*)m_pDlgImage->m_Image.GetBits();
	int nWidth = m_pDlgImage->m_Image.GetWidth();
	int nHeight = m_pDlgImage->m_Image.GetHeight();
	int nPitch = m_pDlgImage->m_Image.GetPitch();

	for (int k = 0; k < 100; k++) {
		int x = rand() % nWidth;
		int y = rand() % nHeight;
		fm[y * nPitch + x] = 0;
	}
	int nSum = 0;
	for (int j = 0; j < nHeight; j++) {
		for (int i = 0; i < nWidth; i++) {
			if (fm[j * nPitch + i] == 0) {
				cout << nSum << ":" << i << "," << j << endl;
				nSum++;
			}
		}
	}
	m_pDlgImage->Invalidate();
}

