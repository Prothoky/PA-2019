//
// Created by rcabido on 7/11/19.
//
#include "GameObject.h"

void GameObject::update(const float& time, const Vector3D& gravity)
{
    if (this->getIsAffectedByGravity())
    {
        this->setSpeed(Vector3D(this->getSpeed() + gravity * time));
    }
    this->setPosition(Vector3D(this->getPosition() + this->getSpeed() * time));
    this->setOrientation(
            Vector3D(
                    this->getOrientation().getX() + time * this->getOrientationSpeed().getX(),
                    this->getOrientation().getY() + time * this->getOrientationSpeed().getY(),
                    this->getOrientation().getZ() + time * this->getOrientationSpeed().getZ()
            )
    );
}