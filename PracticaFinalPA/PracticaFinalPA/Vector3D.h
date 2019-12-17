//
// Created by rcabido on 25/10/19.
//

#ifndef ENGINE_HERENCIA_VECTOR3D_H
#define ENGINE_HERENCIA_VECTOR3D_H


class Vector3D {
private:
    float x;
    float y;
    float z;

public:
    Vector3D(const float &xCoord, const float &yCoord, const float &zCoord);

    Vector3D(const float &value = 0.0);

    float getX() const;

    float getY() const;

    float getZ() const;

    void setX(const float &d);

    void setY(const float &d);

    void setZ(const float &d);

    Vector3D add(const Vector3D &b) const;

    Vector3D substract(const Vector3D &b) const;

    Vector3D product(const float &b) const;

    Vector3D product(const Vector3D &b) const;

    Vector3D operator+(const float &b) const;

    Vector3D operator+(const Vector3D &b) const;

    Vector3D operator-(const float &b) const;

    Vector3D operator-(const Vector3D& b) const;

    Vector3D operator*(const float &b) const;

    Vector3D operator*(const Vector3D &b) const;

};


#endif //ENGINE_HERENCIA_VECTOR3D_H
