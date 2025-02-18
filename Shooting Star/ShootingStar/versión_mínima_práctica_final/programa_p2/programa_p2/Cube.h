#pragma once
#include <GL/glut.h>
#include "Solid.h"

class Cube : public Solid
{
private:

	float size;

public:

	Cube() : Solid(Vector3D(0.0, 0.0, -0.2), Color(0.7, 0.2, 0.5), Vector3D(0.0, 0.0, 0.0)), size(0.9) { }
	Cube(float x, float y, float z) : Solid(Vector3D(x, y, z), Color(0.7, 0.2, 0.5), Vector3D(0.0, 0.0, 0.0)), size(0.9) { }

	inline float GetSize() const { return this->size; }

	inline void SetSize(float sizeToSet) { this->size = sizeToSet; }

	void Render();
};

