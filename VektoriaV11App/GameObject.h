#pragma once

#include "root.h"

class GameObject
{
public:
	GameObject();
	~GameObject();

	Vektoria::CPlacement* getPlacement();

	virtual void tick(float deltaTime, float time);

private:

protected:

	// Jedes Gameobjekt besitzt eine position
	Vektoria::CPlacement mPlacement;

};

