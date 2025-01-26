#include "Cube.h"

void Cube::Render()
{
	glPushMatrix();
	glTranslatef(GetPosition().GetX(), GetPosition().GetY(), GetPosition().GetZ());
	glColor3f(GetColor().GetRed(), GetColor().GetGreen(), GetColor().GetBlue());
	glRotatef(GetOrientation().GetX(), 1.0, 0.0, 0.0);
	glRotatef(GetOrientation().GetY(), 0.0, 1.0, 0.0);
	glRotatef(GetOrientation().GetZ(), 0.0, 0.0, 1.0);
	this->GetIsTransparent() ? glutWireCube(this->GetSize()) : glutSolidCube(this->GetSize());
	glPopMatrix();
}

// glutWireCube(this->GetSize()) renderiza de forma transparente
// glutSolidCube(this->GetSize()) renderiza sin ponerlo transparente