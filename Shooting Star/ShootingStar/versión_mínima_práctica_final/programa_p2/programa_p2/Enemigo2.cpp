#include "Enemigo2.h"
#include <ctime>
#include <stdlib.h>
#include <iostream>


void Enemigo2::Desplazamiento(const float& timeIncrement) {

	float azar;

	srand((unsigned)time(0));
	azar = (rand() % 70);
	

	Sphere* sphere = new Sphere();
	*sphere = this->GetFigura();

	if (azar < 15) {
		/*cubo->SetPosition((Vector3D(cubo->GetPosition().GetX() + 0.001, this->GetFigura().GetPosition().GetY(), this->GetFigura().GetPosition().GetZ())));*/
		sphere->SetSpeed(Vector3D(GetVelocidadMovimiento() * timeIncrement, 0, 0));
	}
	else if (azar < 30) {
		/*cubo->SetPosition((Vector3D(this->GetFigura().GetPosition().GetX() - 0.001, this->GetFigura().GetPosition().GetY(), this->GetFigura().GetPosition().GetZ())));*/
		sphere->SetSpeed(Vector3D(-GetVelocidadMovimiento() * timeIncrement, 0, 0));
	}
	else if (azar<40) {
		/*cubo->SetPosition((Vector3D(this->GetFigura().GetPosition().GetX(), this->GetFigura().GetPosition().GetY() + 0.001, this->GetFigura().GetPosition().GetZ())));*/
		sphere->SetSpeed(Vector3D(0.0, -GetVelocidadMovimiento() * timeIncrement, 0));
	}
	else if (azar < 50) {
		sphere->SetSpeed(Vector3D(GetVelocidadMovimiento() * timeIncrement, -GetVelocidadMovimiento() * timeIncrement, 0));
	}
	else {
		sphere->SetSpeed(Vector3D(-GetVelocidadMovimiento() * timeIncrement, -GetVelocidadMovimiento() * timeIncrement, 0));
	}
	this->SetFigura(*sphere);
}

bool Enemigo2::Colision(Cylinder* Bala) {
	float yBalaDown;
	float yBala;
	float y;
	float xBalaD;
	float xBala;
	float radio;
	float x;
	float heightBala;
	float heightModel;


	heightModel = this->GetFigura().GetRadius();
	radio = Bala->GetBaseRadius();
	heightBala = Bala->GetHeight();
	yBala = Bala->GetPosition().GetY() + heightBala;
	yBalaDown = Bala->GetPosition().GetY();
	y = this->GetFigura().GetPosition().GetY();

	xBala = Bala->GetPosition().GetX() - radio;
	xBalaD = Bala->GetPosition().GetX() + radio;
	x = this->GetFigura().GetPosition().GetX();

	if ((yBala >= (y + heightModel)) && (xBala >= (x - (heightModel))) && (xBalaD <= (x + (heightModel))) && (yBalaDown <= (y + (heightModel)))) {
		return true;
	}

	else {
		return false;
	}
}

void Enemigo2::Render() {
	GetFigura().Render();
}

void Enemigo2::Update(const float& timeIncrement) {
	Sphere* sphere = new Sphere();
	*sphere = this->GetFigura();

	sphere->SetPosition(sphere->GetPosition() + sphere->GetSpeed() * timeIncrement);
	sphere->SetOrientation(sphere->GetOrientation() + sphere->GetOrientationSpeed() * timeIncrement);

	this->SetFigura(*sphere);

	this->Desplazamiento(timeIncrement);
}

bool Enemigo2::Impacto(float limite) {
	Sphere* sphere = new Sphere();
	*sphere = this->GetFigura();
	if ((sphere->GetPosition().GetY() - (sphere->GetRadius())) <= limite) {
		return true;
	}
	else {
		return false;
	}
}
