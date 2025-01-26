#pragma once
#include "Scene.h"
using namespace std;
class Scene0 : public Scene
{
private:
	ModelLoader* loader;
public:
	Scene0(){}
	void Init0();
	void CreateText();
	void CreateModel();
};

