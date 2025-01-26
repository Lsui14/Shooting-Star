#pragma once
#include "Entidad.h"
#include "Cylinder.h"
#include "Solid.h"
#include "Model.h"
#include "cylinder.h"

class Jugador : public Entidad
{
private:
	
	Vector3D posDisparo;
	float velocidadAtaque;
	float velocidadMovimiento;
	Model modelo;
	
public:
	Jugador() : Entidad(3, 1, Vector3D(1, 1, 1)), posDisparo(Vector3D(6, 1, 5)), velocidadAtaque(0.1),
		velocidadMovimiento(0.5){}
	Jugador( Vector3D posDisparo, float velocidadAtaque, float velocidadMovimiento) :  posDisparo(posDisparo),
		velocidadAtaque(velocidadAtaque), velocidadMovimiento(velocidadMovimiento) {}
	
	inline Vector3D GetposDisparo() const { return this->posDisparo; }
	inline float GetVelocidadAtaque() const { return this->velocidadAtaque; }
	inline float GetVelocidadMovimiento() const { return this->velocidadMovimiento; }
	inline Model GetModel() const { return this->modelo; }

	inline void SetPosDisparo(const Vector3D& posDisparoToSet) { this->posDisparo = posDisparoToSet; }
	inline void SetVelocidadAtaque(const float& velocidadAtaqueToSet) { this->velocidadAtaque = velocidadAtaqueToSet; }
	inline void SetVelocidadMovimiento(const float& velocidadMovimientoToSet) { this->velocidadMovimiento = velocidadMovimientoToSet; }
	inline void SetModel(const Model& modeloToSet) { this->modelo = modeloToSet; }


	Cylinder* Disparo(const float& timeIncrement);

	bool Colision(Cylinder* Bala);

	void Desplazamiento(const float& timeIncrement);

	void Render();

	void Update(const float& timeIncrement);

};

