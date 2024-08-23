
// mfcBitmapBtnDlg.h : ��� ����
//

#pragma once


// CmfcBitmapBtnDlg ��ȭ ����
class CmfcBitmapBtnDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CmfcBitmapBtnDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCBITMAPBTN_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.

private:
	CBitmapButton *m_pBtnOnOff; 
	void InitButtons();


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnDestroy();
	afx_msg void OnBnClickedBtnOnOff();
};
