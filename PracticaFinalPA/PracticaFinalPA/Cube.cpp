//
// Created by rcabido on 25/10/19.
//

#include "Cube.h"

Cube::Cube() : GameObject(), size(1.0) {}

Cube::Cube(const Vector3D &position, const Color &color, const Vector3D &speed, const Vector3D &orientation, float size):
GameObject(position, color, speed, orientation, Vector3D(), true, true), size(size) {}

void Cube::render() const {

    glPushMatrix();
    glTranslatef(getPosition().getX(), getPosition().getY(), getPosition().getZ());
    glRotatef(getOrientation().getX(), 1.0, 0.0, 0.0);
    glRotatef(getOrientation().getY(), 0.0, 1.0, 0.0);
    glRotatef(getOrientation().getZ(), 0.0, 0.0, 1.0);
    glColor3f(getColor().getRed(), getColor().getGreen(), getColor().getBlue());
    glutSolidCube(getSize());
	for (Triangle* triangle : this->gettriangles())
	{
		triangle->Render();
	}
    glPopMatrix();
}

bool Cube::checkCollisionZX(const float& z, const float& x) const {
	bool collision = false;
	if (z < getPosition().getZ() + getSize() / 2 && z > getPosition().getZ() - getSize() / 2) {	//Comprobamos si está en el rango de las z (más rápido que de la otra manera)
		if (x < getPosition().getX() + getSize() / 2 && x > getPosition().getX() - getSize() / 2) {	//Comprobamos si está en el rango de las x
			collision = true;
		}
	}
	return collision;
}

//void Cube::update(const float &deltaTime, const Vector3D& gravity) {
//
//    this->setSpeed(Vector3D(this->getSpeed() + gravity * deltaTime));
//    this->setPosition(Vector3D(this->getPosition() + this->getSpeed() * deltaTime));
//    this->setOrientation(Vector3D(this->getOrientation().getX() + deltaTime * 1, this->getOrientation().getY() + deltaTime * 0, this->getOrientation().getZ() + deltaTime * 1));
//}