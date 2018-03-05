// XiugaigerenxinxiDlg.cpp : implementation file
//

#include "stdafx.h"
#include "��У�̲Ĺ���ϵͳ.h"
#include "XiugaigerenxinxiDlg.h"
#include "ADOConn.h"               //������װ�����ݿ��ͷ�ļ�
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// XiugaigerenxinxiDlg dialog


XiugaigerenxinxiDlg::XiugaigerenxinxiDlg(CWnd* pParent /*=NULL*/)
	: CDialog(XiugaigerenxinxiDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(XiugaigerenxinxiDlg)
	m_beizhu = _T("");
	m_lianxifangshi = _T("");
	m_mima = _T("");
	m_querenmima = _T("");
	m_xingming = _T("");
	m_yonghuming = _T("");
	m_zhuanye = _T("");
	m_chushengriqi = 0;
	m_xingbie = _T("");
	//}}AFX_DATA_INIT
}


void XiugaigerenxinxiDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(XiugaigerenxinxiDlg)
	DDX_Text(pDX, IDC_EDIT_BEIZHU, m_beizhu);
	DDX_Text(pDX, IDC_EDIT_LIANXIFANGSHI, m_lianxifangshi);
	DDX_Text(pDX, IDC_EDIT_MIMA, m_mima);
	DDX_Text(pDX, IDC_EDIT_QUERENMIMA, m_querenmima);
	DDX_Text(pDX, IDC_EDIT_XINGMING, m_xingming);
	DDX_Text(pDX, IDC_EDIT_YONGHUMING, m_yonghuming);
	DDX_Text(pDX, IDC_EDIT_ZHUANYE, m_zhuanye);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER, m_chushengriqi);
	DDX_CBString(pDX, IDC_COMBO_XINGBIE, m_xingbie);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(XiugaigerenxinxiDlg, CDialog)
	//{{AFX_MSG_MAP(XiugaigerenxinxiDlg)
	ON_BN_CLICKED(IDC_BUTTON_XIUGAI, OnButtonXiugai)
	ON_BN_CLICKED(IDC_BUTTON_HUOQUWODEXINXI, OnButtonHuoquwodexinxi)
	ON_BN_CLICKED(IDC_BUTTON_QUXIAO, OnButtonQuxiao)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// XiugaigerenxinxiDlg message handlers

void XiugaigerenxinxiDlg::OnButtonXiugai() 
{
	UpdateData(TRUE);                   //���Ի����б༭������ݶ�ȡ����Ա������
    if (m_yonghuming == "")
	{
		MessageBox("���Ȼ�ȡ������Ϣ!");
		return;
	}
	if (m_mima == "")
	{
		MessageBox("���Ȼ�ȡ������Ϣ!");
		return;
	}                                           
	if (m_mima != m_querenmima)
	{
		MessageBox("������������벻��ȷ���������޸ĸ�����Ϣ!");
		return;
	}
	if (m_xingming == "")
	{
		MessageBox("����������!");
		return;
	}
	if (m_xingbie == "")
	{
		MessageBox("��ѡ���Ա�!");
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
	}
	if (m_beizhu == "")
	{
		m_beizhu = "��";
        UpdateData(FALSE);
		MessageBox("���ڱ�עû����д���Ѿ��Զ���Ϊ��!");
		return;
	}                                           //���������Ч��
	UpdateData(TRUE);
	ADOConn m_AdoConn;                          //�������ݿ�
	m_AdoConn.OnInitADOConn();                     
	_bstr_t vSQL;                               //����UPDATE���
	vSQL = "UPDATE �û���Ϣ�� SET ����='" + m_xingming + "' WHERE �û���='" + m_yonghuming + "'"; 	
	m_AdoConn.ExecuteSQL(vSQL);	                //ִ��UPDATE���
    vSQL = "UPDATE �û���Ϣ�� SET �Ա�='" + m_xingbie + "' WHERE �û���='" + m_yonghuming + "'"; 	
	m_AdoConn.ExecuteSQL(vSQL);	                //ִ��UPDATE���
	vSQL = "UPDATE �û���Ϣ�� SET ��ϵ��ʽ='" + m_lianxifangshi + "' WHERE �û���='" + m_yonghuming + "'"; 	
	m_AdoConn.ExecuteSQL(vSQL);	                //ִ��UPDATE���
	vSQL = "UPDATE �û���Ϣ�� SET רҵ='" + m_zhuanye + "' WHERE �û���='" + m_yonghuming + "'"; 	
	m_AdoConn.ExecuteSQL(vSQL);	                //ִ��UPDATE���
	vSQL = "UPDATE �û���Ϣ�� SET ��ע='" + m_beizhu + "' WHERE �û���='" + m_yonghuming + "'"; 	
	m_AdoConn.ExecuteSQL(vSQL);	                //ִ��UPDATE���
	m_AdoConn.ExitConnect();                         
	CDialog::OnOK();                         //�رնԻ���    
	
}

void XiugaigerenxinxiDlg::OnButtonHuoquwodexinxi() 
{
	CString yonghuming;                                                            //�Ա������ж���                                                       
                            
    try
	{
	ADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();                                                     //�����ݿ�
	_bstr_t vSQL;
	vSQL = "SELECT * FROM ϵͳ������ WHERE ���� ='��ǰ�û�'";                      //����SELECT���
	m_AdoConn.ExecuteSQL(vSQL);	                                                   //ִ��SELETE���
	_RecordsetPtr m_pRecordset;                                                    //���ü�¼��ָ��                            
	m_pRecordset = m_AdoConn.GetRecordSet(vSQL);                                   //��ò�ѯ�Ľ��
	yonghuming = (LPCTSTR)(_bstr_t)m_pRecordset->GetCollect("�û���");             //���û�����ֵ              
	vSQL = "SELECT * FROM �û���Ϣ�� WHERE �û��� ='" + yonghuming + "'";          //���±������û����ҵ���Ϣ
	m_pRecordset.CreateInstance(__uuidof(Recordset));                              //��ʼ����¼��ָ��
	m_pRecordset = m_AdoConn.GetRecordSet(vSQL);                                   //��ü�¼��
    m_yonghuming = (LPCTSTR)(_bstr_t)m_pRecordset->GetCollect("�û���");           //���и�ֵ������
	m_mima = (LPCTSTR)(_bstr_t)m_pRecordset->GetCollect("����");
	m_xingming = (LPCTSTR)(_bstr_t)m_pRecordset->GetCollect("����");
	m_xingbie = (LPCTSTR)(_bstr_t)m_pRecordset->GetCollect("�Ա�");
	m_lianxifangshi = (LPCTSTR)(_bstr_t)m_pRecordset->GetCollect("��ϵ��ʽ");
	m_zhuanye = (LPCTSTR)(_bstr_t)m_pRecordset->GetCollect("רҵ");
	m_beizhu = (LPCTSTR)(_bstr_t)m_pRecordset->GetCollect("��ע");
    m_AdoConn.ExitConnect();                         
	UpdateData(FALSE);                                                            //�ѱ�����ֵ��ֵ���ؼ�
	}
   catch(...)                                                                     //��ȡ������Ϣ
	{
		MessageBox("��ȡ������Ϣʧ�ܣ�����ϵ����Ա");
		return;
	}
}




void XiugaigerenxinxiDlg::OnButtonQuxiao() 
{
	CDialog::OnOK();// TODO: Add your control notification handler code here
	
}
