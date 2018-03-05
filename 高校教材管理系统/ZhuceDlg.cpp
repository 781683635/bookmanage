// ZhuceDlg.cpp : implementation file
//

#include "stdafx.h"
#include "��У�̲Ĺ���ϵͳ.h"
#include "ZhuceDlg.h"
#include "ADOConn.h"               //������װ�����ݿ��ͷ�ļ�

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// ZhuceDlg dialog


ZhuceDlg::ZhuceDlg(CWnd* pParent /*=NULL*/)
	: CDialog(ZhuceDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(ZhuceDlg)
	m_yonghuming = _T("");
	m_mima = _T("");
	m_querenmima = _T("");
	m_xingming = _T("");
	m_zhuanye = _T("");
	m_lianxifangshi = _T("");
	m_beizhu = _T("");
	m_xingbie = _T("");
	m_chushengriqi = 0;
	//}}AFX_DATA_INIT
}


void ZhuceDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ZhuceDlg)
	DDX_Text(pDX, IDC_EDIT_YONGHUMING, m_yonghuming);
	DDX_Text(pDX, IDC_EDIT_MIMA, m_mima);
	DDX_Text(pDX, IDC_EDIT_QUERENMIMA, m_querenmima);
	DDX_Text(pDX, IDC_EDIT_XINGMING, m_xingming);
	DDX_Text(pDX, IDC_EDIT_ZHUANYE, m_zhuanye);
	DDX_Text(pDX, IDC_EDIT_LIANXIFANGSHI, m_lianxifangshi);
	DDX_Text(pDX, IDC_EDIT_BEIZHU, m_beizhu);
	DDX_CBString(pDX, IDC_COMBO_XINGBIE, m_xingbie);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER, m_chushengriqi);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(ZhuceDlg, CDialog)
	//{{AFX_MSG_MAP(ZhuceDlg)
	ON_BN_CLICKED(IDC_BUTTON_ZHUCE, OnButtonZhuce)
	ON_BN_CLICKED(IDC_BUTTON_QUXIAO, OnButtonQuxiao)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ZhuceDlg message handlers

void ZhuceDlg::OnButtonZhuce() 
{
	UpdateData(TRUE);                   //���Ի����б༭������ݶ�ȡ����Ա������
    if (m_yonghuming == "")
	{
		MessageBox("�������û���!");
		return;
	}
	if (m_mima == "")
	{
		MessageBox("����������!");
		return;
	}                                           
	if (m_mima != m_querenmima)
	{
		MessageBox("������������벻��ȷ������������!");
		return;
	}
	if (m_xingming == "")
	{
		MessageBox("����������!");
		return;
	}
	if (m_xingbie == "")
	{
		MessageBox("��ѡ���ձ�!");
		return;
	}
	if (m_lianxifangshi == "")
	{
		MessageBox("��������ϵ��ʽ!");
		return;
	} 
	if (m_zhuanye == "")
	{
		MessageBox("������רҵ!");
		return;
	}                                                      //���������Ч��
    ADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();                            //�������ݿ�
	CString yonghuming;
	CString mima;
	CString xingming;
	CString xingbie;
	CString lianxifangshi;
	CString zhuanye;
	CString chushengriqi;
	CString beizhu;
	CString yonghuleixing;
	yonghuming    = m_yonghuming;
	yonghuleixing = "1";
	mima          = m_mima;
	xingming      = m_xingming;
	xingbie       = m_xingbie;
	lianxifangshi = m_lianxifangshi;
	zhuanye       = m_zhuanye;
	chushengriqi  = 1995-01-15;
	beizhu        = m_beizhu;
	try
	{
	bstr_t vSQL;
	vSQL = "INSERT INTO �û���Ϣ��(�û���,����,�û�����,����,�Ա�,��ϵ��ʽ,רҵ,��ע) VALUES('" + yonghuming + "','" + mima + "','" + yonghuleixing + "','" + xingming + "','" + xingbie + "','" + lianxifangshi + "','" + zhuanye + "','" + beizhu + "')";
	//ִ��INSERT���
	m_AdoConn.ExecuteSQL(vSQL);	
	//�Ͽ������ݿ������
	m_AdoConn.ExitConnect();
	}
	catch(...)
	{
		MessageBox("ע��ʧ�ܣ�����ϵ����Ա");
		return;
	}
	MessageBox("�ɹ�ע��!");
	CDialog::OnOK();     
}

void ZhuceDlg::OnButtonQuxiao() 
{
	CDialog::OnOK();// TODO: Add your control notification handler code here
	
}
