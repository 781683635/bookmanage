// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "��У�̲Ĺ���ϵͳ.h"

#include "MainFrm.h"
#include "DengluDlg.h"                  //��½�����ͷ�ļ�
#include "BenxueqisuoxujiaocaiDlg.h"    //�鿴��ѧ������̲�ͷ�ļ�
#include "XiugaigerenxinxiDlg.h"        //�鿴��ѧ������̲�ͷ�ļ�
#include "YonghugenggaimimaDlg.h"       //�û��޸�����ͷ�ļ�
#include "JiaocaituidingDlg.h"          //�̲��˶�ͷ�ļ�
#include "LianxiguanliyuanDlg.h"        //��ϵ����Աͷ�ļ�
#include "JiaocaijibenxinxiDlg.h"       //�̲Ļ�����Ϣͷ�ļ�
#include "JiaocaijinhuoDlg.h"           //�̲Ľ���ͷ�ļ�
#include "JiaocaichukuDlg.h"            //�̲ĳ���ͷ�ļ�
#include "KucunguanliDlg.h"             //������ͷ�ļ�
#include "KuweiguanliDlg.h"             //��λ����ͷ�ļ�
#include "GenjujiaocaihaoDlg.h"         //���ݽ̲ĺ�Ԥ��ͷ�ļ�
#include "GenjujiaocaimingDlg.h"        //���ݽ̲���Ԥ��ͷ�ļ�
#include "FenleixuanzeyudingDlg.h"      //����ѡ��Ԥ��ͷ�ļ�
#include "ChakansuoyoujiaocaiDlg.h"     //�鿴���н̲�ͷ�ļ�
#include "JinhuocaiwuguanliDlg.h"       //�����������ͷ�ļ�
#include "ChuhuocaiwuguanliDlg.h"       //�����������ͷ�ļ�
#include "YuefencaiwuguanliDlg.h"       //�·ݲ������ͷ�ļ�
#include "NianfencaiwuguanliDlg.h"      //��ݲ������ͷ�ļ�
#include "YinglizongbiaoDlg.h"          //ӯ���ܱ�ͷ�ļ�
#include "YonghugerenguanliDlg.h"       //�û����˹���ͷ�ļ�
#include "BanjifuzerenguanliDlg.h"      //�༶�����˹���ͷ�ļ�
#include "GongyingshangguanliDlg.h"     //��Ӧ�̹���ͷ�ļ�
#include "ChubansheguanliDlg.h"         //���������ͷ�ļ�
#include "ZhuceguanliyuanDlg.h"         //ע�����Աͷ�ļ�
#include "XiugaiguanliyuanmimaDlg.h"    //�޸Ĺ���Ա�����ļ�
#include "XiugaiyonghujibenxinxiDlg.h"  //�޸��û�������Ϣͷ�ļ�
#include "YonghuxiaoxiDlg.h"            //�û���Ϣͷ�ļ�







