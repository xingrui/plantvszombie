// plantDlg.h : ͷ�ļ�
//

#pragma once


// CplantDlg �Ի���
class CplantDlg : public CDialog
{
	// ����
public:
	CplantDlg(CWnd *pParent = NULL);	// ��׼���캯��

	// �Ի�������
	enum { IDD = IDD_PLANT_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange *pDX);	// DDX/DDV ֧��


	// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
protected:
	void PressChoose(int nIndex);
	void ChoosePlant(int nRow, int nColumn);
	void SetPlant(int nRow, int nColumn);
	CWnd *m_plantWnd;
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedCheck1();
	BOOL m_bIsBackGround;
};
