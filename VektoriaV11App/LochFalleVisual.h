#pragma once
#include "LochFalle.h"
#include "root.h"

// Debug Klasse zum darstellen der Box-Colliders
class LochFalleVisual :
	public LochFalle
{
public:
	LochFalleVisual(Vektoria::CHVector boxColliderSize);
	~LochFalleVisual();

private:

	Vektoria::CGeoCube mCubeGeo;
	Vektoria::CMaterial mCubeMaterial;
	
};

