#pragma once




#ifdef _DEBUG
	#pragma comment (lib, "Vektoria_Debug.lib")
#else
	#pragma comment (lib, "Vektoria_Release.lib")
#endif

#include "Root.h"
#include "Util.h"
#include "TangentSpaceHelper.h"
#include "Scene.h"

using namespace Vektoria;


class CGame
{
public: 
    CGame(void);
    ~CGame(void);

	void Init(HWND hwnd, CSplash * psplash);
	void Tick(float fTime, float fTimeDelta);
	void Fini();
	void WindowReSize(int iNewWidth, int iNewHeight);

private:

	Vektoria::CScene mVectoriaScene;
	Vektoria::CRoot mRoot;
	Vektoria::CFrame mFrame;
	Vektoria::CViewport mViewPort;
	

	Scene mScene;


};


