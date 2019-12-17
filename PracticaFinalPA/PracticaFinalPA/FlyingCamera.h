#pragma once
#include "Camera.h"
class FlyingCamera : public Camera
{
private:
	int mouseCoordinateX;
	int mouseCoordinateY;
public:
	FlyingCamera() : Camera(), mouseCoordinateX(0), mouseCoordinateY(0) {}
	FlyingCamera(const Vector3D &positionToSet, const Vector3D &orientationToSet) : Camera(positionToSet, orientationToSet) {}
	FlyingCamera(float x, float y, float z) : Camera(x, y, z), mouseCoordinateX(0), mouseCoordinateY(0) {}

	inline float getMouseCoordinateX() const { return this->mouseCoordinateX; }
	inline void setMouseCoordinateX(const int& mouseX) { this->mouseCoordinateX = mouseX; }
	inline float getMouseCoordinateY() const { return this->mouseCoordinateY; }
	inline void setMouseCoordinateY(const int& mouseY) { this->mouseCoordinateY = mouseY; }

	void render();
	void update(const float& time, const Vector3D& gravity) override;

	void processMouseMovement(const int& x, const int& y);
	void processMouseClick(const int& button, const int& state, const int& x, const int& y);
	void processKeyPressed(unsigned char key, int px, int py);
};

