// 위 클래스는 더블 버퍼링 기법을 사용하기 위해 
// 직접 구현한 버퍼 클래스 이다. 
// 다른 클래스에 더블 버퍼링 기법을 사용하려면 해당 클래스를 복붙하자. 
#pragma once

class CBufferDC : public CDC
{
private:     
	CBufferDC() {}
	CBufferDC(const CBufferDC& src) {}
	CBufferDC& operator=(const CBufferDC& src) {}

protected:
	BOOL Attach(HDC hDC);
	HDC Detach();

private:
	CWnd*			m_pParent;							// 대상 윈도우에 대한 포인터
	CDC*			m_pTarget;							// 대상 윈도우 DC에 대한 포인터
	PAINTSTRUCT		m_PaintStruct;						// 화면을 그리기 위한 정보를 담는 구조체
	CRect			m_RcClient, m_RcWindow;				// 대상 윈도우의 크기 정보
	CDC				m_MemoryDC;							// 메모리 DC(버퍼 DC)
	CBitmap			m_MemoryBmp, * m_pOldMemoryBmp;		// 버퍼링을 위한 비트맵

public:
	CBufferDC(CWnd* pParent);
	~CBufferDC();

public:
	inline CRect ClientRect() const { return m_RcClient; }
	inline CRect WindowRect() const {return m_RcWindow;}
	inline CRect UpdateRect() const { return m_PaintStruct.rcPaint; }

	operator HDC() const { return m_MemoryDC.m_hDC; }	// DC Handle 
};
