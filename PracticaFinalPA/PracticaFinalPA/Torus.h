#pragma once
#include "GameObject.h"
class Torus : public GameObject
{
private:
	float innerRadius;										// Inner radius of the torus.
	float outerRadius;										// Outer radius of the torus.
	int sides;												// Number of sides for each radial section.
	int rings;												// Number of radial divisions for the torus.
public:
	Torus() :GameObject(), innerRadius(0.3f), outerRadius(1.0f), sides(20), rings(20) {}
	float getInnerRadius()const { return innerRadius; }
	void setInnerRadius(float ir) { innerRadius = ir; }
	float getOuterRadius()const { return outerRadius; }
	void setOuterRadius(float r) { outerRadius = r; }
	int getSides()const { return sides; }
	void setSides(int s) { sides = s; }
	int getRings()const { return rings; }
	void setRings(int r) { rings = r; }

	void render()const;
	bool checkCollisionZX(const float& z, const float& x) const { return false; }
};

