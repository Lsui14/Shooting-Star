#pragma once
#include "Entidad.h"
#include "Cube.h"
#include "Jugador.h"


class Enemigo1 : public Entidad
{
private:
	float velocidadMovimiento;
	Cube figura;

public:
	Enemigo1() : Entidad(), velocidadMovimiento(0.001), figura(Cube()) {}

	inline float GetVelocidadMovimiento() const { return this->velocidadMovimiento; }
	inline Cube GetFigura() const { return this->figura; }

	inline void SetVelocidadMovimiento(const float& velocidadMovimietnoToSet) { this->velocidadMovimiento = velocidadMovimietnoToSet; }
	inline void SetFigura(const Cube& figuraToSet) { this->figura = figuraToSet; }

	void Desplazamiento(const float& timeIncrement);

	bool Colision(Cylinder* Bala);

	void Render();

	void Update(const float& timeIncrement);

	bool Impacto(float limite);

};

