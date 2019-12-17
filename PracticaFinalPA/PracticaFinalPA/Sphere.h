//
// Created by rcabido on 25/10/19.
//

#ifndef ENGINE_HERENCIA_SPHERE_H
#define ENGINE_HERENCIA_SPHERE_H

#include "Vector3D.h"
#include "Color.h"
#include "GameObject.h"

class Sphere : public GameObject {
private:
    float radius;
    int slices;
    int stacks;

public:
    Sphere(const Vector3D &position, const Color &color, const Vector3D &speed, const Vector3D &orientation, float radius = 1.0, int slices = 20, int stacks = 20);

    void render() const;
	bool checkCollisionZX(const float& z, const float& x) const;
    //void update(const float &deltaTime, const Vector3D& gravity);

};


#endif //ENGINE_HERENCIA_SPHERE_H
