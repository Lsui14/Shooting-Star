#pragma once
#include "Entidad.h"
#include "Sphere.h"

class Enemigo2 : public Entidad
{
private:
	float velocidadMovimiento;
	Sphere figura;

public:
	Enemigo2() : Entidad(2, 1, Vector3D(1, 1, 1)), velocidadMovimiento(0.001), figura(Sphere()) {}

	inline float GetVelocidadMovimiento() const { return this->velocidadMovimiento; }
	inline Sphere GetFigura() const { return this->figura; }

	inline void SetVelocidadMovimiento(const float& velocidadMovimietnoToSet) { this->velocidadMovimiento = velocidadMovimietnoToSet; }
	inline void SetFigura(const Sphere& figuraToSet) { this->figura = figuraToSet; }

	void Desplazamiento(const float& timeIncrement);

	bool Colision(Cylinder* Bala);

	void Render();

	void Update(const float& timeIncrement);

	bool Impacto(float limite);

};

