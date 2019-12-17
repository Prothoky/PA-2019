//
// Created by rcabido on 25/10/19.
//

#ifndef ENGINE_HERENCIA_CUBE_H
#define ENGINE_HERENCIA_CUBE_H

#include "Vector3D.h"
#include "GameObject.h"
#include <GL/glut.h>

class Cube : public GameObject {
private:
    float size;

public:

    Cube();

    Cube(const Vector3D &position, const Color &color, const Vector3D &speed, const Vector3D &orientation, float size = 1.0);

    float getSize() const { return this->size; }
    void setSize(const float& sizeToSet) { this->size = sizeToSet; }

    void render() const;
	bool checkCollisionZX(const float& z, const float& x) const;
    //void update(const float &deltaTime, const Vector3D& gravity);
};


#endif //ENGINE_HERENCIA_CUBE_H
