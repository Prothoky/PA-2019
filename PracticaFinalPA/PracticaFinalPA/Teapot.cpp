//
// Created by rcabido on 25/10/19.
//

#include "Teapot.h"
#include <GL/glut.h>

Teapot::Teapot(): GameObject() { }

Teapot::Teapot(const Vector3D &positionToSet, const Color &colorToSet, const Vector3D &speedToSet, const Vector3D &orientationToSet)
: GameObject(positionToSet, colorToSet, speedToSet, orientationToSet, Vector3D(), true, false) {}

void Teapot::render() const {
    glPushMatrix();
    glTranslatef(getPosition().getX(), getPosition().getY(), getPosition().getZ());
    glColor3f(getColor().getRed(), getColor().getGreen(), getColor().getBlue());
    glRotatef(getOrientation().getX(), 1.0, 0.0, 0.0);
    glRotatef(getOrientation().getY(), 0.0, 1.0, 0.0);
    glRotatef(getOrientation().getZ(), 0.0, 0.0, 1.0);
    glutSolidTeapot(0.25);
    glPopMatrix();
}

//void Teapot::update(const float &deltaTime, const Vector3D& gravity) {
//    setPosition(getPosition() + getSpeed() * deltaTime);
//    setOrientation(Vector3D(this->getOrientation().getX() + deltaTime, this->getOrientation().getY() + deltaTime, this->getOrientation().getZ() + deltaTime));
//
//}


