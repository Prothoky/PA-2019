//
// Created by rcabido on 7/11/19.
//

#include "Camera.h"
#include <GL/glut.h>

Camera::Camera():GameObject()
{
	setIsAffectedByGravity(false);
	setCollidable(false);
}

Camera::Camera(const Vector3D &positionToSet, const Vector3D &orientationToSet) : GameObject(positionToSet, Color(), Vector3D(), orientationToSet, Vector3D(), false, false) {}


Camera::Camera(float x, float y, float z) : GameObject(Vector3D(x, y, z), Color(), Vector3D(), Vector3D(), Vector3D(), false, false) {}


void Camera::render() const{
    glTranslatef(-this->getPosition().getX(), -this->getPosition().getY(), -this->getPosition().getZ());
    glRotatef(getOrientation().getX(), 1.0, 0.0, 0.0);
    glRotatef(getOrientation().getY(), 0.0, 1.0, 0.0);
    glRotatef(getOrientation().getZ(), 0.0, 0.0, 1.0);
}

void Camera::update(const float &deltaTime,  const Vector3D& gravity){

}
