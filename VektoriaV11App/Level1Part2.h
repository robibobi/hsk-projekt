#pragma once
#include "MapPart.h"
#include "LochFalleVisual.h"
class Level1Part2 :
	public MapPart
{
public:
	Level1Part2();
	~Level1Part2();

private:
	LochFalleVisual* mFalle1Ptr;
	LochFalleVisual* mFalle2Ptr;


	void loadMaterial();
	void initGameObjects();
};

