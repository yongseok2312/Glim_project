
// glimProjectDlg.h: 헤더 파일
//
#include "DRAWCIRCLE.h"
#include "Resource.h"

#pragma once


// CglimProjectDlg 대화 상자
class CglimProjectDlg : public CDialogEx
{
// 생성입니다.
public:
	CglimProjectDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

	DRAWCIRCLE* m_pDlgImage;
	DRAWCIRCLE* m_pDlgImgReuslt;
	DRAWCIRCLE* m_pDlgImage2;

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_glimPROJECT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;
	CStatic m_staticCenter;
	int m_PixelInterval; 
	int m_CircleRadius;  
	CPoint m_StartPoint;
    CPoint m_EndPoint;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnDestroy();
	afx_msg void OnBnClickedBtnTest();
	void drawCircle(unsigned char* fm, int i, int j, int nRadius, int nGray);
	bool isInCircle(int i, int j, int nCenterX, int nCenterY, int nRadius);
	afx_msg void OnBnClickedBtnLoad3();
	afx_msg void OnBnClickedBtmReset();
	afx_msg void OnBnClickedBtnsave();
	afx_msg void OnBnClickedBtnAction();
	void SaveImage(const CString& filePath);
};
