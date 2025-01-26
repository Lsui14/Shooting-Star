#pragma once
#include "Scene.h"
class Scene1 : public Scene
{
private:
	ModelLoader* loader;
public:
	Scene1(){}
	void Init1(bool vertex, bool box, float x, float y, float z,Color color, bool fondo);
	void CreateEnemies(int numEnemigos1, int numEnemigos2,int numEnemigos3);
	
};

