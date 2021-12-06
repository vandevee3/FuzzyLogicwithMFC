
// FuzzyLogicGUIvs15Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "FuzzyLogicGUIvs15.h"
#include "FuzzyLogicGUIvs15Dlg.h"
#include "afxdialogex.h"
#include "CSeries.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
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


// CFuzzyLogicGUIvs15Dlg dialog



CFuzzyLogicGUIvs15Dlg::CFuzzyLogicGUIvs15Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_FUZZYLOGICGUIVS15_DIALOG, pParent)
	//, m_chartVal(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFuzzyLogicGUIvs15Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TCHART1, m_chartVal);
}

BEGIN_MESSAGE_MAP(CFuzzyLogicGUIvs15Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CFuzzyLogicGUIvs15Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CFuzzyLogicGUIvs15Dlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CFuzzyLogicGUIvs15Dlg message handlers

BOOL CFuzzyLogicGUIvs15Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CFuzzyLogicGUIvs15Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CFuzzyLogicGUIvs15Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CFuzzyLogicGUIvs15Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CFuzzyLogicGUIvs15Dlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	float ux[4][100];
	float jarak[4] = { 0,25,50 };
	float g[4] = { 20,20,20 };
	float h[4] = { (g[0] * 2), (g[1] * 2), (g[2] * 2) };


	for (int x = 0; x <= 100; x++) {
		if (x < jarak[0])				ux[0][x] = 0;
		else if (x > jarak[0] + h[0])	ux[0][x] = 0;
		else							ux[0][x] = 1 - ((2 * (fabs(x - g[0] - jarak[0]) / h[0])));

		if (x < (jarak[0] + g[0]))		ux[0][x] = 1;
	
		if (x < jarak[1])				ux[1][x] = 0;
		else if (x > jarak[1] + h[1])	ux[1][x] = 0;
		else							ux[1][x] = 1 - ((2 * (fabs(x - g[1] - jarak[1]) / h[1])));

		if (x < jarak[2])				ux[2][x] = 0;
		else if (x > jarak[2] + h[2])	ux[2][x] = 0;
		else							ux[2][x] = 1 - ((2 * (fabs(x - g[2] - jarak[2]) / h[2])));
		if (x > (jarak[2] + g[2]))		ux[2][x] = 1;

		((CSeries)(m_chartVal.Series(0))).AddXY(x, ux[0][x], NULL, clTeeColor);
		((CSeries)(m_chartVal.Series(1))).AddXY(x, ux[1][x], NULL, clTeeColor);
		((CSeries)(m_chartVal.Series(2))).AddXY(x, ux[2][x], NULL, clTeeColor);
	}

}


void CFuzzyLogicGUIvs15Dlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	float ux[4][100];
	float batas[3] = { 25,65 };
	float Sdev;

	for(int x = 0; x <= 100; x++) {

		ux[0][x] = exp((-0.5*(pow((x - 50),2)))/sqrt(pow((x - 100),2)/99));
		
		((CSeries)(m_chartVal.Series(0))).AddXY(x, ux[0][x], NULL, clTeeColor);
	}
}
