#pragma once
#include "Entidad.h"
#include "Cuboid.h"
#include "Cube.h"

class Torreta : public Entidad
{
private:
	float velocidadMovimiento;
	Cuboid canon;
	Cube figura;
	Vector3D posDisparo;

public:
	Torreta(): Entidad(4,1,Vector3D(1,1,1)), velocidadMovimiento(0.01), figura(Cube()), canon(Cuboid()) {}
	Torreta(float xf, float yf, float zf, float xc, float yc, float zc) : Entidad(), velocidadMovimiento(0.01), figura(Cube(xf,yf,zf)), canon(Cuboid(xc,yc,zc)) {}

	inline float GetVelocidadMovimiento() const { return this->velocidadMovimiento; }
	inline Cube GetFigura() const { return this->figura; }
	inline Cuboid GetCanon() const { return this->canon; }
	inline Vector3D GetposDisparo() const { return this->posDisparo; }

	inline void SetVelocidadMovimiento(const float& velocidadMovimietnoToSet) { this->velocidadMovimiento = velocidadMovimietnoToSet; }
	inline void SetFigura(const Cube& figuraToSet) { this->figura = figuraToSet; }
	inline void SetCanon(const Cuboid& canonToSet) { this->canon = canonToSet; }
	inline void SetPosDisparo(const Vector3D& posDisparoToSet) { this->posDisparo = posDisparoToSet; }

	Cylinder* Disparo(const float& timeIncrement);

	void Desplazamiento(const float& timeIncrement);

	bool Colision(Cylinder* Bala);

	void Render();

	void Update(const float& timeIncrement);

};

