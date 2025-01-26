#pragma once
#include "Solid.h"
#include <GL/glut.h>

class Cuboid : public Solid
{
private:
    float length;
    float height;
    float width;
public:
    Cuboid() : length(0.4), height(0.7), width(0.1), Solid(Vector3D(), Color(0.2, 0.5, 0.1)) {}
    Cuboid(float x, float y, float z) : length(0.9), height(2), width(0.1), Solid(Vector3D(x,y,z), Color(0.2, 0.5, 0.1)) {}

    //Cuboid(float length, float height, float width) : length(length), height(height), width(width), Solid(Vector3D(), Color(0.2, 0.5, 0.1)) {}

    inline float GetLength() const { return this->length; }
    inline void SetLength(const float& lengthToSet) { this->length = lengthToSet; }
    inline float GetHeight() const { return this->height; }
    inline void SetHeight(const float& heightToSet) { this->height = heightToSet; }
    inline float GetWidth() const { return this->width; }
    inline void SetWidth(const float& widthToSet) { this->width = widthToSet; }

    void Render();
};

