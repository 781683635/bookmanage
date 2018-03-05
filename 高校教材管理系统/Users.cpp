// Users.cpp: implementation of the CUsers class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Users.h"
#include "ADOConn.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CUsers::CUsers()
{
	UserName = "";
	UserPwd = "";
	UserType = 0;

}

CUsers::~CUsers()
{

}


//���ݿ����
int CUsers::HaveName(CString cUserName)
{	
	//�������ݿ�
	ADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	//����SELECT���
	_bstr_t vSQL;
	vSQL = "SELECT * FROM �û���Ϣ�� WHERE �û���='" + cUserName + "'";
	
	//ִ��SELECT���
	_RecordsetPtr m_pRecordset;
	m_pRecordset = m_AdoConn.GetRecordSet(vSQL);
	if (m_pRecordset->adoEOF)
		return -1;
	else
		return 1;

	//�Ͽ������ݿ������
	m_AdoConn.ExitConnect();
}

	
void CUsers::sql_insert()
{	
	//�������ݿ�
	ADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	//����INSERT���
	CString strType;
	strType.Format("%d", UserType);

	_bstr_t vSQL;
	vSQL = "INSERT INTO �û���Ϣ�� VALUES('" + UserName + "','" + UserPwd + "'," 
		+ strType + ")";	
	//ִ��INSERT���
	m_AdoConn.ExecuteSQL(vSQL);	
	//�Ͽ������ݿ������
	m_AdoConn.ExitConnect();
}

void CUsers::sql_updatePwd(CString cUserName)
{
	//�������ݿ�
	ADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	//����UPDATE���
	CString strType;
	strType.Format("%d", UserType);

	_bstr_t vSQL;
	vSQL = "UPDATE �û���Ϣ�� SET ����='" + UserPwd + "' WHERE �û���='" + cUserName + "'";
	//ִ��UPDATE���
	m_AdoConn.ExecuteSQL(vSQL);	
	//�Ͽ������ݿ������
	m_AdoConn.ExitConnect();
}

void CUsers::sql_delete(CString cUserName)
{
	//�������ݿ�
	ADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	//����DELETE���
	_bstr_t vSQL;
	vSQL = "DELETE FROM �û���Ϣ�� WHERE �û���='" + cUserName	+ "'";
	//ִ��DELETE���
	m_AdoConn.ExecuteSQL(vSQL);	
	//�Ͽ������ݿ������
	m_AdoConn.ExitConnect();
}

//����Ա����Ŷ�ȡ�����ֶ�ֵ
void CUsers::GetData(CString cUserName)
{
	//�������ݿ�
	ADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	//����SELECT���
	_bstr_t vSQL;
	vSQL = "SELECT * FROM �û���Ϣ�� WHERE �û��� ='" + cUserName + "'";
	//ִ��SELETE���
	_RecordsetPtr m_pRecordset;
	m_pRecordset = m_AdoConn.GetRecordSet(vSQL);

	//���ظ��е�ֵ
	if (m_pRecordset->adoEOF)
		CUsers();
	else
	{
		UserName = (LPCTSTR)(_bstr_t)m_pRecordset->GetCollect("�û���");       //cUserName;
		UserPwd = (LPCTSTR)(_bstr_t)m_pRecordset->GetCollect("����");
		UserType = atoi((LPCTSTR)(_bstr_t)m_pRecordset->GetCollect("�û�����"));
	}
	//�Ͽ������ݿ������
	m_AdoConn.ExitConnect();
}
