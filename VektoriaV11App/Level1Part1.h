#pragma once
#include "MapPart.h"
#include "LochFalleVisual.h"
#include "TangentSpaceHelper.h"
#include "root.h"

class Level1Part1 : public MapPart
{
public:
	Level1Part1();
	~Level1Part1();

private:
	
	// Um das l�schen der GameObjects k�mmert sich der 
	// zust�ndige MapPart
	LochFalleVisual* mFalle1Ptr;
	LochFalleVisual* mFalle2Ptr;


	void loadMaterial();
	void initGameObjects();
};

