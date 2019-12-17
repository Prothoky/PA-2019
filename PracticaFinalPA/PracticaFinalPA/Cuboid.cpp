#include "Cuboid.h"
#include <GL/glut.h>

void Cuboid::render()const
{
	glPushMatrix();
	glTranslatef(this->getPosition().getX(), this->getPosition().getY(), this->getPosition().getZ());
	glRotatef(getOrientation().getX(), 1.0, 0.0, 0.0);
	glRotatef(getOrientation().getY(), 0.0, 1.0, 0.0);
	glRotatef(getOrientation().getZ(), 0.0, 0.0, 1.0);
	glColor3f(getColor().getRed(), getColor().getGreen(), getColor().getBlue());
	glScalef(getLength(), getHeight(), getWidth());
	glutSolidCube(1);
	glPopMatrix();
}

