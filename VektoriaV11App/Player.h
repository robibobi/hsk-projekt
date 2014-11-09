#pragma once
#include "root.h"
#include "GameObject.h"



// Logik für Spieler ( Kugel )

// Muss GameObject erweitern
class Player : public GameObject
{
public:
	Player();
	~Player();

	virtual void tick(float deltaMillis, float time) override;

private:
	
	
};

