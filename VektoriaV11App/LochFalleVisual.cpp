#include "LochFalleVisual.h"


LochFalleVisual::LochFalleVisual(Vektoria::CHVector boxColliderSize) 
	 : LochFalle(boxColliderSize)
{

	mCubeMaterial.SetTransparencyOn();
	mCubeMaterial.MakeTextureImage("level\\level1\\collidervisual_COLOR.png");
	//mCubeMaterial.SetShadingOff();
	boxColliderSize *= 0.5;
	mCubeGeo.Init(boxColliderSize, &mCubeMaterial);
	mPlacement.AddGeo(&mCubeGeo);
}


LochFalleVisual::~LochFalleVisual()
{
}

