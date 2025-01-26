#pragma once
#include <vector>

#include "Cube.h"
#include "Sphere.h"
#include "Camera.h"
#include "ModelLoader.h"
#include "Model.h"
#include "Cuboid.h"
#include "Cylinder.h"

#include "Text.h"
#include "Jugador.h"
#include "Entidad.h"
#include "Enemigo1.h"
#include "Enemigo2.h"
#include "Torreta.h"

using namespace std;

class Scene
{
private:

	Camera camera;
	vector<Solid*> gameObjects;
	vector<Jugador*> gameJugador;
	vector<Cylinder*> gameBalas;
	vector<Enemigo1*> gameEnemigos;
	vector<Enemigo2*> gameEnemigos2;
	vector<Torreta*> gameTorretas;
	vector<Cylinder*> gameBalasTorreta;
	Vector3D boundary;

	bool drawVertexes;
	bool drawBox;

	void checkBoundary();

	

public:
	Scene(Vector3D boundaryArgument = Vector3D(12, 20, 10), bool drawVertexesArgument = false, bool drawBoxArgument = false) : 
		boundary(boundaryArgument), drawVertexes(drawVertexesArgument), drawBox(drawBoxArgument) {};

	inline Vector3D GetBoundary() const { return this->boundary; }
	inline void SetBoundary(const Vector3D& boundaryToSet) { this->boundary = boundaryToSet; }
	inline bool GetDrawVertexes() const { return this->drawVertexes; }
	inline void SetDrawVertexes(const bool& drawVertexesToSet) { this->drawVertexes = drawVertexesToSet; }
	inline bool GetDrawBox() const { return this->drawBox; }
	inline void SetDrawBox(const bool& drawBoxToSet) { this->drawBox = drawBoxToSet; }

	inline int GetSizeBalas() const { return this->gameBalas.size(); }
	inline int GetSizeJugador() const { return this->gameJugador.size(); }

	inline int GetSizeEnemigo1() const { return this->gameEnemigos.size(); }
	inline int GetSizeEnemigo2() const { return this->gameEnemigos2.size(); }
	inline int GetSizeTorreta() const { return this->gameTorretas.size(); }

	inline void AddGameObject(Solid* gameObject) { this->gameObjects.push_back(gameObject); }
	inline void AddGameJugador(Jugador* gameJugador) { this->gameJugador.push_back(gameJugador); }
	inline void AddGameBalas(Cylinder* gameBalas) { this->gameBalas.push_back(gameBalas); }
	inline void AddGameBalasTorreta(Cylinder* gameBalas) { this->gameBalasTorreta.push_back(gameBalas); }
	inline void AddGameEnemigo1(Enemigo1* gameEnemigo) { this->gameEnemigos.push_back(gameEnemigo); }
	inline void AddGameEnemigo2(Enemigo2* gameEnemigo) { this->gameEnemigos2.push_back(gameEnemigo); }
	inline void AddGameTorreta(Torreta* gameTorreta) { this->gameTorretas.push_back(gameTorreta); }

	inline void ClearBalas() { this->gameBalas.clear(); }
	inline void ClearJugador() { this->gameJugador.clear(); }
	inline void ClearOneBala(int id) {
		for (int i = id; i < (this->gameBalas.size() - 1); i++) {
			this->gameBalas[i] = this->gameBalas[i + 1];
		}
		this->gameBalas.pop_back();

		
	}

	inline void ClearOneBalaTorreta(int id) {
		for (int i = id; i < (this->gameBalasTorreta.size() - 1); i++) {
			this->gameBalasTorreta[i] = this->gameBalasTorreta[i + 1];
		}
		this->gameBalasTorreta.pop_back();


	}


	inline void ClearOneEnemigo(int id)
	{  
		for (int i = id; i < (this->gameEnemigos.size() - 1); i++) {
			this->gameEnemigos[i] = this->gameEnemigos[i + 1];
		}
		this->gameEnemigos.pop_back();
		
		 }

	inline void ClearOneEnemigo2(int id)
	{
		for (int i = id; i < (this->gameEnemigos2.size() - 1); i++) {
			this->gameEnemigos2[i] = this->gameEnemigos2[i + 1];
		}
		this->gameEnemigos2.pop_back();

		;
	}

	inline void ClearOneTorreta(int id)
	{
		for (int i = id; i < (this->gameTorretas.size() - 1); i++) {
			this->gameTorretas[i] = this->gameTorretas[i + 1];
		}
		this->gameTorretas.pop_back();

	}

	void Init(float x, float y, float z, Color color, bool fondo);
	void Render();
	void Update(const float& timeIncrement);


	void ProcessKeyPressed(unsigned char key, int px, int py);
	void ProcessMouseMovement(int x, int y);
	void ProcessMouseClick(int button, int state, int x, int y);

};

