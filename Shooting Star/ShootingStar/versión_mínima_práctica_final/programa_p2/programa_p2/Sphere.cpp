#include "Sphere.h"

void Sphere::Render()
{
	glPushMatrix();
	glTranslatef(GetPosition().GetX(), GetPosition().GetY(), GetPosition().GetZ());
	glColor3f(GetColor().GetRed(), GetColor().GetGreen(), GetColor().GetBlue());
	glRotatef(GetOrientation().GetX(), 1.0, 0.0, 0.0);
	glRotatef(GetOrientation().GetY(), 0.0, 1.0, 0.0);
	glRotatef(GetOrientation().GetZ(), 0.0, 0.0, 1.0);
	this->GetIsTransparent() ? glutWireSphere(GetRadius(), GetSlices(), GetSlacks()) : glutSolidSphere(GetRadius(), GetSlices(), GetSlacks());
	glPopMatrix();
}
