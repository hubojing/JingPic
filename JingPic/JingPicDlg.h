
// JingPicDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"

#include<string>
using namespace std;

// CJingPicDlg �Ի���
class CJingPicDlg : public CDialogEx
{
// ����
public:
	CJingPicDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_JingPic_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnDropFiles(HDROP hDropInfo);
	afx_msg void OnBnClickedBtncopy();
	DECLARE_MESSAGE_MAP()

private:
	CString m_strNote;//��ע���ı���
	CString m_strNewName;//ÿ��ͼƬ���ƣ�����׺��
	CString m_strShowUrl;//����������ַ

	void UseGit();
	void ImgMove(TCHAR* filepath);
	BOOL CopyToClipboard(const char* pszData, const int nDataLen);
};
