#ifndef ENGINE_PLAYER
#define ENGINE_PLAYER

#include "Vector3D.h"
#include "GameObject.h"
#include <GL/glut.h>

class Player : public GameObject {
private:
	float collisionPoints[4] = { -1.0, 4, 1.0, 4 };	//Coordenadas de los puntos de colisión. Van x, z para cada punto (x[0], z[0], x[1], z[1], x[2], z[2]...)
	int collisionPointsNumber = 2;	//Número de puntos de colisión

public:
	Player(const Vector3D &position);
	Player(const Vector3D &position, float* collisionPoints, const int &collisionPointsNumber);

	inline int getCollisionPointsNumber() const { return collisionPointsNumber; }
	inline float* getCollisionPoints() { return collisionPoints; }
	//esta no va por que?
	//inline void setCollisionPoints(float* collisionPoints) { this->collisionPoints = collisionPoints; }

	void render() const;
	bool checkCollisionZX(const float& z, const float& x) const { return false; };
	//void update(const float &deltaTime, const Vector3D& gravity);

	void processKeyPressed(unsigned char key, int px, int py);
};


#endif //ENGINE_PLAYER
