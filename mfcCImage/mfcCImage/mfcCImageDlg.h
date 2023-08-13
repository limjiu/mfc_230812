
// mfcCImageDlg.h : ��� ����
//

#pragma once


// CmfcCImageDlg ��ȭ ����
class CmfcCImageDlg : public CDialogEx
{
private:
	CImage m_image;
	BOOL validImgPos(int x, int y);
// �����Դϴ�.
public:
	CmfcCImageDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCCIMAGE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


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
	afx_msg void OnBnClickedBtnImage();
	afx_msg void OnBnClickedBtnSave();
	afx_msg void OnBnClickedBtnLoad();
	void UpdateDisplay();
	void moveRect();
	void drawCircle(unsigned char* fm, int i, int j, int nRadius, int nGray);
	bool isInCircle(int i, int j, int nCenterX, int nCenterY, int nRadius);
	afx_msg void OnBnClickedBtnActtion();
	void actCircle();
	CString m_editCircle;
	CEdit m_circle;
	void centercross(int centerX, int centerY);
	void drawCircle2(unsigned char* fm, int x, int y, int nRadius, int nGray);
	bool isInCircle2(int i, int j, int nCenterX, int nCenterY, int nRadius);
};
