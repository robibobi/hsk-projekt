#pragma once
#include "GameObject.h"
#include "root.h"

// Logik f�r Lochfallen

class LochFalle : public GameObject
{
public:
	// Collider Typ wird durch GameObjecttyp festegelegt -> LochFalle = BoxCollider
	// Position und rotation wird durch GameObject::mRootPlacement bestimmt
	// Gr��e der Box in x, y und z Richtung wird im Ctor angegeben
	LochFalle(Vektoria::CHVector boxColliderSize);


	~LochFalle();

	// wird vom Level aufgerufen wenn zugeh�riger Mappart aktiv
	virtual void tick(float deltaMillis, float time) override;
};

