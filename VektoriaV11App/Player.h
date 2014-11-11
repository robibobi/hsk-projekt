#pragma once
#include "root.h"
#include "GameObject.h"



// Logik für Spieler und Kamera ( Kugel )


class Player : public GameObject
{
public:
	Player();
	~Player();

	virtual void tick(float deltaMillis, float time) override;

private:
	
	
};

