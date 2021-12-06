
// FuzzyLogicGUIvs15.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CFuzzyLogicGUIvs15App:
// See FuzzyLogicGUIvs15.cpp for the implementation of this class
//

class CFuzzyLogicGUIvs15App : public CWinApp
{
public:
	CFuzzyLogicGUIvs15App();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CFuzzyLogicGUIvs15App theApp;