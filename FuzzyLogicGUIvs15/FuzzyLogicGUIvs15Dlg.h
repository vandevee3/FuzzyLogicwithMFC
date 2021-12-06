
// FuzzyLogicGUIvs15Dlg.h : header file
//

#pragma once
#include "tchart1.h"


// CFuzzyLogicGUIvs15Dlg dialog
class CFuzzyLogicGUIvs15Dlg : public CDialogEx
{
// Construction
public:
	CFuzzyLogicGUIvs15Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FUZZYLOGICGUIVS15_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CTchart1 m_chartVal;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
