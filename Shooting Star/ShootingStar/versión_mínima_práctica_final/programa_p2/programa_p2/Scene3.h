	#pragma once
	#include "Scene.h"
	using namespace std;
	class Scene3 : public Scene
	{
	private:
		ModelLoader* loader;
	public:
		Scene3() {}
		void Init3();
		void CreateText();
		void CreateModel();
	};

