#include "MapPart.h"


MapPart::MapPart(int nr)
{
	mIsLastMapPartOfLevel = false;
	mPartNr = nr;
}


MapPart::~MapPart()
{
	// alle GameObjekte löschen (smart pointer)
	mGameObjects.clear();
}


// tickt alle Gameobjects durch
void MapPart::tick(float deltaMillis, float time){
	for (auto&& r : mGameObjects){
		r->tick(deltaMillis, time);
	}
}


Vektoria::CPlacement*  MapPart::getPlacement(){
	return &mRootPlacement;
}


bool MapPart::getIsLastMapPartOfLevel(){
	return mIsLastMapPartOfLevel;
}


void MapPart::setIsLastMapPartOfLevel(){
	mIsLastMapPartOfLevel = true;
}

void MapPart::addGameObject(GameObject* obj){
	// GameObject in Liste aufnehmen
	mGameObjects.push_back(std::unique_ptr<GameObject>(obj));
	// Placement an Mappart Placement anghängen
	mRootPlacement.AddPlacement(obj->getPlacement());
}


void MapPart::loadMesh(std::string objFilePath){
	Vektoria::CFileWavefront loader = Vektoria::CFileWavefront();

	mGroundMesh = loader.LoadGeo((char*)objFilePath.c_str());
	
	rs::TangentSpaceHelper::calculateTangentsAndBitangents(mGroundMesh);

	mGroundMesh->SetMaterial(&mGroundMaterial);

	mRootPlacement.AddGeo(mGroundMesh);
}