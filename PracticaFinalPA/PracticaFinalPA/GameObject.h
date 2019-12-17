//
// Created by rcabido on 7/11/19.
//

#ifndef ENGINE_HERENCIA_GAMEOBJECT_H
#define ENGINE_HERENCIA_GAMEOBJECT_H

#include "Vector3D.h"
#include "Color.h"

class GameObject {
private:
    Vector3D position;
    Color color;
    Vector3D speed;
    Vector3D orientation;
    Vector3D orientationSpeed;
    bool isAffectedByGravity;
	bool collidable;	//Determina si un objeto puede producir una colisión o no
public:
    GameObject() : position(Vector3D()), color(Color()), speed(Vector3D()), orientation(Vector3D()), orientationSpeed(Vector3D()), isAffectedByGravity(true), collidable(true) {}

    GameObject(const Vector3D &position, const Color &color, const Vector3D &speed, const Vector3D &orientation, const Vector3D &orientationSpeed, bool isAffectedByGravity, bool collidable) :
            position(position), color(color), speed(speed), orientation(orientation), orientationSpeed(orientationSpeed), isAffectedByGravity(isAffectedByGravity), collidable(collidable) {}

    Vector3D getPosition() const { return this->position; }
    Color getColor() const { return this->color; }
    Vector3D getSpeed() const { return this->speed; }
    Vector3D getOrientation() const { return this->orientation; }
    Vector3D getOrientationSpeed() const { return this->orientationSpeed; }
    bool getIsAffectedByGravity() const { return this->isAffectedByGravity; }
	bool getCollidable() const { return this->collidable; };
    void setPosition(const Vector3D &vector) { this->position = vector; }
    void setColor(const Color &colorToSet) { this->color = colorToSet; }
    void setSpeed(const Vector3D &vector) { this->speed = vector; }
    void setOrientation(const Vector3D& vector) { this->orientation = vector; }
    void setOrientationSpeed(const Vector3D& vector) { this->orientationSpeed = vector; }
    void setIsAffectedByGravity(const bool& isAffectedByGravity) { this->isAffectedByGravity = isAffectedByGravity; }
	void setCollidable(const bool& collidable) { this->collidable = collidable; }

    virtual void render() const=0;

    virtual void update(const float &deltaTime, const Vector3D& gravity); //virtual void update(const float &deltaTime, const int &limit) = 0;

	virtual bool checkCollisionZX(const float& z, const float& x) const = 0;	//Devuelve si la posición pasada como parámetro colisiona (tienendo en cuenta únicamente las coordenadas z, x)
};


#endif //ENGINE_HERENCIA_SOLID_H
