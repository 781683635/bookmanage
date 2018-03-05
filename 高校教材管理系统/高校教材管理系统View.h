// ��У�̲Ĺ���ϵͳView.h : interface of the CMyView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_VIEW_H__55151A4D_4A68_41B4_BAED_DBB1B70FA6CE__INCLUDED_)
#define AFX_VIEW_H__55151A4D_4A68_41B4_BAED_DBB1B70FA6CE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMyView : public CView
{
protected: // create from serialization only
	CMyView();
	DECLARE_DYNCREATE(CMyView)

// Attributes
public:

	CMyDoc* GetDocument();             

// Operations   
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	/*_ConnectionPtr m_pConnection;      //���ݿ����ӱ���
	_RecordsetPtr  m_pRecordset;       //���ݿ��¼������
	_CommandPtr    m_Command;*/          //���ݿ��������                     //���ADO������ָ�����
	virtual ~CMyView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMyView)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ��У�̲Ĺ���ϵͳView.cpp
inline CMyDoc* CMyView::GetDocument()
   { return (CMyDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VIEW_H__55151A4D_4A68_41B4_BAED_DBB1B70FA6CE__INCLUDED_)
