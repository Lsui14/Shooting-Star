#include "Enemigo1.h"
#include <ctime>
#include <stdlib.h>
#include <iostream>

using namespace std;
void Enemigo1::Desplazamiento(const float& timeIncrement) {
	
	float azar;

	srand((unsigned)time(0));
	azar = (rand() % 50);
	

	Cube* cubo = new Cube();
	*cubo = this->GetFigura();

	if (azar < 15) {
		/*cubo->SetPosition((Vector3D(cubo->GetPosition().GetX() + 0.001, this->GetFigura().GetPosition().GetY(), this->GetFigura().GetPosition().GetZ())));*/
		cubo->SetSpeed(Vector3D(GetVelocidadMovimiento() * timeIncrement, 0, 0));
	}
	else if(azar < 30) {
		/*cubo->SetPosition((Vector3D(this->GetFigura().GetPosition().GetX() - 0.001, this->GetFigura().GetPosition().GetY(), this->GetFigura().GetPosition().GetZ())));*/
		cubo->SetSpeed(Vector3D(-GetVelocidadMovimiento() * timeIncrement, 0, 0));
	}
	else {
		/*cubo->SetPosition((Vector3D(this->GetFigura().GetPosition().GetX(), this->GetFigura().GetPosition().GetY() + 0.001, this->GetFigura().GetPosition().GetZ())));*/
		cubo->SetSpeed(Vector3D(0.0, -GetVelocidadMovimiento() * timeIncrement, 0));
	}
	this->SetFigura(*cubo);
}
bool Enemigo1::Colision(Cylinder* Bala) {
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

	if ((yBala >= (y + heightModel/2)) && (xBala >= (x - (heightModel / 2))) && (xBalaD <= (x + (heightModel / 2))) && (yBalaDown <= (y + (heightModel)))) {
		return true;
	}
	
	else {
		return false;
	}

	
}
void Enemigo1::Render() {
	
	GetFigura().Render();
}

void Enemigo1::Update(const float& timeIncrement) {
	Cube* cubo = new Cube();
	*cubo = this->GetFigura();

	cubo->SetPosition(cubo->GetPosition() + cubo->GetSpeed() * timeIncrement);
	cubo->SetOrientation(cubo->GetOrientation() + cubo->GetOrientationSpeed() * timeIncrement);

	this->SetFigura(*cubo);
	
	this->Desplazamiento(timeIncrement);
	
}

bool Enemigo1::Impacto(float limite) {
	Cube* cube = new Cube();
	*cube = this->GetFigura();
	if ((cube->GetPosition().GetY() - (cube->GetSize()/2) ) <= limite) {
		return true;
	}
	else {
		return false;
	}
}
