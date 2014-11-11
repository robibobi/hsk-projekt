#pragma once
#include "MapPart.h"
#include "LochFalleVisual.h"
class Level1Part4 :
	public MapPart
{
public:
	Level1Part4();
	~Level1Part4();

private:
	LochFalleVisual* mFalle1Ptr;
	LochFalleVisual* mFalle2Ptr;


	void loadMaterial();
	void initGameObjects();
};

