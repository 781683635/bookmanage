// DengluDlg.cpp : implementation file
//

#include "stdafx.h"
#include "��У�̲Ĺ���ϵͳ.h"
#include "DengluDlg.h"        //������½��ͷ�ļ�
#include "ZhuceDlg.h"         //����ע������ͷ�ļ�
#include "ADOConn.h"          //������װ�����ݿ��ͷ�ļ�
#include "Users.h"            //������װ���ͷ�ļ�
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
//#include "��У�̲Ĺ���ϵͳView.h"
/////////////////////////////////////////////////////////////////////////////
// DengluDlg dialog


DengluDlg::DengluDlg(CWnd* pParent /*=NULL*/)
	: CDialog(DengluDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(DengluDlg)
	m_Pwd = _T("");
	m_UserName = _T("");
	//}}AFX_DATA_INIT
}


void DengluDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DengluDlg)
	DDX_Text(pDX, IDC_EDIT_MIMA, m_Pwd);
	DDX_Text(pDX, IDC_EDIT_YONGHUMING, m_UserName);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DengluDlg, CDialog)
	//{{AFX_MSG_MAP(DengluDlg)
	ON_BN_CLICKED(IDC_BUTTON_DENGLU, OnButtonDenglu)
	ON_BN_CLICKED(IDC_BUTTON_ZHUCE, OnButtonZhuce)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


void DengluDlg::OnButtonDenglu() 
{  
	UpdateData(TRUE);                               //���Ի����б༭������ݶ�ȡ����Ա������
	CString      dengluming;
	CString      mima;
	CString      yonghuleixing;                     //���ü�������
	dengluming = m_UserName;                        //����ǰ��½����ֵ
	if (m_UserName == "")
	{
		MessageBox("�������û���");
		return;
	}
	if (m_Pwd == "")
	{
		MessageBox("����������");
		return;
	}                                                //���������Ч��
    try
	{
	ADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();                        //�����ݿ�
	_bstr_t vSQL;
	vSQL = "SELECT * FROM �û���Ϣ�� WHERE �û��� ='" + dengluming + "'";          //����SELECT���
	m_AdoConn.ExecuteSQL(vSQL);	                                                   //ִ��SELETE���
	_RecordsetPtr m_pRecordset;                                                    //���ü�¼��ָ��                            
	m_pRecordset = m_AdoConn.GetRecordSet(vSQL);                                   //��ò�ѯ�Ľ��
	mima = (LPCTSTR)(_bstr_t)m_pRecordset->GetCollect("����");                     //�����븳ֵ
	yonghuleixing = atoi((LPCTSTR)(_bstr_t)m_pRecordset->GetCollect("�û�����"));      //���û����͸�ֵ
    vSQL = "UPDATE ϵͳ������ SET �û���='" + dengluming + "' WHERE ����='��ǰ�û�'";   //��¼��ǰ�û���ϵͳ������
    m_AdoConn.ExecuteSQL(vSQL);	                                                        //ִ��UPDATE��� 
	m_AdoConn.ExitConnect();
	}
   catch(...)                                                                     //��ȡ������Ϣ
	{
		MessageBox("�û�������,���������ݿ�ʧ��,��ע�����ϵ����Ա!");
		return;
   }                                                                              //�Ͽ������ݿ������

	if (mima != m_Pwd)
	{
		MessageBox("��������������ϵ����Ա!");
		return;
	}	                                                                     //�����ȡ���������û��������ݲ�ͬ���򷵻�
    MessageBox("��ӭ,��½�ɹ�!");
	CDialog::OnOK();                                                         //�رնԻ���,����������		
}

void DengluDlg::OnButtonZhuce() 
{

	ZhuceDlg dlg;
	dlg.DoModal();                                                            //ע�ᰴť��ע�����

}
