#include "Cylinder.h"

Cylinder::Cylinder(float baseRadius, float cylinderHeight) {
	this->quadratic = gluNewQuadric();
	this->radius = baseRadius;
	this->height = cylinderHeight;
}

Cylinder::~Cylinder()
{
	delete quadratic;
}

void Cylinder::render()const {
	glPushMatrix();
	glColor3f(this->getColor().getRed(), this->getColor().getGreen(), this->getColor().getBlue());
	glTranslatef(this->getPosition().getX(), this->getPosition().getY(), this->getPosition().getZ());
	glRotatef(getOrientation().getX(), 1.0, 0.0, 0.0);
	glRotatef(getOrientation().getY(), 0.0, 1.0, 0.0);
	glRotatef(getOrientation().getZ(), 0.0, 0.0, 1.0);
	gluCylinder(this->getQuadratic(), this->getRadius(), this->getRadius(), this->getHeight(), 16, 16);
	glPopMatrix();
}

bool Cylinder::checkCollisionZX(const float& z, const float& x) const {
	bool collision = false;
	// POR RELLENAR
	return collision;
}
