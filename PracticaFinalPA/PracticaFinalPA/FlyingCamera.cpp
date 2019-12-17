#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include "FlyingCamera.h"
#include <GL/glut.h>

void FlyingCamera::render() {
	glRotatef(getOrientation().getX(), 1.0, 0.0, 0.0);
	glRotatef(getOrientation().getY(), 0.0, 1.0, 0.0);
	glRotatef(getOrientation().getZ(), 0.0, 0.0, 1.0);
	glTranslatef(-this->getPosition().getX(), -this->getPosition().getY(), -this->getPosition().getZ());
}

void FlyingCamera::update(const float& time, const Vector3D& gravity)
{
	float yOrientationInRadians = this->getOrientation().getY() * M_PI / 180;
	float xOrientationInRadians = this->getOrientation().getX() * M_PI / 180;
	float xComponent = -cos(xOrientationInRadians) * sin(yOrientationInRadians);
	float yComponent = sin(xOrientationInRadians);
	float zComponent = cos(xOrientationInRadians) * cos(yOrientationInRadians);
	Vector3D velocity(xComponent, yComponent, zComponent);
	this->setPosition(this->getPosition() -  velocity * time);

	std::cout << "X: " << this->getPosition().getX() << " Y: " << this->getPosition().getY() << " Z: " << this->getPosition().getZ() << std::endl;
	std::cout << "P: " << this->getOrientation().getX() << " Y: " << this->getOrientation().getY() << " R: " << this->getOrientation().getZ() << std::endl;

}

void FlyingCamera::processMouseMovement(const int& x, const int& y) 
{
	this->setOrientation(this->getOrientation() + Vector3D(y - this->getMouseCoordinateY(), x - this->getMouseCoordinateX(), 0.0));
	this->setMouseCoordinateX(x);
	this->setMouseCoordinateY(y);
}

void FlyingCamera::processMouseClick(const int& button, const int& state, const int& x, const int& y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		this->setMouseCoordinateX(x);
		this->setMouseCoordinateY(y);
	}
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
		this->setMouseCoordinateX(0);
		this->setMouseCoordinateY(0);
	}
}

void FlyingCamera::processKeyPressed(unsigned char key, int px, int py)
{
	switch (key) {
	case 'w':
	case 'W':
		this->update(0.1f, Vector3D());
		break;
	case 's':
	case 'S':
		this->update(-0.1f, Vector3D());
		break;
	}
}

