#include "Player.h"
/*
class Player : public GameObject {
private:
	float* xCollisionPoints;	//Coordenadas x de los puntos de colisión
	float* zCollisionPoints;	//Coordenadas z de los puntos de colisión
	int collisionPointsNumber;	//Número de puntos de colisión

public:
	Player(const Vector3D &position, const float* xCollisionPoints, const float* zCollisionPoints, const int &collisionPoints);

	inline int getCollisionPointsNumber() const { return collisionPointsNumber; }
	float* getCollisionPoints() const;
	void setCollisionPoints(const float* xCollisionPoints, const float* zCollisionPoints);

	void render() const;
	bool checkCollisionZX(const float& z, const float& x) const { return false };
	//void update(const float &deltaTime, const Vector3D& gravity);
};

Vector3D position;
Color color;
Vector3D speed;
Vector3D orientation;
Vector3D orientationSpeed;
bool isAffectedByGravity;
bool collidable;
*/

Player::Player(const Vector3D &position) : GameObject(position, Color(), Vector3D(0.25), Vector3D(), Vector3D(), false, false) {
	//this->collisionPointsNumber = 2;
	//float collisionPoints[] = { 0.5, 0.0, -0.5, 0.0 };
	//this->collisionPoints = collisionPoints;
}

Player::Player(const Vector3D &position, float* collisionPoints, const int &collisionPointsNumber) : GameObject(position, Color(), Vector3D(0.02), Vector3D(), Vector3D(), false, false),
collisionPoints(), collisionPointsNumber(collisionPointsNumber) {}

void Player::render() const {
	glPushMatrix();
	glScalef(0.75, 0.75, 0.75);
	glTranslatef(getPosition().getX(), getPosition().getY(), getPosition().getZ());
	glRotatef(getOrientation().getX(), 1.0, 0.0, 0.0);
	glRotatef(getOrientation().getY(), 0.0, 1.0, 0.0);
	glRotatef(getOrientation().getZ(), 0.0, 0.0, 1.0);
	glColor3f(getColor().getRed(), getColor().getGreen(), getColor().getBlue());
	//Este sería el cono de colision deberia comentarse para que no se vea
	glutSolidCone(1.0, 3.0, 15, 15);
	for (Triangle* triangle : this->gettriangles())
	{
		triangle->Render();
	}
	glPopMatrix();
}

void Player::processKeyPressed(unsigned char key, int px, int py)
{
	Vector3D newPosition = this->getPosition();
	switch (key) {
	case 'a':
	case 'A':
		newPosition.setZ(newPosition.getZ() - this->getSpeed().getZ());
		collisionPoints[0] -= this->getSpeed().getZ();
		collisionPoints[2] -= this->getSpeed().getZ();
		this->setPosition(newPosition);
		break;
	case 'd':
	case 'D':
		newPosition.setZ(newPosition.getZ() + this->getSpeed().getZ());
		collisionPoints[0] += this->getSpeed().getZ();
		collisionPoints[2] += this->getSpeed().getZ();
		this->setPosition(newPosition);
		break;
	}
}
