#include "Player.h"


Player::Player()
{
}


Player::~Player()
{
}


void Player::tick(float deltaMillis, float time){


	// Beispielsweise spieler noch vorne bewegen
	mPlacement.TranslateZDelta(-deltaMillis);


	// Gameobject.tick()
	GameObject::tick(deltaMillis, time);
}


