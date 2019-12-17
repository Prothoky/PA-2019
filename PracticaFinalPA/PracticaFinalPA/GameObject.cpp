//
// Created by rcabido on 7/11/19.
//
#include "GameObject.h"

void GameObject::update(const float& time, const Vector3D& gravity)
{
    if (this->getIsAffectedByGravity())
    {
        this->setSpeed(Vector3D(this->getSpeed() + gravity * time));
    }
    this->setPosition(Vector3D(this->getPosition() + this->getSpeed() * time));
    this->setOrientation(
            Vector3D(
                    this->getOrientation().getX() + time * this->getOrientationSpeed().getX(),
                    this->getOrientation().getY() + time * this->getOrientationSpeed().getY(),
                    this->getOrientation().getZ() + time * this->getOrientationSpeed().getZ()
            )
    );
}


void GameObject::LoadModel(const string& filename)
{
	string line;
	ifstream modelFile(filename.c_str());
	if (modelFile.is_open())
	{
		while (modelFile.good())
		{
			getline(modelFile, line);
			if (line.c_str()[0] == 'v' && line.c_str()[1] == 't')
			{
				cout << ">>> Esto es una coordenada de textura de un v�rtice: \n";
				cout << line << "\n";
				line[0] = ' ';
				line[1] = ' ';
				this->textures.push_back(this->parseLineToVector3D(line));
				cout << ">>>>> tama�o de texture: " << this->textures.size() << "\n";
			}
			else if (line.c_str()[0] == 'v' && line.c_str()[1] == 'n')
			{
				cout << ">>> Esto es la normal de un v�rtice: \n";
				cout << line << "\n";
				line[0] = ' ';
				line[1] = ' ';
				this->normals.push_back(this->parseLineToVector3D(line));
				cout << ">>>>> tama�o de normals: " << this->normals.size() << "\n";
			}
			else if (line.c_str()[0] == 'v')
			{
				cout << ">>> Esto es un v�rtice: \n";
				cout << line << "\n";
				line[0] = ' ';
				this->vertexes.push_back(this->parseLineToVector3D(line));
				cout << ">>>>> tama�o de vertexes: " << this->vertexes.size() << "\n";

			}
			else if (line.c_str()[0] == 'f')
			{
				cout << ">>> Esto es una cara: \n";
				cout << line << "\n";

				line[0] = ' ';
				this->triangles.push_back(this->parseFace(line));

			}
			else if (line.c_str()[0] == '#')
			{
				cout << ">>> Esto es un comentario: \n";
				cout << line << "\n";
			}
			else
			{
				cout << ">>> Esto no se sabe lo que es: \n";
				cout << line << "\n";
			}
		}
		modelFile.close();
	}
}

Vector3D* GameObject::parseLineToVector3D(string& line)
{
	istringstream lineManager(line);
	float x = 0.0;
	float y = 0.0;
	float z = 0.0;
	lineManager >> x;
	lineManager >> y;
	lineManager >> z;
	Vector3D* vector = new(nothrow) Vector3D(x, y, z);
	return vector;
}

Triangle* GameObject::parseFace(string& line)
{
	istringstream lineManager(line);
	int firstVertexIndex = 0;
	//int firstVertexTexture = 0;
	int firstVertexNormal = 0;

	int secondVertexIndex = 0;
	//int secondVertexTexture = 0;
	int secondVertexNormal = 0;

	int thirdVertexIndex = 0;
	//int thirdVertexTexture = 0;
	int thirdVertexNormal = 0;

	char c;
	lineManager >> firstVertexIndex >> c >> c >> firstVertexNormal;
	lineManager >> secondVertexIndex >> c >> c >> secondVertexNormal;
	lineManager >> thirdVertexIndex >> c >> c >> thirdVertexNormal;

	cout << firstVertexIndex << "/" << "/" << firstVertexNormal << endl;
	cout << secondVertexIndex << "/" << "/" << secondVertexNormal << endl;
	cout << thirdVertexIndex << "/" << "/" << thirdVertexNormal << endl;

	Vector3D triangleVertex1 = *this->vertexes[--firstVertexIndex];
	Vector3D triangleVertex2 = *this->vertexes[--secondVertexIndex];
	Vector3D triangleVertex3 = *this->vertexes[--thirdVertexIndex];
	Vector3D triangleNormal = *this->normals[--firstVertexNormal];
	Triangle* triangle = new(nothrow) Triangle(
		triangleVertex1,
		triangleVertex2,
		triangleVertex3,
		triangleNormal);
	return triangle;
}
