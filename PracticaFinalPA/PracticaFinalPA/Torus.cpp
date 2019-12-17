#include "Torus.h"
#include <GL/glut.h>

void Torus::render()const
{
	glPushMatrix();
	glTranslatef(this->getPosition().getX(), (*this).getPosition().getY(), getPosition().getZ());
	glRotatef(getOrientation().getX(), 1.0, 0.0, 0.0);
	glRotatef(getOrientation().getY(), 0.0, 1.0, 0.0);
	glRotatef(getOrientation().getZ(), 0.0, 0.0, 1.0);
	glColor3f(getColor().getRed(), getColor().getGreen(), getColor().getBlue());
	glutSolidTorus(this->getInnerRadius(), this->getOuterRadius(), this->getSides(), this->getRings());
	glPopMatrix();
}