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
	m_hwnd = hwnd;
	m_bReSized = false;

	setupSzene(hwnd, psplash);

	initCamera(1.3);

	createMaterials();




	std::cout << "Hello Init 2";

	// Himmel
	mSkyBoxGeo.Init(40.0, 15.0, &mSkyMaterial, true);
	mSkyPlacement.AddGeo(&mSkyBoxGeo);
	mSkyPlacement.TranslateY(45.0);
	mSkyPlacement.SetSky();
	
	m_zs.AddPlacement(&mSkyPlacement);
	
	// Umgebung
	loadMesh("meshes\\map_simple1.obj");
	mGroundPlacement.AddGeo(mGroundMesh);
	m_zs.AddPlacement(&mGroundPlacement);
	mGroundPlacement.Translate(0, 0, -4);
	mGroundMesh->SetMaterial(&m_zm);

	// Kugel
	mBoulderGeo.Init(0.4, &mBoulderMaterial);
	
	//mBoulderGeo.MapPlanarY();
	mBoulderPlacement.AddGeo(&mBoulderGeo);
	mBoulderPlacement.Translate(0, -0.5, -3.0);
	
	//m_zs.AddPlacement(&mBoulderPlacement);

	// Kugel an kamera anhängen
	m_zpCamera.AddPlacement(&mBoulderPlacement);
}

void CGame::Tick(float fTime, float fTimeDelta)
{
	// Kemara Mat zurücksetzen und um 2 nach oben heben

	m_zpCamera.Translate(0, 0, 0);
	mKeyboard.PlaceWASD(m_zpCamera, fTimeDelta, true);
	
	// Cam relativ zu den coordinaten achsten verschieben
	m_zpCamera.m_mLocal = m_zpCamera.m_mLocal  *  mCamMat;
	mBoulderPlacement.RotateX(0);
	switch (mKeyboard.GetChar(mKeyboard.GetKey())){
	case 'w':
		mBoulderPlacement.RotateX(-fTime * 2.5);
		break;
	case 's':
		mBoulderPlacement.RotateX(fTime * 2.5);
		break;
	case 'a':
		mBoulderPlacement.RotateZ(fTime * 2.5);
		break;
	case 'd':
		mBoulderPlacement.RotateZ(-fTime * 2.5);
		break;
	}
	
		
	
	mBoulderPlacement.TranslateDelta(0, -0.75, -3.0);

	
	//m_zpCamera.Translate(camTranslation);
	//mGroundPlacement.RotateY(-fTime * 0.5);
	//mGroundPlacement.RotateXDelta(-fTime* 0.5);
	//mGroundPlacement.TranslateDelta(0, 0, -3);

	//m_zpCamera.RotateXDelta(mMoudse.GetRelativeY());

	

	m_zr.Tick(fTimeDelta);
}

void CGame::Fini()
{
	delete mGroundMesh;
}

void CGame::WindowReSize(int iNewWidth, int iNewHeight)
{
	// Windows ReSize wird immer automatisch aufgerufen, wenn die Fenstergröße verändert wurde.
	// Hier kannst Du dann die Auflösung des Viewports neu einstellen:
	//m_zf.ReSize(iNewWidth, iNewHeight);
}

void CGame::setupSzene(HWND hwnd, CSplash * psplash){
	// Hier die Initialisierung Deiner Vektoria-Objekte einfügen:
	m_zr.Init(psplash);
	m_zf.Init(hwnd, eRenderApi_DirectX11_Shadermodel50);
	m_zv.InitFull(&m_zc);
	m_zr.AddFrameHere(&m_zf);
	m_zf.AddViewport(&m_zv);
	m_zr.AddScene(&m_zs);
	m_zv.SetBackfaceCullingOff();

	// Licht
	m_zl.Init(CHVector(4, 4, -2), CColor(1, 0.7, 0.7));

	mTopLight.Init(CHVector(0, 5, -2), CColor(1.0, 0.8, 0.8));
	m_zs.AddParallelLight(&m_zl);
	m_zs.AddParallelLight(&mTopLight);

	mSpotLight.Init(CColor(1.0, 1.0, 1.0), HALFPI * 0.1, HALFPI * 0.5, 10.0);

	// Keyboard
	m_zf.AddDeviceKeyboard(&mKeyboard);
	mKeyboard.SetWASDTranslationSensitivity(2.0);
	mKeyboard.SetWASDRotationSensitivity(2.0);
	

	// Maus
	m_zf.AddDeviceMouse(&mMouse);
	mMouse.SetSensitivity(mMouse.GetSensitivity() * 3.0);

}

void CGame::createMaterials(){


	mSkyMaterial.MakeTextureSky("textures\\skybox.jpg");

	m_zm.MakeTextureImage("textures\\simple1_baked_flipped.png");
	m_zm.MakeTextureSpecular("textures\\simple1_baked_flipped_SPEC.jpg");
	m_zm.MakeTextureGlow("textures\\simple1_glow.png");
	m_zm.MakeTextureBump("textures\\simple1_baked_flipped_NRM.jpg");

	mBoulderMaterial.MakeTextureImage("textures\\boulder_COLOR.png");
	mBoulderMaterial.MakeTextureSpecular("textures\\boulder_SPEC.png");
	mBoulderMaterial.MakeTextureBump("textures\\boulder_NRM.png");
	mBoulderMaterial.MakeTextureGlow("textures\\boulder_GLOW.png");
	mBoulderMaterial.SetSpecularSharpness(128);
	mBoulderMaterial.SetBumpStrength(0.5);
}

void CGame::loadMesh(std::string objFilePath){
	CFileWavefront loader = CFileWavefront();
	//CFileBlender blenderLoader = CFileBlender();

	//mGroundMesh = blenderLoader.LoadGeo((char*)objFilePath.c_str());
	mGroundMesh = loader.LoadGeo((char*)objFilePath.c_str());
	//mGroundMesh->EstimateTangentsAndBinormals();
	//mList = loader.LoadGeo((char*)objFilePath.c_str());
	
	rs::TangentSpaceHelper::calculateTangentsAndBitangents(mGroundMesh);
	
	
}

void CGame::initCamera(float angle){
	m_zc.Init(angle);
	m_zpCamera.AddCamera(&m_zc);
	m_zs.AddPlacement(&m_zpCamera);
	m_zpCamera.RotateX(-HALFPI * 0.20);
	m_zpCamera.TranslateDelta(0, 2.0, 0.0);
	mCamMat = m_zpCamera.m_mLocal; // x rotation und y verschiebung
}




