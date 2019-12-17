//
// Created by rcabido on 7/11/19.
//

#ifndef ENGINE_HERENCIA_CAMERA_H
#define ENGINE_HERENCIA_CAMERA_H

#include "Vector3D.h"
#include "GameObject.h"

class Camera: public GameObject {

public:
    Camera();
    Camera(const Vector3D &positionToSet, const Vector3D &orientationToSet);
    Camera(float x, float y, float z);

    void render() const;
    void update(const float &deltaTime,  const Vector3D& gravity);
	inline bool checkCollisionZX(const float& z, const float& x) const { return false; };
};


#endif //ENGINE_HERENCIA_CAMERA_H
