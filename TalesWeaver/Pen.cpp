#include "stdafx.h"
#include "Pen.h"


EJ::Pen::Pen()
{
}

EJ::Pen::Pen(HDC hdc)
{
	m_hDC = hdc;
	
	m_iStyle = PS_SOLID;
	m_nWidth = 1;
	m_color = RGB(255, 0, 255);

	m_hNewPen = ::CreatePen(m_iStyle, m_nWidth,  m_color);
	m_hOldPen = (HPEN)SelectObject(hdc, m_hNewPen);
}

EJ::Pen::Pen(HDC hdc, HPEN pen)
{
	m_hDC     = hdc;
	m_hNewPen = pen;
}

// should fix this bug that m_hNewPen isn't allocated.
EJ::Pen::~Pen()
{
	DeleteObject(SelectObject(m_hDC, m_hOldPen));
	DeleteObject(m_hOldPen);
}

void EJ::Pen::CreatePen(HDC hdc)
{
	m_hDC = hdc;

	m_iStyle = PS_SOLID;
	m_nWidth = 1;
	m_color = RGB(255, 0, 255);

	m_hNewPen = ::CreatePen(m_iStyle, m_nWidth, m_color);
	m_hOldPen = (HPEN)SelectObject(hdc, m_hNewPen);
}

void EJ::Pen::SetColor(const COLORREF color)
{
	m_color = color;

	DeleteObject(SelectObject(m_hDC, m_hOldPen));
	
	m_hNewPen = ::CreatePen(m_iStyle, m_nWidth, m_color);
	m_hOldPen = (HPEN)SelectObject(m_hDC, m_hNewPen);
}

void EJ::Pen::SetWidth(const int width)
{
	m_nWidth = width;

	DeleteObject(SelectObject(m_hDC, m_hOldPen));
	
	m_hNewPen = ::CreatePen(m_iStyle, m_nWidth, m_color);
	m_hOldPen = (HPEN)SelectObject(m_hDC, m_hNewPen);
}

void EJ::Pen::SetStyle(const int style)
{
	m_iStyle = style;

	DeleteObject(SelectObject(m_hDC, m_hOldPen));

	m_hNewPen = ::CreatePen(m_iStyle, m_nWidth, m_color);
	m_hOldPen = (HPEN)SelectObject(m_hDC, m_hNewPen);
}
