//
// Created by rcabido on 25/10/19.
//

#ifndef INC_0_06_ENGINE_STRUCTS_TEAPOT_H
#define INC_0_06_ENGINE_STRUCTS_TEAPOT_H

#include "Vector3D.h"
#include "GameObject.h"

class Teapot : public GameObject {

public:
    Teapot();
    Teapot(const Vector3D &positionToSet, const Color &colorToSet, const Vector3D &speedToSet = Vector3D(), const Vector3D &orientationToSet = Vector3D());

     void render() const;
	 inline bool checkCollisionZX(const float& z, const float& x) const { return false; }
    //void update(const float &deltaTime, const Vector3D& gravity);
};


#endif //INC_0_06_ENGINE_STRUCTS_TEAPOT_H
