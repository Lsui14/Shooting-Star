#include "Torreta.h"
#include <ctime>
#include <stdlib.h>
#include <iostream>

Cylinder* Torreta::Disparo(const float& timeIncrement) {
	Cylinder* Bala = new Cylinder();
	/*new Cylinder(0.15, 0.15, 1.3, 16, 16, this->GetposDisparo(), Color(0.6, 0.6, 0.7))*/
	Bala->SetPosition(this->GetposDisparo());
	Bala->SetSpeed(Vector3D(0., -timeIncrement * 0.01, 0));
	Bala->SetHeight(1.3);
	Bala->SetColor(Color(0.2, 0.2, 0.7));
	Bala->SetOrientation(Vector3D(90., 0., 0.));
	Bala->SetOrientationSpeed(Vector3D(0.0, 0., 0.));


	return Bala;
}

void Torreta::Desplazamiento(const float& timeIncrement) {
	float azar;

	srand((unsigned)time(0));
	azar = (rand() % 50);
	

	Cuboid* canon = new Cuboid();
	*canon = this->GetCanon();

	if (azar < 25) {
		/*cubo->SetPosition((Vector3D(cubo->GetPosition().GetX() + 0.001, this->GetFigura().GetPosition().GetY(), this->GetFigura().GetPosition().GetZ())));*/
		canon->SetOrientationSpeed(Vector3D(0, 0, GetVelocidadMovimiento() * timeIncrement));
		SetPosDisparo(Vector3D(GetposDisparo().GetX() + GetVelocidadMovimiento()/100, GetposDisparo().GetY(), GetposDisparo().GetZ()));
	}
	else  {
		/*cubo->SetPosition((Vector3D(this->GetFigura().GetPosition().GetX() - 0.001, this->GetFigura().GetPosition().GetY(), this->GetFigura().GetPosition().GetZ())));*/
		canon->SetOrientationSpeed(Vector3D(0, 0, -GetVelocidadMovimiento() * timeIncrement));
		SetPosDisparo(Vector3D(GetposDisparo().GetX() - GetVelocidadMovimiento()/100, GetposDisparo().GetY(), GetposDisparo().GetZ()));
	}
	
	this->SetCanon(*canon);
}

bool Torreta::Colision(Cylinder* Bala) {
	float yBalaDown;
	float yBala;
	float y;
	float xBalaD;
	float xBala;
	float radio;
	float x;
	float heightBala;
	float heightModel;

	heightModel = this->GetFigura().GetSize();
	radio = Bala->GetBaseRadius();
	heightBala = Bala->GetHeight();
	yBala = Bala->GetPosition().GetY() + heightBala;
	yBalaDown = Bala->GetPosition().GetY();
	y = this->GetFigura().GetPosition().GetY();

	xBala = Bala->GetPosition().GetX() - radio;
	xBalaD = Bala->GetPosition().GetX() + radio;
	x = this->GetFigura().GetPosition().GetX();

	if ((yBala >= (y + heightModel / 2)) && (xBala >= (x - (heightModel / 2))) && (xBalaD <= (x + (heightModel / 2))) && (yBalaDown <= (y + (heightModel)))) {
		return true;
	}

	else {
		return false;
	}
}

void Torreta::Render() {
	GetFigura().Render();
	GetCanon().Render();
}

void Torreta::Update(const float& timeIncrement) {
	Cuboid* canon = new Cuboid();
	*canon = this->GetCanon();

	
	canon->SetOrientation(canon->GetOrientation() + canon->GetOrientationSpeed() * timeIncrement);

	this->SetCanon(*canon);

	this->Desplazamiento(timeIncrement);
}
