
// JingPicDlg.h : 头文件
//

#pragma once
#include "afxwin.h"

#include<string>
using namespace std;

// CJingPicDlg 对话框
class CJingPicDlg : public CDialogEx
{
// 构造
public:
	CJingPicDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_JingPic_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnDropFiles(HDROP hDropInfo);
	afx_msg void OnBnClickedBtncopy();
	DECLARE_MESSAGE_MAP()

private:
	CString m_strNote;//备注博文标题
	CString m_strFileName;//每张图片名称（带后缀）
	CString m_strShowUrl;//外链完整地址

	void UseGit();
	void ImgMove(TCHAR* filepath);
	BOOL CopyToClipboard(const char* pszData, const int nDataLen);
};
