#include "StdAfx.h"
#include "Game.h"



CGame::CGame(void)
{
}

CGame::~CGame(void)
{
}

void CGame::Init(HWND hwnd, CSplash * psplash)
{	
	mRoot.Init(psplash);
	mFrame.Init(hwnd, eRenderApi_DirectX11_Shadermodel50);

	mScene.init(&mVectoriaScene, &mRoot);

	// Kamera initialisieren
	mScene.initViewport(&mViewPort);

	mRoot.AddFrameHere(&mFrame);
	mFrame.AddViewport(&mViewPort);
	mRoot.AddScene(&mVectoriaScene);

	// erstes Level laden
	mScene.loadLevel(1);
	
	mViewPort.SetWireframeOn();
	
}

void CGame::Tick(float fTime, float fTimeDelta)
{
	mScene.tick(fTimeDelta, fTime);
}

void CGame::Fini()
{
}

void CGame::WindowReSize(int iNewWidth, int iNewHeight)
{	
}










