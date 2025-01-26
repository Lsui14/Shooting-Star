#include "Game.h"
#include <iostream>
#include "Scene0.h"
#include "Scene1.h"
#include "Scene2.h"
#include "Scene3.h"


void Game::ProcessKeyPressed(unsigned char key, int px, int py)
{
	cout << "Tecla pulsada: " << key << endl;

	switch (key) {
	case 't':
		if (this->activeScene->GetSizeBalas() < 1 && this->activeScene->GetSizeJugador() >0) {
			this->activeScene->AddGameBalas(estrella->Disparo(TIME_INCREMENT));
		}

				
		break;
	case 'a':
		
		*estrella2 = estrella->GetModel();
		if (estrella2->GetPosition().GetX() - estrella->GetVelocidadMovimiento() * TIME_INCREMENT < 0) {
			estrella2->SetPosition(Vector3D(this->activeScene->GetBoundary().GetX(), estrella2->GetPosition().GetY(), estrella2->GetPosition().GetZ()));
		}
		else {
			estrella2->SetPosition(Vector3D(estrella2->GetPosition().GetX() - estrella->GetVelocidadMovimiento() * TIME_INCREMENT, estrella2->GetPosition().GetY(), estrella2->GetPosition().GetZ()));
			estrella->SetPosDisparo(Vector3D(estrella2->GetPosition().GetX(), estrella2->GetPosition().GetY() + 1, estrella2->GetPosition().GetZ()));
			
		}
		estrella->SetModel(*estrella2);
		
		break;
	case 'd':
		
		if (estrella2->GetPosition().GetX() + estrella->GetVelocidadMovimiento() * TIME_INCREMENT > this->activeScene->GetBoundary().GetX()) {
			estrella2->SetPosition(Vector3D(0, estrella2->GetPosition().GetY(), estrella2->GetPosition().GetZ()));
		}

		else {

			*estrella2 = estrella->GetModel();
			estrella2->SetPosition(Vector3D(estrella2->GetPosition().GetX() + estrella->GetVelocidadMovimiento() * TIME_INCREMENT, estrella2->GetPosition().GetY(), estrella2->GetPosition().GetZ()));
			estrella->SetPosDisparo(Vector3D(estrella2->GetPosition()));
			
		}
		estrella->SetModel(*estrella2);

		break;

	case 'j':
		if(this->activeScene == scenes[0]) {
		contadorEscenas++;
		this->activeScene = scenes[contadorEscenas];
		break;
		}
	}

}

void Game::ProcessMouseMovement(int x, int y)
{
	cout << "Movimiento del mouse: " << x << ", " << y << endl;
	this->activeScene->ProcessMouseMovement(x, y);
}

void Game::ProcessMouseClick(int button, int state, int x, int y)
{
	cout << "Clic del mouse: " << button << " " << state << " " << x << " " << y << endl;
	this->activeScene->ProcessMouseClick(button, state, x, y);
}

void Game::Init()
{
	cout << "GAME INIT..." << endl;
	ModelLoader* loader = new ModelLoader();
	
	Scene0* scene0 = new Scene0();
	scene0->Init0();
	this->scenes.push_back(scene0);

	Scene1* scene1 = new Scene1();
	scene1->Init1(false,true, 12, 21, 10, Color(0.0, 0.8, 0.5), false);
	scene1->CreateEnemies(3, 0, 0);
	this->scenes.push_back(scene1);

	Scene1* scene2 = new Scene1();
	scene2->Init1(false, true, 12, 16, 10, Color(0.0, 0.8, 0.5), false);
	scene2->CreateEnemies(0, 3, 0);
	this->scenes.push_back(scene2);

	Scene1* scene3 = new Scene1();
	scene3->Init1(false, true, 12, 12, 10, Color(0.0, 0.8, 0.5), false);
	scene3->CreateEnemies(0, 2, 1);
	this->scenes.push_back(scene3);

	Scene2* scene4 = new Scene2();
	scene4->Init2();
	this->scenes.push_back(scene4);

	Scene3* scene5 = new Scene3();
	scene5->Init3();
	this->scenes.push_back(scene5);
	
	estrella = new Jugador();
	Model* estrellam = new Model();
	
	loader->LoadModel("..\\..\\3dModels\\Star.obj");

	*estrellam = loader->GetModel();
	
	estrellam->SetPosition(Vector3D(6, 1, 5));
	estrellam->SetSpeed(Vector3D(0.0, 0, 0));
	estrellam->SetOrientationSpeed(Vector3D(0, 0., 0));
	estrellam->PaintColor(Color(0.6, 0.3, 0.3));
	estrella->SetModel(*estrellam);
	
	scene1->AddGameJugador(estrella);
	scene2->AddGameJugador(estrella);
	scene3->AddGameJugador(estrella);
	
	this->activeScene = this->scenes[0];
}

void Game::Render()
{
	if (this->activeScene != nullptr) this->activeScene->Render();
	
}

void Game::Update()
{

	milliseconds currentTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());

	bool timeCondition = currentTime.count() - this->initialMilliseconds.count() - this->lastUpdatedTime > UPDATE_PERIOD;
	
	if ((this->activeScene->GetSizeEnemigo1() == 0 && this->activeScene->GetSizeEnemigo2() == 0
		&& this->activeScene->GetSizeTorreta() == 0) && this->activeScene != this->scenes[4] 
		&& this->activeScene != this->scenes[5] && this->activeScene != this->scenes[0]){
		contadorEscenas++;
		this->activeScene = this->scenes[contadorEscenas];
	}

	if (this->activeScene->GetSizeJugador() == 0 && this->activeScene != this->scenes[4] && this->activeScene != this->scenes[5] && this->activeScene != this->scenes[0]){
		this->activeScene = this->scenes[5];
	}

	if (timeCondition)
	{
		if (this->activeScene != nullptr) this->activeScene->Update(TIME_INCREMENT);
		this->lastUpdatedTime = currentTime.count() - this->initialMilliseconds.count();
	}

	
	
	
}
