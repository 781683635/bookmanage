// JiaocaijibenxinxiDlg.cpp : implementation file
//

#include "stdafx.h"
#include "��У�̲Ĺ���ϵͳ.h"
#include "JiaocaijibenxinxiDlg.h"
#include "ADOConn.h" 
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// JiaocaijibenxinxiDlg dialog


JiaocaijibenxinxiDlg::JiaocaijibenxinxiDlg(CWnd* pParent /*=NULL*/)
	: CDialog(JiaocaijibenxinxiDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(JiaocaijibenxinxiDlg)
	m_chaxuntiaojian = _T("");
	m_chaxunneirong = _T("");
	m_zhidujiaocaibianhao = _T("");
	m_zhidujiaocaimingcheng = _T("");
	//}}AFX_DATA_INIT
}


void JiaocaijibenxinxiDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(JiaocaijibenxinxiDlg)
	DDX_CBString(pDX, IDC_COMBO_CHAXUNTIAOJIAN, m_chaxuntiaojian);
	DDX_Text(pDX, IDC_EDIT_CHAXUNNEIRONG, m_chaxunneirong);
	DDX_Text(pDX, IDC_EDIT_ZHIDUJIAOCAIBIANHAO, m_zhidujiaocaibianhao);
	DDX_Text(pDX, IDC_EDIT_ZHIDUJIAOCAIMINGCHENG, m_zhidujiaocaimingcheng);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(JiaocaijibenxinxiDlg, CDialog)
	//{{AFX_MSG_MAP(JiaocaijibenxinxiDlg)
	ON_BN_CLICKED(IDC_BUTTON_CHAXUN, OnButtonChaxun)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// JiaocaijibenxinxiDlg message handlers

void JiaocaijibenxinxiDlg::OnButtonChaxun() 
{
	UpdateData(TRUE);                   //���Ի����б༭������ݶ�ȡ����Ա������
    if (m_chaxuntiaojian == "")
	{
		MessageBox("��ѡ���ѯ����!");
		return;
	}
	if (m_chaxunneirong == "")
	{
		MessageBox("�������ѯ����!");
		return;
	}
	
	try
	{
	ADOConn m_AdoConn;                          //�������ݿ�
	m_AdoConn.OnInitADOConn();                     
	_bstr_t vSQL; 
	if (m_chaxuntiaojian == "�̲�ID")
	{
       vSQL = "SELECT * FROM �̲Ļ�����Ϣ�� WHERE �̲�ID ='" + m_chaxunneirong + "'";
	   m_AdoConn.ExecuteSQL(vSQL);	
	}
	if (m_chaxuntiaojian == "���")
	{
       vSQL = "SELECT * FROM �̲Ļ�����Ϣ�� WHERE ��� ='" + m_chaxunneirong + "'";
	   m_AdoConn.ExecuteSQL(vSQL);	
	}
	if (m_chaxuntiaojian == "����")
	{
       vSQL = "SELECT * FROM �̲Ļ�����Ϣ�� WHERE ���� ='" + m_chaxunneirong + "'";
	   m_AdoConn.ExecuteSQL(vSQL);	
	}
	if (m_chaxuntiaojian == "����")
	{
       vSQL = "SELECT * FROM �̲Ļ�����Ϣ�� WHERE ���� ='" + m_chaxunneirong + "'";
	   m_AdoConn.ExecuteSQL(vSQL);	
	}
 	_RecordsetPtr m_pRecordset;  
	m_pRecordset.CreateInstance(__uuidof(Recordset));                              //��ʼ����¼��ָ��
	m_pRecordset = m_AdoConn.GetRecordSet(vSQL);  
    m_zhidujiaocaibianhao = (LPCTSTR)(_bstr_t)m_pRecordset->GetCollect("�̲�ID");           //���и�ֵ������
	m_zhidujiaocaimingcheng = (LPCTSTR)(_bstr_t)m_pRecordset->GetCollect("����");
    m_AdoConn.ExitConnect();                         
	UpdateData(FALSE);
	}
	
    catch(...)                                                                     //��ȡ������Ϣ
	{
		MessageBox("��ѯʧ�ܣ�û���ҵ�����Ҫ��ѯ�ļ�¼!");
		return;
	}
	
}

BOOL JiaocaijibenxinxiDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
