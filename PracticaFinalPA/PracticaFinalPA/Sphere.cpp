//
// Created by rcabido on 25/10/19.
//

#include "Sphere.h"
#include <GL/glut.h>

Sphere::Sphere(const Vector3D &position, const Color &color, const Vector3D &speed, const Vector3D &orientation, float radius, int slices, int stacks) :
GameObject(position, color, speed, orientation, Vector3D(), true, true), radius(radius), slices(slices), stacks(stacks) {}

void Sphere::render() const {
    glPushMatrix();
    glTranslatef(getPosition().getX(), getPosition().getY(), getPosition().getZ());
    glColor3f(getColor().getRed(), getColor().getGreen(), getColor().getBlue());
    glRotatef(getOrientation().getX(), 1.0, 0.0, 0.0);
    glRotatef(getOrientation().getY(), 0.0, 1.0, 0.0);
    glRotatef(getOrientation().getZ(), 0.0, 0.0, 1.0);
    glutSolidSphere(radius, slices, stacks);
    glPopMatrix();
}

bool Sphere::checkCollisionZX(const float& z, const float& x) const {
	bool collision = false;
	// POR RELLENAR
	return collision;
}

//void Sphere::update(const float &deltaTime, const Vector3D& gravity) {
//    setSpeed(Vector3D(this->getSpeed() + gravity * deltaTime));
//    setPosition(Vector3D(this->getPosition() + this->getSpeed() * deltaTime));
//}
