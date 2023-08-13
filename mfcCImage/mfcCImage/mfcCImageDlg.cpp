
// mfcCImageDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "mfcCImage.h"
#include "mfcCImageDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include <iostream>
using namespace std;


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
protected:
	DECLARE_MESSAGE_MAP()
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


// CmfcCImageDlg ��ȭ ����



CmfcCImageDlg::CmfcCImageDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCCIMAGE_DIALOG, pParent)
	, m_editCircle(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CmfcCImageDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_CIRCLE, m_editCircle);
	DDX_Control(pDX, IDC_EDIT_CIRCLE, m_circle);
}

BEGIN_MESSAGE_MAP(CmfcCImageDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_IMAGE, &CmfcCImageDlg::OnBnClickedBtnImage)
	ON_BN_CLICKED(IDC_BTN_SAVE, &CmfcCImageDlg::OnBnClickedBtnSave)
	ON_BN_CLICKED(IDC_BTN_LOAD, &CmfcCImageDlg::OnBnClickedBtnLoad)
	ON_BN_CLICKED(IDC_BTN_ACTTION, &CmfcCImageDlg::OnBnClickedBtnActtion)
END_MESSAGE_MAP()


// CmfcCImageDlg �޽��� ó����

BOOL CmfcCImageDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// �� ��ȭ ������ �������� �����մϴ�.  ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CmfcCImageDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CmfcCImageDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CmfcCImageDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CmfcCImageDlg::OnBnClickedBtnImage()
{
	int nWidth = 640;
	int nHeight = 480;
	int nBpp = 8;
	
	m_image.Create(nWidth, -nHeight, nBpp);
	if (nBpp == 8) {
		static RGBQUAD rgb[256];
		for (int i = 0; i < 256; i++)
			rgb[i].rgbRed = rgb[i].rgbGreen = rgb[i].rgbBlue = i;
		m_image.SetColorTable(0, 256, rgb);
	}
	

	//m_image.SetColorTable(0, 256, rgb);


	int nPitch = m_image.GetPitch();
	unsigned char* fm = (unsigned char*)m_image.GetBits();

	memset(fm, 0xff, nWidth*nHeight);

	//for (int j = 0; j < nHeight; j++) {
	//	for (int i = 0; i < nWidth; i++) {
	//		fm[j*nPitch + i] = (j % 0xff);
//	}
//}

//for (int j = 0; j < nHeight/2; j++) {
//	for (int i = 0; i < nWidth/2; i++) {
//		fm[j*nPitch + i] = 200;
//	}
//}

UpdateDisplay();
}

CString g_strFileImage = _T("c:\\image\\save.bmp");
void CmfcCImageDlg::OnBnClickedBtnSave()
{
	m_image.Save(g_strFileImage);
}


void CmfcCImageDlg::OnBnClickedBtnLoad()
{
	if (m_image != NULL) {
		m_image.Destroy();
	}
	m_image.Load(g_strFileImage);

	UpdateDisplay();
}

void CmfcCImageDlg::UpdateDisplay()
{
	CClientDC dc(this);
	m_image.Draw(dc, 0, 0);

}

void CmfcCImageDlg::moveRect()
{
	static int nSttX = 0;
	static int nSttY = 0;
	int nGray = 80;
	int nWidth = m_image.GetWidth();
	int nHeight = m_image.GetHeight();
	int nPitch = m_image.GetPitch();
	int nRadius = 20;
	unsigned char* fm = (unsigned char*)m_image.GetBits();

	//memset(fm, 0xff, nWidth*nHeight);
	drawCircle(fm, nSttX, nSttY, nRadius, 0xff);
	//drawCircle(fm, ++nSttX, ++nSttY, nRadius, nGray);

	UpdateDisplay();
	CString strFile;
	strFile.Format(_T("C:\\image\\image%d.jpg"), nSttX);
	m_image.Save(strFile);
}

void CmfcCImageDlg::OnBnClickedBtnActtion()
{
	/*for (int i = 0; i < 400; i++) {
		moveRect();
		Sleep(10);
	}*/

	actCircle();
	Sleep(10);

}

BOOL CmfcCImageDlg::validImgPos(int x, int y)
{
	int nWidth = m_image.GetWidth();
	int nHeight = m_image.GetHeight();
	CRect rect(0, 0, nWidth, nHeight);

	return rect.PtInRect(CPoint(x, y));
}

