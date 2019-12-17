#pragma once
#include "GameObject.h"
#include <GL/glut.h>

class Cylinder : public GameObject
{
private:
	GLUquadricObj* quadratic;
	float radius;
	float height;
public:
	Cylinder(float radius, float height);
	~Cylinder();
	inline float getRadius() const { return this->radius; }
	inline void setRadius(const float& radiusToset) { this->radius = radiusToset; }
	inline float getHeight() const { return this->height; }
	inline void setHeight(const float& heightToset) { this->height = heightToset; }
	inline GLUquadricObj* getQuadratic() const { return this->quadratic; }

	void render()const;
	inline bool checkCollisionZX(const float& z, const float& x) const;
};

