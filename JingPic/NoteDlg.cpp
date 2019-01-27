// NoteDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "JingPic.h"
#include "NoteDlg.h"
#include "afxdialogex.h"


// NoteDlg 对话框

IMPLEMENT_DYNAMIC(NoteDlg, CDialogEx)

NoteDlg::NoteDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_NOTE, pParent)
	, m_strNote(_T(""))
{

}

NoteDlg::~NoteDlg()
{
}

void NoteDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_NOTE, m_strNote);
}


BEGIN_MESSAGE_MAP(NoteDlg, CDialogEx)
	ON_BN_CLICKED(IDC_OK, &NoteDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// NoteDlg 消息处理程序


void NoteDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialog::OnOK();
}