void CmfcCImageDlg::drawCircle(unsigned char* fm, int x, int y, int nRadius, int nGray) // x,y�� ������ǥ
{
	int nCenterX = x + nRadius; //��������ŭ �����ִ°�
	int nCenterY = y + nRadius;
	int nPitch = m_image.GetPitch();

	int nSumX = 0;
	int nSumY = 0;
	int nCount = 0;

	
	

	//������°�
	for (int j = y; j < y + nRadius * 2; j++) {
		for (int i = x; i < x + nRadius * 2; i++) {
			if (isInCircle(i, j, nCenterX, nCenterY, nRadius)) {
				fm[j * nPitch + i] = nGray;
				nSumX += i;
				nSumY += j;
				nCount++;
			}
		}
		//���� �����߽��� ���⼭ ã�� -> �� �Ű������� drawPoint �Լ��� �����ؼ� drawPoint �Լ��� ���ڸ�ũ�� ������� �׸���

	}

	int dCenterX = nSumX / nCount;
	int dCenterY = nSumY / nCount;

	cout << dCenterX << "\t" << dCenterY << endl;

	

	centercross(dCenterX, dCenterY);

}

bool CmfcCImageDlg::isInCircle(int i, int j, int nCenterX, int nCenterY, int nRadius)
{
	bool bRet = false;

	double dX = i - nCenterX;
	double dY = j - nCenterY;
	double dDist = dX * dX + dY * dY;

	if (dDist < nRadius*nRadius) {
		bRet = true;
	}

	return bRet;
}


void CmfcCImageDlg::actCircle()
{

	int nSttX = 0;
	int nSttY = 0;
	int nGray = 80;
	int nWidth = m_image.GetWidth();
	int nHeight = m_image.GetHeight();
	int nPitch = m_image.GetPitch();
	int nRadius = 0;
	int nRadius2 = 0;
	unsigned char* fm = (unsigned char*)m_image.GetBits();
	CString str = _T("");
	m_circle.GetWindowText(str);

	nRadius = _ttoi(str);
	nRadius2 = nRadius / 2;


	srand(time(NULL));

	nSttX = (rand() % nWidth) + nRadius;
	nSttY = (rand() % nHeight) + nRadius;


	//memset(fm, 0xff, nWidth*nHeight);
	//drawCircle(fm, nSttX, nSttY, nRadius, 0xff);
	drawCircle(fm, nSttX, nSttY, nRadius, 0x30);
	drawCircle2(fm, nSttX, nSttY, nRadius2, 0x49);


	UpdateDisplay();
	//CString strFile;
	//strFile.Format(_T("C:\\image\\image%d.jpg"), nSttX);
	//m_image.Save(strFile);


	// TODO: ���⿡ ���� �ڵ� �߰�.
}


void CmfcCImageDlg::centercross(int centerX, int centerY)
{
	// TODO: ���⿡ ���� �ڵ� �߰�.

	g_centerX = centerX;
	g_centerY = centerY;



}


void CmfcCImageDlg::drawCircle2(unsigned char* fm, int x, int y, int nRadius, int nGray)
{
	// TODO: ���⿡ ���� �ڵ� �߰�.

	int nCenterX = g_centerX; //��������ŭ �����ִ°�
	int nCenterY = g_centerY;
	int nPitch = m_image.GetPitch();

	

	//������°�
	for (int j = y; j < y + nRadius * 4; j++) {
		for (int i = x; i < x + nRadius * 4; i++) {
			if (isInCircle2(i, j, nCenterX, nCenterY, nRadius)) {
				fm[j * nPitch + i] = nGray;
				
			}
		}
		//���� �����߽��� ���⼭ ã�� -> �� �Ű������� drawPoint �Լ��� �����ؼ� drawPoint �Լ��� ���ڸ�ũ�� ������� �׸���

	}

	for (int j = (nCenterY - 7); j < (nCenterY + 7); j++) {
		
			fm[j * nPitch + nCenterX] = nGray;	
	}
	for (int i = (nCenterX - 7); i < (nCenterX + 7); i++) {

		fm[nCenterY * nPitch + i] = nGray;
	}



}


bool CmfcCImageDlg::isInCircle2(int i, int j, int nCenterX, int nCenterY, int nRadius)
{

	bool bRet = false;

	double dX = i - nCenterX;
	double dY = j - nCenterY;
	double dDist = dX * dX + dY * dY;

	if ((dDist > ((nRadius - 1) * (nRadius - 1))) && (dDist < nRadius * nRadius)) {
		bRet = true;
	}

	return bRet;

}
