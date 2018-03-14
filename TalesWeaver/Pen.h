#pragma once

namespace EJ
{
	class Pen
	{
	public:
		explicit Pen();
		explicit Pen(HDC hdc);
		explicit Pen(HDC hdc, HPEN pen);

		~Pen();

		void CreatePen(HDC hdc);
		void SetColor(const COLORREF color);
		void SetWidth(const int width);
		void SetStyle(const int style);
	private:
		HDC   m_hDC;
		HPEN  m_hNewPen, m_hOldPen;

		COLORREF m_color;
		int   m_iStyle;
		int   m_nWidth;
	};
}



