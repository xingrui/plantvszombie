// plantDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "plant.h"
#include "plantDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CplantDlg �Ի���




CplantDlg::CplantDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CplantDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CplantDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CplantDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDOK, &CplantDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &CplantDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CplantDlg ��Ϣ�������

BOOL CplantDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CplantDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CplantDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ��������о���
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
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù����ʾ��
//
HCURSOR CplantDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CplantDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	m_plantWnd = FindWindow(L"MainWindow", NULL);
	CRect plantRect;
	if(m_plantWnd != NULL)
	{
		m_plantWnd->GetWindowRect(&plantRect);
		m_plantWnd->MoveWindow(0, 0, plantRect.Width(), plantRect.Height());
	}else
	{
		return;
	}

	Sleep(2000);

	/*ChoosePlant(2, 3);
	ChoosePlant(3, 1);
	ChoosePlant(4, 7);
	ChoosePlant(4, 8);
	ChoosePlant(5, 4);
	ChoosePlant(5, 5);
	ChoosePlant(5, 7);
	ChoosePlant(6, 3);
	ChoosePlant(6, 6);
	ChoosePlant(1, 1);*/

	//PressChoose(7);
	for(int i = 1; i < 7; ++i)
	{
		PressChoose(2);
		SetPlant(3, i);
		PressChoose(2);
		SetPlant(4, i);
	}

	PressChoose(6);
	SetPlant(2, 9);
	PressChoose(6);
	SetPlant(5, 9);

	PressChoose(4);
	SetPlant(2, 3);
	PressChoose(9);
	SetPlant(2, 3);

	PressChoose(4);
	SetPlant(5, 3);
	PressChoose(9);
	SetPlant(5, 3);

	for(int i = 6; i < 9; ++i)
	{
		PressChoose(1);
		SetPlant(2, i);
		PressChoose(1);
		SetPlant(5, i);
		PressChoose(5);
		SetPlant(2, i);
		PressChoose(5);
		SetPlant(5, i);
		PressChoose(8);
		SetPlant(2, i);
		PressChoose(8);
		SetPlant(5, i);
	}
	for(int i = 1; i < 7; ++i)
		for(int j = 1; j < 7; ++j)
		{
			switch(i * 10 + j)
			{
			case 35:
			case 32:
			case 62:
			case 65:
				break;
			default:
				{
					PressChoose(7);
					SetPlant(j, i);
				}
			}
		}
		
		PressChoose(3);
		SetPlant(1, 6);
		PressChoose(3);
		SetPlant(3, 6);
		PressChoose(3);
		SetPlant(4, 6);
		PressChoose(3);
		SetPlant(6, 6);
		PressChoose(3);
		SetPlant(2, 8);
		PressChoose(3);
		SetPlant(5, 8);
	//OnOK();
}

void CplantDlg::ChoosePlant(int nRow, int nColumn)
{
	m_plantWnd->PostMessage(WM_LBUTTONDOWN, 0, MAKELONG(50 + (nColumn - 1) * 53, 160 + (nRow - 1) * 70));
	m_plantWnd->PostMessage(WM_LBUTTONUP, 0, MAKELONG(50 + (nColumn - 1) * 53, 160 + (nRow - 1) * 70));
	Sleep(100);
}

void CplantDlg::PressChoose(int nIndex)
{
	m_plantWnd->PostMessage(WM_LBUTTONDOWN, 0, MAKELONG(120 + (nIndex - 1) * 51, 40));
	m_plantWnd->PostMessage(WM_LBUTTONUP, 0, MAKELONG(50 + (nIndex - 1) * 51, 40));
	Sleep(100);
}

void CplantDlg:: SetPlant(int nRow, int nColumn)
{
	m_plantWnd->PostMessage(WM_LBUTTONDOWN, 0, MAKELONG(80 + (nColumn - 1) * 80, 120 + (nRow - 1) * 86));
	m_plantWnd->PostMessage(WM_LBUTTONUP, 0, MAKELONG(50 + (nColumn - 1) * 80, 160 + (nRow - 1) * 86));
}
void CplantDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_plantWnd = FindWindow(L"MainWindow", NULL);
	CRect plantRect;
	if(m_plantWnd != NULL)
	{
		m_plantWnd->GetWindowRect(&plantRect);
		m_plantWnd->MoveWindow(0, 0, plantRect.Width(), plantRect.Height());
	}else
	{
		return;
	}

	ChoosePlant(2, 3);
	ChoosePlant(3, 1);
	ChoosePlant(4, 7);
	ChoosePlant(4, 8);
	ChoosePlant(5, 4);
	ChoosePlant(5, 5);
	ChoosePlant(5, 7);
	ChoosePlant(6, 3);
	ChoosePlant(6, 6);
	ChoosePlant(1, 1);
}
