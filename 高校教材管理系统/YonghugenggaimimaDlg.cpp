// YonghugenggaimimaDlg.cpp : implementation file
//

#include "stdafx.h"
#include "��У�̲Ĺ���ϵͳ.h"
#include "YonghugenggaimimaDlg.h"
#include "ADOConn.h"    //������װ�����ݿ��ͷ�ļ�
#include "Users.h"      //������װ���ͷ�ļ�

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// YonghugenggaimimaDlg dialog


YonghugenggaimimaDlg::YonghugenggaimimaDlg(CWnd* pParent /*=NULL*/)
	: CDialog(YonghugenggaimimaDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(YonghugenggaimimaDlg)
	m_jiumima = _T("");
	m_xinmima = _T("");
	m_chongfumima = _T("");
	//}}AFX_DATA_INIT
}


void YonghugenggaimimaDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(YonghugenggaimimaDlg)
	DDX_Text(pDX, IDC_EDIT_JIUMIMA, m_jiumima);
	DDX_Text(pDX, IDC_EDIT_XINMIMA, m_xinmima);
	DDX_Text(pDX, IDC_EDITCHONGFUXINMIMA, m_chongfumima);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(YonghugenggaimimaDlg, CDialog)
	//{{AFX_MSG_MAP(YonghugenggaimimaDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// YonghugenggaimimaDlg message handlers

void YonghugenggaimimaDlg::OnOK() 
{   
	CString    yonghuming;
	CString    mima;
	UpdateData(TRUE); // TODO: Add extra validation here
	 try
	{
	ADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();                        //�����ݿ�
	_bstr_t vSQL;
	vSQL = "SELECT * FROM ϵͳ������ WHERE ���� ='��ǰ�û�'";
	m_AdoConn.ExecuteSQL(vSQL);	                                                   //ִ��SELETE���
	_RecordsetPtr m_pRecordset;                                                    //���ü�¼��ָ��                            
	m_pRecordset = m_AdoConn.GetRecordSet(vSQL);                                   //��ò�ѯ�Ľ��
	yonghuming = (LPCTSTR)(_bstr_t)m_pRecordset->GetCollect("�û���");
    vSQL = "SELECT * FROM �û���Ϣ�� WHERE �û��� ='" + yonghuming + "'";
    m_pRecordset.CreateInstance(__uuidof(Recordset));                              //��ʼ����¼��ָ��
	m_pRecordset = m_AdoConn.GetRecordSet(vSQL); 
    mima = (LPCTSTR)(_bstr_t)m_pRecordset->GetCollect("����");
    m_AdoConn.ExitConnect();                           
    }
   catch(...)                                                                     //��ȡ������Ϣ
	{
		MessageBox("��ȡ����ʧ�ܣ�����ϵ����Ա");
		return;
	}
    if (m_jiumima != mima)
	{
		MessageBox("������󣬲������޸�����!");
		return;
	}

	if (m_xinmima != m_chongfumima)
	{
		MessageBox("�����������벻��ͬ���������������!");
		return;
	}
    if (mima == m_xinmima)
	{
		MessageBox("������;�����һ��!");
		return;
	}
    UpdateData(FALSE);
	try
	{
	ADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();                        //�����ݿ�
	_bstr_t vSQL;
    vSQL = "UPDATE �û���Ϣ�� SET ����='" + m_xinmima + "' WHERE �û���='" + yonghuming + "'"; 
	m_AdoConn.ExecuteSQL(vSQL);
    m_AdoConn.ExitConnect();                           
    }
   catch(...)                                                                     //��ȡ������Ϣ
	{
		MessageBox("��������ʧ�ܣ�����ϵ����Ա");
		return;
	}
   MessageBox("�ɹ��޸�����!");
 

	CDialog::OnOK();
}
