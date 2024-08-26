#pragma once
#include "afxdialogex.h"


// DRAWCIRCLE 대화 상자

class DRAWCIRCLE : public CDialogEx
{
	DECLARE_DYNAMIC(DRAWCIRCLE)

public:
	DRAWCIRCLE(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~DRAWCIRCLE();

	CImage m_Image;
	CWnd* m_pParent;
	int m_nDataCount = 0;
	CPoint m_ptData[100];

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DRAW };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	void InitImage();
	void drawData(CDC* pDC);
	afx_msg void OnPaint();
};
