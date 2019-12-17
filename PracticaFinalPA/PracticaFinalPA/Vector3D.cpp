//
// Created by rcabido on 25/10/19.
//

#include "Vector3D.h"


Vector3D::Vector3D(const float &xCoord, const float &yCoord, const float &zCoord) {
    x = xCoord;
    y = yCoord;
    z = zCoord;
}

Vector3D::Vector3D(const float &value) {
    x = y = z = value;
}

float Vector3D::getX() const { return this->x; }

float Vector3D::getY() const { return this->y; }

float Vector3D::getZ() const { return this->z; }

void Vector3D::setX(const float &d) { this->x = d; }

void Vector3D::setY(const float &d) { this->y = d; }

void Vector3D::setZ(const float &d) { this->z = d; }

Vector3D Vector3D::add(const Vector3D &b) const {
    Vector3D result;
    result.x = x + b.x;
    result.y = y + b.y;
    result.z = z + b.z;
    return result;
}

Vector3D Vector3D::substract(const Vector3D &b) const {
    Vector3D result;
    result.x = x - b.x;
    result.y = y - b.y;
    result.z = z - b.z;
    return result;
}

Vector3D Vector3D::product(const float &b) const {
    Vector3D result;
    result.x = x * b;
    result.y = y * b;
    result.z = z * b;
    return result;
}

Vector3D Vector3D::product(const Vector3D &b) const {
    Vector3D result;
    result.x = x * b.x;
    result.y = y * b.y;
    result.z = z * b.z;
    return result;
}

Vector3D Vector3D::operator+(const float &b) const {
    Vector3D result;
    result.x = x + b;
    result.y = y + b;
    result.z = z + b;
    return result;
}

Vector3D Vector3D::operator+(const Vector3D &b) const {
    Vector3D result;
    result.x = x + b.x;
    result.y = y + b.y;
    result.z = z + b.z;
    return result;
}

Vector3D Vector3D::operator-(const float &b) const {
    Vector3D result;
    result.x = x - b;
    result.y = y - b;
    result.z = z - b;
    return result;
}

Vector3D Vector3D::operator-(const Vector3D &b) const {
    Vector3D result;
    result.x = x - b.x;
    result.y = y - b.y;
    result.z = z - b.z;
    return result;
}

Vector3D Vector3D::operator*(const float &b) const {
    Vector3D result;
    result.x = x * b;
    result.y = y * b;
    result.z = z * b;
    return result;
}

Vector3D Vector3D::operator*(const Vector3D &b) const {
    Vector3D result;
    result.x = x * b.x;
    result.y = y * b.y;
    result.z = z * b.z;
    return result;
}
