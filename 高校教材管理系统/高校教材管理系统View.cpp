// ��У�̲Ĺ���ϵͳView.cpp : implementation of the CMyView class
//

#include "stdafx.h"
#include "��У�̲Ĺ���ϵͳ.h"

#include "��У�̲Ĺ���ϵͳDoc.h"
#include "��У�̲Ĺ���ϵͳView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyView

IMPLEMENT_DYNCREATE(CMyView, CView)

BEGIN_MESSAGE_MAP(CMyView, CView)
	//{{AFX_MSG_MAP(CMyView)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyView construction/destruction

CMyView::CMyView()
{
	// TODO: add construction code here

}

CMyView::~CMyView()
{
}

BOOL CMyView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
    // TODO: �ڴ˴�ͨ���޸�
	return CView::PreCreateWindow(cs); 
}

/////////////////////////////////////////////////////////////////////////////
// CMyView drawing

void CMyView::OnDraw(CDC* pDC)
{
	CMyDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CMyView diagnostics

#ifdef _DEBUG
void CMyView::AssertValid() const
{
	CView::AssertValid();
}

void CMyView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMyDoc* CMyView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMyDoc)));
	return (CMyDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMyView message handlers

//DEL BOOL CMyView::OnEraseBkgnd(CDC* pDC)  //����������ͼƬ����
//DEL {
//DEL 	CDC MemDC;
//DEL 	//CBitmap����
//DEL 	CBitmap Bitmap,*pOldBitmap;
//DEL 	//BITMAP���
//DEL 	BITMAP bm;
//DEL 	//����λͼ
//DEL 	Bitmap.LoadBitmap(IDB_DENGLUJIEMIAN);
//DEL 	//��λͼ��Դ������
//DEL 	Bitmap.GetObject(sizeof(BITMAP),&bm);
//DEL 	//�������ڴ���ݵ�DC
//DEL 	MemDC.CreateCompatibleDC(pDC);
//DEL 	//�滻ԭλͼ
//DEL 	pOldBitmap=(CBitmap*)(MemDC.SelectObject(&Bitmap));
//DEL 	//��ȡ���Ƶ�����
//DEL 	CRect rcClient;
//DEL 	GetClientRect(&rcClient);
//DEL 	//���Ƶ��ͻ���
//DEL 	pDC->BitBlt(0,0,rcClient.Width(),rcClient.Height(),&MemDC,0,0,SRCCOPY);
//DEL 	MemDC.SelectObject(pOldBitmap);
//DEL 	MemDC.DeleteDC();
//DEL 	return TRUE;// TODO: Add your message handler code here and/or call default
//DEL 	
//DEL 	//return CView::OnEraseBkgnd(pDC);
//DEL }
