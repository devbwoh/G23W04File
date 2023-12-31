﻿
// G23W04FileView.cpp: CG23W04FileView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "G23W04File.h"
#endif

#include "G23W04FileDoc.h"
#include "G23W04FileView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CG23W04FileView

IMPLEMENT_DYNCREATE(CG23W04FileView, CView)

BEGIN_MESSAGE_MAP(CG23W04FileView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CG23W04FileView 생성/소멸

CG23W04FileView::CG23W04FileView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CG23W04FileView::~CG23W04FileView()
{
}

BOOL CG23W04FileView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CG23W04FileView 그리기

void CG23W04FileView::OnDraw(CDC* pDC)
{
	CG23W04FileDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	//CPoint p = pDoc->GetPoint();
	//pDC->Ellipse(p.x - 30, p.y - 30, p.x + 30, p.y + 30);

	int n = pDoc->GetCount();
	for (int i = 0; i < n; i++) {
		CPoint p = pDoc->GetPoint(i);
		pDC->Ellipse(p.x - 30, p.y - 30, p.x + 30, p.y + 30);
	}

}


// CG23W04FileView 인쇄

BOOL CG23W04FileView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CG23W04FileView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CG23W04FileView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CG23W04FileView 진단

#ifdef _DEBUG
void CG23W04FileView::AssertValid() const
{
	CView::AssertValid();
}

void CG23W04FileView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CG23W04FileDoc* CG23W04FileView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CG23W04FileDoc)));
	return (CG23W04FileDoc*)m_pDocument;
}
#endif //_DEBUG


// CG23W04FileView 메시지 처리기


void CG23W04FileView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	//GetDocument()->SetPoint(point);
	GetDocument()->AddPoint(point);
	Invalidate();

	CView::OnLButtonDown(nFlags, point);
}

void CG23W04FileView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	GetDocument()->Undo();
	Invalidate();

	CView::OnRButtonDown(nFlags, point);
}

void CG23W04FileView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (nFlags & MK_LBUTTON) {
		GetDocument()->AddPoint(point);
		Invalidate();
	}

	CView::OnMouseMove(nFlags, point);
}