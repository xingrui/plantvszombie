// plantDlg.h : 头文件
//

#pragma once


// CplantDlg 对话框
class CplantDlg : public CDialog
{
	// 构造
public:
	CplantDlg(CWnd *pParent = NULL);	// 标准构造函数

	// 对话框数据
	enum { IDD = IDD_PLANT_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange *pDX);	// DDX/DDV 支持


	// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
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
