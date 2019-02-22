
// JingPicDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "JingPic.h"
#include "JingPicDlg.h"
#include "afxdialogex.h"

#include "NoteDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CJingPicDlg �Ի���



CJingPicDlg::CJingPicDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_JingPic_DIALOG, pParent)
	, m_strShowUrl(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CJingPicDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDITURL, m_strShowUrl);
}

BEGIN_MESSAGE_MAP(CJingPicDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_DROPFILES()
	ON_BN_CLICKED(IDC_BTNCOPY, &CJingPicDlg::OnBnClickedBtncopy)
END_MESSAGE_MAP()


// CJingPicDlg ��Ϣ�������

BOOL CJingPicDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	SetDlgItemText(IDC_EDIT,_T("\r\n\r\n\r\n\r\n\r\n\r\n\r\n�뽫ͼƬ�������"));

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CJingPicDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CJingPicDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CJingPicDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CJingPicDlg::OnDropFiles(HDROP hDropInfo)
{
	UINT Num;
	TCHAR filePath[MAX_PATH];
	Num = DragQueryFile(hDropInfo, 0xFFFFFFFF, NULL, 0);
	if (Num > 0)
	{
		for (UINT i = 0; i < Num; i++)
		{
			DragQueryFile(hDropInfo, i, filePath, sizeof(filePath));
		}
	}
	DragFinish(hDropInfo);
	CDialog::OnDropFiles(hDropInfo);

	NoteDlg dlg;
	if (dlg.DoModal() == IDOK)
	{
		m_strNote = dlg.m_strNote;
	}

	ImgMove(filePath);
	UseGit();
	m_strShowUrl = _T("https://github.com/hubojing/BlogImages/blob/master/") + m_strNewName + _T("?raw=true");
	SetDlgItemText(IDC_EDITURL, m_strShowUrl);
}

void CJingPicDlg::ImgMove(TCHAR* filePath)
{
	CString  strfilePath;
	strfilePath.Format(_T("%s"), filePath);
	int iPos = strfilePath.ReverseFind('\\');
	int temp = strfilePath.GetLength();
	CString strFileName = strfilePath.Right(strfilePath.GetLength() - iPos - 1);
	m_strNewName = m_strNote + _T("����") + strFileName;
	CString strTargetPath = _T("E:\\BlogImages");
	strTargetPath = strTargetPath + _T("\\") + m_strNewName;
	rename(filePath, strTargetPath);
// 	BOOL m = CopyFile(filePath, strTargetPath, TRUE);
}

void CJingPicDlg::UseGit()
{
	CString strNotes = m_strNote + _T("������ͼ");
	char s[MAX_PATH];
	sprintf_s(s, "%s %s", "E:\\AutoUpload.bat", strNotes);
	system(s);
}

void CJingPicDlg::OnBnClickedBtncopy()
{
	CopyToClipboard(m_strShowUrl, m_strShowUrl.GetLength());
	m_strShowUrl.ReleaseBuffer();
}

BOOL CJingPicDlg::CopyToClipboard(const char* pszData, const int nDataLen)
{
		if (::OpenClipboard(NULL))
		{
			::EmptyClipboard();
			HGLOBAL clipbuffer;
			char *buffer;
			clipbuffer = ::GlobalAlloc(GMEM_DDESHARE, nDataLen + 1);
			buffer = (char *)::GlobalLock(clipbuffer);
			strcpy(buffer, pszData);
			::GlobalUnlock(clipbuffer);
			::SetClipboardData(CF_TEXT, clipbuffer);
			::CloseClipboard();
			return TRUE;
		}
		return FALSE;
}