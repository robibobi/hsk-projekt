#pragma once

#include "root.h"
#include "Player.h"

using namespace Vektoria;

class PlayerVisual : public Player
{
public:
	PlayerVisual();
	~PlayerVisual();

	void tick(float deltaMillis, float time) override;

	void loadMaterial();
	void loadMesh();

private:

	CGeoSphere mPlayerMesh;
	CMaterial mPlayerMaterial;
};

