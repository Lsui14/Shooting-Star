	#pragma once
	#include "Scene.h"
	using namespace std;
	class Scene2 : public Scene
	{
	private:
		ModelLoader* loader;
	public:
		Scene2() {}
		void Init2();
		void CreateText();
		void CreateModel();
	};