#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_COMMAND(ID_MENU_CHAKANBENXUEQISUOXUJIAOCAI, OnMenuChakanbenxueqisuoxujiaocai)
	ON_COMMAND(ID_MENU_XIUGAIGERENXINXI, OnMenuXiugaigerenxinxi)
	ON_COMMAND(ID_MENU_GENGGAIMIMA, OnMenuGenggaimima)
	ON_COMMAND(ID_MENU_JIAOCAITUIDING, OnMenuJiaocaituiding)
	ON_COMMAND(ID_MENU_LIANXIGUANLIYUAN, OnMenuLianxiguanliyuan)
	ON_COMMAND(ID_MENU_JIAOCAIJIBENXINXI, OnMenuJiaocaijibenxinxi)
	ON_COMMAND(ID_MENU_JIAOCAIJINHUO, OnMenuJiaocaijinhuo)
	ON_COMMAND(ID_MENU_JIAOCAICHUKU, OnMenuJiaocaichuku)
	ON_COMMAND(ID_MENU_KUCUNGUANLI, OnMenuKucunguanli)
	ON_COMMAND(ID_MENU_KUWEIGUANLI, OnMenuKuweiguanli)
	ON_COMMAND(ID_MENU_GENJUJIAOCAIHAOYUDING, OnMenuGenjujiaocaihaoyuding)
	ON_COMMAND(ID_MENU_GENJUJIAOCAIMINGYUDING, OnMenuGenjujiaocaimingyuding)
	ON_COMMAND(ID_MENU_FENLEIXUANZEYUDING, OnMenuFenleixuanzeyuding)
	ON_COMMAND(ID_MENU_CHAKANSUOYOUJIAOCAI, OnMenuChakansuoyoujiaocai)
	ON_COMMAND(ID_MENU_JINHUOCAIWUGUANLI, OnMenuJinhuocaiwuguanli)
	ON_COMMAND(ID_MENU_CHUHUOCAIWUGUANLI, OnMenuChuhuocaiwuguanli)
	ON_COMMAND(ID_MENU_YUEFENCAIWUGUANLI, OnMenuYuefencaiwuguanli)
	ON_COMMAND(ID_MENU_NIANFENCAIWUGUANLI, OnMenuNianfencaiwuguanli)
	ON_COMMAND(ID_MENU_YINGLIZONGBIAO, OnMenuYinglizongbiao)
	ON_COMMAND(ID_MENU_YONGHUGERENGUANLI, OnMenuYonghugerenguanli)
	ON_COMMAND(ID_MENU_BANJIFUZERENGUANLI, OnMenuBanjifuzerenguanli)
	ON_COMMAND(ID_MENU_GONGYINGSHANGGUANLI, OnMenuGongyingshangguanli)
	ON_COMMAND(ID_MENU_CHUBANSHEGUANLI, OnMenuChubansheguanli)
	ON_COMMAND(ID_MENU_ZHUCEXINGUANLIYUAN, OnMenuZhucexinguanliyuan)
	ON_COMMAND(ID_MENU_XIUGAIGUANLIYUANMIMA, OnMenuXiugaiguanliyuanmima)
	ON_COMMAND(ID_MENU_XIUGAIYONGHUJIBENXINXI, OnMenuXiugaiyonghujibenxinxi)
	ON_COMMAND(ID_MENU_YONGHUXIAOXI, OnMenuYonghuxiaoxi)
	ON_COMMAND(ID_MENU_QIEHUANYONGHU, OnMenuQiehuanyonghu)
	ON_COMMAND(ID_MENU_TUICHUDENGLU, OnMenuTuichudenglu)
	ON_COMMAND(ID_MENU_BANGZHU, OnMenuBangzhu)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{   
	////////////////////////////////////////////////////
	DengluDlg dlg; 
    if(IDOK == dlg.DoModal()) {
 
	}
    else 
    exit(0);
	/////////////////////////////�¼���ĵ�½���룬���������ǳ����ȥ�ĵ�һ������
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs) //����������ܴ��ڵĴ�С����ʽ������
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs ���޸Ĵ��������ʽ
	//cs.x = 300;  //���ڵ�X����Ϊ
    //cs.y = 300;  //���ڵ�Y����Ϊ
	//cs.dwExStyle &= ~WS_EX_CLIENTEDGE;
    //cs.lpszClass = AfxRegisterWndClass(0);

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers


void CMainFrame::OnMenuChakanbenxueqisuoxujiaocai() 
{
	BenxueqisuoxujiaocaiDlg dlg;
    dlg.DoModal();                      // �˵��򿪲�ѯ��ѧ������̲�
	
}

void CMainFrame::OnMenuXiugaigerenxinxi() 
{
	XiugaigerenxinxiDlg dlg;
    dlg.DoModal();                     //  �˵����޸ĸ�����Ϣ
	
}

void CMainFrame::OnMenuGenggaimima() 
{
	
	YonghugenggaimimaDlg dlg;
    dlg.DoModal(); // �˵����޸�����
	
}

void CMainFrame::OnMenuJiaocaituiding() 
{
	JiaocaituidingDlg dlg;
    dlg.DoModal();              // �˵��򿪽̲��˶�
	
}

void CMainFrame::OnMenuLianxiguanliyuan() 
{
	LianxiguanliyuanDlg dlg;
    dlg.DoModal();              // �˵�����ϵ����Ա
	
}

void CMainFrame::OnMenuJiaocaijibenxinxi() 
{
	JiaocaijibenxinxiDlg dlg;
    dlg.DoModal();              // �˵��򿪽̲Ļ�����Ϣ
	
}

void CMainFrame::OnMenuJiaocaijinhuo() 
{
	JiaocaijinhuoDlg dlg;
    dlg.DoModal();              // �˵��򿪽̲Ľ���
	
}

