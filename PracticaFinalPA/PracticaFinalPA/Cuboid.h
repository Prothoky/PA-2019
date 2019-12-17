#pragma once
#include "GameObject.h"
class Cuboid : public GameObject
{
private:
	float height;											// Dimensi�n en el eje y
	float length;											// Dimensi�n en el eje x
	float width;											// Dimensi�n en el eje z
public:
	Cuboid() : GameObject(), height(1.0f), length(2.0f), width(0.5f) {}

	inline float getHeight() const { return this->height; }
	inline void setHeight(const float& heightToset) { this->height = heightToset; }
	inline float getLength() const { return this->length; }
	inline void setLength(const float& lengthToset) { this->length = lengthToset; }
	inline float getWidth() const { return this->width; }
	inline void setWidth(const float& widthToset) { this->width = widthToset; }

	void render()const;
	inline bool checkCollisionZX(const float& z, const float& x) const { return false; }
};

