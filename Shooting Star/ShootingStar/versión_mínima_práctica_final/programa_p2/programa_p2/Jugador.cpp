#include "Jugador.h"

Cylinder* Jugador::Disparo(const float& timeIncrement) {
	Cylinder* Bala = new Cylinder();
	/*new Cylinder(0.15, 0.15, 1.3, 16, 16, this->GetposDisparo(), Color(0.6, 0.6, 0.7))*/
	Bala->SetPosition(this->GetposDisparo());
	Bala->SetSpeed(Vector3D(0., GetVelocidadAtaque() * timeIncrement, 0));
	Bala->SetHeight(1.3);
	Bala->SetColor(Color(0.2, 0.2, 0.7));
	Bala->SetOrientation(Vector3D(90., 0., 0.));
	Bala->SetOrientationSpeed(Vector3D(0.0, 0., 0.));
	

	return Bala;
}

bool Jugador::Colision(Cylinder* Bala) {
	float yBalaDown;
	float y;
	float xBalaDown;
	float x;
	float heightBala;
	float heightModel;
	
	heightBala = Bala->GetHeight();
	yBalaDown = Bala->GetPosition().GetY();
	y = this->GetModel().GetPosition().GetY();
	
	xBalaDown = Bala->GetPosition().GetX();
	x = this->GetModel().GetPosition().GetX();

	if ((yBalaDown <= (y + 1)) && (((xBalaDown - 0.15) >= (x - 1)) && (xBalaDown - 0.15) <= (x + 1))) {
		return true;
	}
	else {
		return false;
	}

	
}

void Jugador::Desplazamiento(const float& timeIncrement) {

}

void Jugador::Render() {
	
	glPushMatrix();
	glTranslatef(GetModel().GetPosition().GetX(), GetModel().GetPosition().GetY(), GetModel().GetPosition().GetZ());
	glColor3f(GetModel().GetColor().GetRed(), GetModel().GetColor().GetGreen(), GetModel().GetColor().GetBlue());
	glRotatef(GetModel().GetOrientation().GetX(), 1.0, 0.0, 0.0);
	glRotatef(GetModel().GetOrientation().GetY(), 0.0, 1.0, 0.0);
	glRotatef(GetModel().GetOrientation().GetZ(), 0.0, 0.0, 1.0);

	vector <Triangle> triangles = GetModel().GetTriangle();
	for (Triangle& triangle : triangles)
	{
		triangle.Render();
	}

	glPopMatrix();
}

void Jugador::Update(const float& timeIncrement) {

	Model* estrella2 = new Model();
	*estrella2 = this->GetModel();
	estrella2->SetPosition(estrella2->GetPosition() + estrella2->GetSpeed() * timeIncrement);
	estrella2->SetOrientation(estrella2->GetOrientation() + estrella2->GetOrientationSpeed() * timeIncrement);

	this->SetModel(*estrella2);
}
