#pragma once
#include "Vector3D.h"
#include "Cylinder.h"
#include "Solid.h"



class Entidad
{
private:
	int vida;
	int dano;
	Vector3D posicion;
	

public:
	Entidad() : vida(1), dano(1), posicion(Vector3D(1,1,1)) {}
	
	Entidad(int vida, int dano, Vector3D posicion) : vida(vida), dano(dano), posicion(posicion) {}

	inline int GetVida() const { return this->vida; }
	inline int GetDano() const { return this->dano; }
	inline Vector3D GetPosicion() const { return this->posicion; }
	
	inline void SetVida(const int& vidaToSet) { this->vida = vidaToSet; }
	inline void SetDano(const int& danoToSet) { this->dano = danoToSet; }
	inline void SetPosicion(const Vector3D& posicionToSet) { this->posicion = posicionToSet; }

	virtual void Desplazamiento(const float& timeIncrement) = 0;

	virtual bool Colision(Cylinder* Bala) = 0;

	virtual void Render() = 0;

	virtual void Update(const float& timeIncrement) = 0;

};

