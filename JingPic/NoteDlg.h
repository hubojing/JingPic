#pragma once
#include "afxwin.h"


// NoteDlg 对话框

class NoteDlg : public CDialogEx
{
	DECLARE_DYNAMIC(NoteDlg)

public:
	NoteDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~NoteDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_NOTE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CString m_strNote;
};
