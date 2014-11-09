#include "PlayerVisual.h"


PlayerVisual::PlayerVisual()
{
	loadMaterial();
	loadMesh();
}


PlayerVisual::~PlayerVisual()
{
}


void PlayerVisual::tick(float deltaMillis, float time){
	// stuff...


	// Player logik ticken
	Player::tick(deltaMillis, time);
}

void PlayerVisual::loadMaterial(){
	mPlayerMaterial.MakeTextureImage("textures\\boulder_COLOR.png");
	mPlayerMaterial.MakeTextureBump("textures\\boulder_NRM.png");
	mPlayerMaterial.MakeTextureSpecular("textures\\boulder_SPEC.png");
	mPlayerMaterial.MakeTextureGlow("textures\\boulder_SPEC.png");
}

void PlayerVisual::loadMesh(){
	mPlayerMesh.Init(0.25, &mPlayerMaterial, 12, 12);
	mPlacement.AddGeo(&mPlayerMesh);
}