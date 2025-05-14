
// CHAN_DoubleBufferingView.cpp: CCHANDoubleBufferingView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "CHAN_DoubleBuffering.h"
#endif

#include "CHAN_DoubleBufferingDoc.h"
#include "CHAN_DoubleBufferingView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include "BufferDC.h"	// 직접 구현한 더블 버퍼 클래스 

// CCHANDoubleBufferingView

IMPLEMENT_DYNCREATE(CCHANDoubleBufferingView, CView)

BEGIN_MESSAGE_MAP(CCHANDoubleBufferingView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()

// CCHANDoubleBufferingView 생성/소멸

CCHANDoubleBufferingView::CCHANDoubleBufferingView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CCHANDoubleBufferingView::~CCHANDoubleBufferingView()
{
}

BOOL CCHANDoubleBufferingView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CCHANDoubleBufferingView 그리기

void CCHANDoubleBufferingView::OnDraw(CDC* /*pDC*/)
{
	CCHANDoubleBufferingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CCHANDoubleBufferingView 인쇄

BOOL CCHANDoubleBufferingView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CCHANDoubleBufferingView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CCHANDoubleBufferingView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CCHANDoubleBufferingView 진단

#ifdef _DEBUG
void CCHANDoubleBufferingView::AssertValid() const
{
	CView::AssertValid();
}

void CCHANDoubleBufferingView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCHANDoubleBufferingDoc* CCHANDoubleBufferingView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCHANDoubleBufferingDoc)));
	return (CCHANDoubleBufferingDoc*)m_pDocument;
}
#endif //_DEBUG


// CCHANDoubleBufferingView 메시지 처리기


void CCHANDoubleBufferingView::OnPaint()
{
	// OnPaint 이벤트를 생성할 때 기본적으로 생성되는 구문은 주석처리 하자. 
	// 더블 버퍼링 기법의 차이를 보고 싶다면 하나씩 주석처리해서 확인해보자. 
	//CPaintDC dc(this); 
	// 버퍼 생성 
	CBufferDC dc(this);

	CRect rect;
	GetClientRect(&rect);
	for (int i = 0; i < 500; i++)
	{
		dc.FillSolidRect(&rect, RGB(192, 0, 0));
		dc.FillSolidRect(&rect, RGB(0, 200, 0));
		dc.FillSolidRect(&rect, RGB(0, 100, 0));
		dc.FillSolidRect(&rect, RGB(0, 0, 210));
		dc.FillSolidRect(&rect, RGB(0, 0, 180));
		dc.FillSolidRect(&rect, RGB(255, 0, 280));
	}
	//보다 극명한 차이를 보이기 위한 조치, 이 함수가 반드시 필요한 것은 아님
	Invalidate(0);
}


// 깜빡거림 효과 개선 중 가장 먼저 해야 하는 행동은 'OnEraseBkgnd' 이벤트를 추가해주어야 한다. 
BOOL CCHANDoubleBufferingView::OnEraseBkgnd(CDC* pDC)
{
	// OnEraseBkgnd 이벤트를 최초 생성됐을 때 아래의 return 문이 기본적으로 생성된다.
	// 이 구문은 해당 이벤트가 실행될 때, 하얀색 화면으로 오버라이트하는 역할을 수행하므로
	// 가능한 주석하는 것이 좋다. 
	CRect rect;
	GetClientRect(&rect);
	pDC->FillSolidRect(&rect, RGB(0, 0, 0));
	// 별다른 구문 없이 그냥 리턴만 시켜주면 된다.
	return true;		
	//return CView::OnEraseBkgnd(pDC);
}
