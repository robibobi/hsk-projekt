#include "Scene.h"




Scene::Scene()
{
	
}

Scene::~Scene()
{
	
}

void Scene::init(CScene* scene, CRoot* root){
	
	mVectoriaScene = scene;
	mRoot = root;
	mMapPartManager.setScene(mVectoriaScene);
}


void Scene::initViewport(Vektoria::CViewport* viewport){
	mCamera.initViewPort(1.2, viewport);
}


void Scene::loadLevel(int lvlNr){

	//auto level = mLevelLoader.loadLevel(lvlNr);
	mActiveLevel = std::move(std::unique_ptr<Level>(new Level1()));
	mActiveLevel->initialize(mVectoriaScene);

	mCamera.setPlayerPlacement(mActiveLevel->getPlayer()->getPlacement());

	mVectoriaScene->AddPlacement(mActiveLevel->getPlayer()->getPlacement());
	
	mMapPartManager.initWithActiveLevel(mActiveLevel.get());
	
}


void Scene::tick(float deltaMillis, float ftime){

	// aktive map parts updaten
	mMapPartManager.update(deltaMillis, ftime);
	
	// aktive GameObjects ticken
	mMapPartManager.tickActiveObjects(deltaMillis, ftime);

	// rendern
	mRoot->Tick(deltaMillis);
	
}