// ADOConn.h: interface for the ADOConn class.
//
//////////////////////////////////////////////////////////////////////
//#import "c:\Program Files\Common Files\System\ado\msado15.dll" no_namespace rename("EOF","adoEOF") rename("BOF","adoBOF")
#if !defined(AFX_ADOCONN_H__AF13F190_AA90_4F42_A095_80F2D28FACC7__INCLUDED_)
#define AFX_ADOCONN_H__AF13F190_AA90_4F42_A095_80F2D28FACC7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class ADOConn  
{
// �������
public:
	//���һ��ָ��Connection�����ָ��:
	_ConnectionPtr m_pConnection;
	//���һ��ָ��Recordset�����ָ��:
	_RecordsetPtr m_pRecordset;
// ���巽��
public:
	ADOConn();
	virtual ~ADOConn();
	// ��ʼ�����������ݿ�
	void  OnInitADOConn();
	// ִ�в�ѯ
	_RecordsetPtr& GetRecordSet(_bstr_t bstrSQL);
	// ִ��SQL��䣬Insert Update _variant_t
	BOOL ExecuteSQL(_bstr_t bstrSQL);
	void ExitConnect();

};

#endif // !defined(AFX_ADOCONN_H__AF13F190_AA90_4F42_A095_80F2D28FACC7__INCLUDED_)
