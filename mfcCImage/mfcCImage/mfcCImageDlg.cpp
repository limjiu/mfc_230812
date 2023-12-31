
// mfcCImageDlg.cpp : 구현 파일
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


// CmfcCImageDlg 대화 상자



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


// CmfcCImageDlg 메시지 처리기

BOOL CmfcCImageDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CmfcCImageDlg::OnPaint()
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

void CmfcCImageDlg::drawCircle(unsigned char* fm, int x, int y, int nRadius, int nGray) // x,y는 시작좌표
{
	int nCenterX = x + nRadius; //반지름만큼 더해주는것
	int nCenterY = y + nRadius;
	int nPitch = m_image.GetPitch();

	int nSumX = 0;
	int nSumY = 0;
	int nCount = 0;

	
	

	//원만드는거
	for (int j = y; j < y + nRadius * 2; j++) {
		for (int i = x; i < x + nRadius * 2; i++) {
			if (isInCircle(i, j, nCenterX, nCenterY, nRadius)) {
				fm[j * nPitch + i] = nGray;
				nSumX += i;
				nSumY += j;
				nCount++;
			}
		}
		//원의 무게중심을 여기서 찾고 -> 그 매개변수를 drawPoint 함수에 전달해서 drawPoint 함수가 십자마크와 노란원을 그리자

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


	// TODO: 여기에 구현 코드 추가.
}


void CmfcCImageDlg::centercross(int centerX, int centerY)
{
	// TODO: 여기에 구현 코드 추가.

	g_centerX = centerX;
	g_centerY = centerY;



}


void CmfcCImageDlg::drawCircle2(unsigned char* fm, int x, int y, int nRadius, int nGray)
{
	// TODO: 여기에 구현 코드 추가.

	int nCenterX = g_centerX; //반지름만큼 더해주는것
	int nCenterY = g_centerY;
	int nPitch = m_image.GetPitch();

	

	//원만드는거
	for (int j = y; j < y + nRadius * 4; j++) {
		for (int i = x; i < x + nRadius * 4; i++) {
			if (isInCircle2(i, j, nCenterX, nCenterY, nRadius)) {
				fm[j * nPitch + i] = nGray;
				
			}
		}
		//원의 무게중심을 여기서 찾고 -> 그 매개변수를 drawPoint 함수에 전달해서 drawPoint 함수가 십자마크와 노란원을 그리자

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
