#include "GameObject.h"


GameObject::GameObject()
{
}


GameObject::~GameObject()
{
}

void GameObject::tick(float deltaTime, float time){

}




Vektoria::CPlacement*  GameObject::getPlacement(){
	return &mPlacement;
}
