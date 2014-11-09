#pragma once

#include <memory>

#include "Level1Part1.h";
#include "Level1Part2.h";
#include "Level1Part3.h";
#include "Level.h"

class Level1 : public Level
{
public:
	Level1();
	~Level1();

	void initialize(Vektoria::CScene* scene) override;

private:
	std::unique_ptr<Level1Part1> mPart1{ new Level1Part1() };
	std::unique_ptr<Level1Part2> mPart2{ new Level1Part2() };
	std::unique_ptr<Level1Part3> mPart3{ new Level1Part3() };
	void addMapParts();

	CParallelLight mLight1;

};

