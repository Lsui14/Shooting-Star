#pragma once
#include "Scene.h"
#include <chrono>
#include "Jugador.h"
#include "Enemigo1.h"
#include "Scene1.h"
#include "Scene2.h"
#include "Scene3.h"



using namespace std;
using namespace std::chrono;

class Game
{
private:
	vector<Scene*> scenes;
	Scene* activeScene;
	

	Jugador* estrella;

	Cylinder* Bala = new Cylinder();

	Cylinder* Balas = new Cylinder[5];
	int idBala = 0;

	Model* estrella2 = new Model();

	int contadorEscenas = 0;


	const float TIME_INCREMENT = 2; // tiempo en el juego, este valor se puede aumentar o disminuir para que la velocidad del juego sea la adecuada (ya que depende del procesador de cada ordenador, la velocidad es mayor o menor)
	const long UPDATE_PERIOD = 0.01; //tiempo real

	milliseconds initialMilliseconds;
	long lastUpdatedTime;

public:
	Game() : activeScene(nullptr)
	{
		this->initialMilliseconds = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
		this->lastUpdatedTime = 0;
	}

	void Init();
	void Render();
	void Update();

	void ProcessKeyPressed(unsigned char key, int px, int py);
	void ProcessMouseMovement(int x, int y);
	void ProcessMouseClick(int button, int state, int x, int y);

};