void CMainFrame::OnMenuJiaocaichuku() 
{
	JiaocaichukuDlg dlg;
    dlg.DoModal();              // �˵��򿪽̲ĳ���
	
}

void CMainFrame::OnMenuKucunguanli() 
{
	KucunguanliDlg dlg;
    dlg.DoModal();              // �˵��򿪿�����
	
}

void CMainFrame::OnMenuKuweiguanli() 
{
	KuweiguanliDlg dlg;
    dlg.DoModal();              // �˵��򿪿�λ����
	
}

void CMainFrame::OnMenuGenjujiaocaihaoyuding() 
{
	GenjujiaocaihaoDlg dlg;
    dlg.DoModal();              // �˵��򿪸��ݽ̲ĺ�Ԥ���̲�
	
}

void CMainFrame::OnMenuGenjujiaocaimingyuding() 
{
	GenjujiaocaimingDlg dlg;
    dlg.DoModal();              // �˵��򿪸��ݽ̲���Ԥ���̲�
	
}

void CMainFrame::OnMenuFenleixuanzeyuding() 
{
	FenleixuanzeyudingDlg dlg;
    dlg.DoModal();              // �˵��򿪷���ѡ��Ԥ��
	
}

void CMainFrame::OnMenuChakansuoyoujiaocai() 
{
	CChakansuoyoujiaocaiDlg dlg;
    dlg.DoModal();              // �˵��򿪲鿴���н̲�
	
}

void CMainFrame::OnMenuJinhuocaiwuguanli() 
{
	JinhuocaiwuguanliDlg dlg;
    dlg.DoModal();              // �˵��򿪽����������
	
}

void CMainFrame::OnMenuChuhuocaiwuguanli() 
{
	CChuhuocaiwuguanliDlg dlg;
    dlg.DoModal();              // �˵��򿪳����������
	
}

void CMainFrame::OnMenuYuefencaiwuguanli() 
{
	YuefencaiwuguanliDlg dlg;
    dlg.DoModal();              // �˵����·ݲ������
	
}

void CMainFrame::OnMenuNianfencaiwuguanli() 
{
	NianfencaiwuguanliDlg dlg;
    dlg.DoModal();              // �˵�����ݲ������
	
}

void CMainFrame::OnMenuYinglizongbiao() 
{
	YinglizongbiaoDlg dlg;
    dlg.DoModal();              // �˵���ӯ���ܱ�
	
}

void CMainFrame::OnMenuYonghugerenguanli() 
{
	YonghugerenguanliDlg dlg;
    dlg.DoModal();              // �˵����û����˹���
	
}

void CMainFrame::OnMenuBanjifuzerenguanli() 
{
	BanjifuzerenguanliDlg dlg;
    dlg.DoModal();              // �˵��򿪰༶�����˹���
	
}

void CMainFrame::OnMenuGongyingshangguanli() 
{
	GongyingshangguanliDlg dlg;
    dlg.DoModal();              // �˵��򿪹�Ӧ�̹���
}

void CMainFrame::OnMenuChubansheguanli() 
{
	CChubansheguanliDlg dlg;
    dlg.DoModal();              // �˵��򿪳��������
	
}

void CMainFrame::OnMenuZhucexinguanliyuan() 
{
	ZhuceguanliyuanDlg dlg;
    dlg.DoModal();              // �˵���ע�����Ա
	
}

void CMainFrame::OnMenuXiugaiguanliyuanmima() 
{
	XiugaiguanliyuanmimaDlg dlg;
    dlg.DoModal();              // �˵���ע�����Ա
	
}

void CMainFrame::OnMenuXiugaiyonghujibenxinxi() 
{
	XiugaiyonghujibenxinxiDlg dlg;
    dlg.DoModal();              // �˵����޸��û�������Ϣ
	
}

void CMainFrame::OnMenuYonghuxiaoxi() 
{
	YonghuxiaoxiDlg dlg;
    dlg.DoModal();              // �˵����û���Ϣ
	
}

void CMainFrame::OnMenuQiehuanyonghu() 
{
	// �˵����л��û�
	
}

void CMainFrame::OnMenuTuichudenglu() 
{
	// �˵����˳���¼
	
}

void CMainFrame::OnMenuBangzhu() 
{
	// �˵��򿪰���
	
}
