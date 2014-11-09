#include "MapPartManager.h"


MapPartManager::MapPartManager()
{
	mLastMapPartLoaded = false;
	mCheck = true;
}


MapPartManager::~MapPartManager()
{
}


void MapPartManager::setScene(CScene* scene){
	mScenePtr = scene;
}

void MapPartManager::initWithActiveLevel(Level* level){
	mActiveLevelPtr = level;

	// Ersten MapPart laden und zur Scene hinzuf�gen
	mFirstActiveMapPart = mActiveLevelPtr->getNextMapPart();
	mScenePtr->AddPlacement(mFirstActiveMapPart->getPlacement());

	// Falls weitere Mapparts vorhanden: zweiten Mapparte ladens
	if (!mFirstActiveMapPart->getIsLastMapPartOfLevel()){
		mSecondActiveMapPart = mActiveLevelPtr->getNextMapPart();
		mSecondActiveMapPart->getPlacement()->TranslateZDelta(-MAP_PART_SIZE);
		mScenePtr->AddPlacement(mSecondActiveMapPart->getPlacement());
	}

}



void MapPartManager::update(float deltaMillis, float fTime){

	Vektoria::CHVector pos = mActiveLevelPtr->getPlayer()->getPlacement()->GetTranslation();
	float playerZPos = pos.z;

	
	// Wenn sich der Spieler in der Mitte eines MapPartsbefinden soll 
	// der N�chste Mappart geladen werden
	if (playerIsAtMapPartMid(playerZPos)){
		switchMapsParts();
	}

}

/*
*	Tick nur die aktiven GameObjects/Mapparts und den Player
*/
void MapPartManager::tickActiveObjects(float deltaMillis, float time){
	// Spieler ticken
	mActiveLevelPtr->getPlayer()->tick(deltaMillis, time);
	// Aktive MapParts ticken
	mFirstActiveMapPart->tick(deltaMillis, time);
	mSecondActiveMapPart->tick(deltaMillis, time);

}


/*
*	Pr�ft ob sch der Spieler in der Mitte eines MapParts befindet
*
*/
bool MapPartManager::playerIsAtMapPartMid(float absoluteZPos){
	if (mCheck){
		if (absoluteZPos < -8.0){
			mCheck = false;
			return true;
		}
	}
	return false;
}


/*
*	Entfernt den hinteren aktive Mappart aus der Szene 
*   und l�dt den n�chsten
*/
void MapPartManager::switchMapsParts(){

	// Placement aus sczene entfernen
	mScenePtr->m_placements.Sub(mFirstActiveMapPart->getPlacement());

	// Hinterer Mappart nun erster
	mFirstActiveMapPart = mSecondActiveMapPart;

	// Vorne Neuen MapPart laden
	loadNextMapPart();

	
}

/*
*	F�gt den n�chsten Mappart zur Szene hinzu
*
*/
void MapPartManager::loadNextMapPart(){

	mSecondActiveMapPart = mActiveLevelPtr->getNextMapPart();

	// neuen MapPart an sezene anh�ngen
	mSecondActiveMapPart->getPlacement()->TranslateZDelta(-MAP_PART_SIZE * 2);
	mScenePtr->AddPlacement(mSecondActiveMapPart->getPlacement());
	
}


void MapPartManager::checkIfLastMapPart(MapPart* part){
	if (part->getIsLastMapPartOfLevel())
		mLastMapPartLoaded = true;
}