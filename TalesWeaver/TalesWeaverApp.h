#pragma once

#include "WinApp.h"

class Renderer;
class TalesWeaverApp : public WinApp
{
public:
	TalesWeaverApp();
	~TalesWeaverApp();

	virtual bool GameInit();
	virtual void Update(const float fElapsedTime);
	virtual void Render();

	shared_ptr<Renderer> m_pRenderer;
private :

};

