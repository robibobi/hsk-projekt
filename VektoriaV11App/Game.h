#pragma once




#ifdef _DEBUG
	#pragma comment (lib, "Vektoria_Debug.lib")
#else
	#pragma comment (lib, "Vektoria_Release.lib")
#endif

#include "Root.h"
#include "Util.h"
#include "TangentSpaceHelper.h"

using namespace Vektoria;


class CGame
{
public: 
    CGame(void);
    ~CGame(void);


	void Init(HWND hwnd, CSplash * psplash);
	void Tick(float fTime, float fTimeDelta);
	void Fini();

	void WindowReSize(int iNewWidth, int iNewHeight); // WindowsReSize wird immer dann aufgerufen, wenn der Benutzer die Fenstergröße verändert hat

private:


	

	HWND m_hwnd;
	bool m_bReSized;

    // Hier ist Platz für Deine Vektoriaobjekte:
	void setupSzene(HWND hwnd, CSplash * psplash);
	void createMaterials();
	void loadMesh(std::string objFilePath);
	void initCamera(float angle);




	CDeviceKeyboard mKeyboard;
	CDeviceMouse mMouse;

	CRoot m_zr;
	CScene m_zs;
	CPlacement m_zpCamera;
	CHardware m_zh;
	CFrame m_zf;
	CViewport m_zv;
	CCamera m_zc;


	CParallelLight m_zl;
	CParallelLight mTopLight;

	CSpotLight mSpotLight;

	CMaterial m_zm;

	// Himmel
	CGeoDome mSkyBoxGeo;
	CPlacement	mSkyPlacement;
	
	CMaterial mSkyMaterial;

	// Umgebung
	CTriangleList* mGroundMesh;
	CPlacement mGroundPlacement;
	CTriangleList* mList;


	// Kugel
	CPlacement mBoulderPlacement;
	CGeoSphere mBoulderGeo;
	CMaterial mBoulderMaterial;

	// Kamera führung
	CHMat mCamMat;
};


