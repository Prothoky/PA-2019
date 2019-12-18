#include <stdlib.h>

#include "Game.h"
#include "Cube.h"
#include "Cylinder.h"
#include "Cuboid.h"

void Game::create()
{
	/*
	const Vector3D &sizeToSet = Vector3D(10.0, 10.0, 10.0), const Vector3D &cameraPosition = Vector3D(5.0, 0.0,
		20.0),
		const Vector3D &cameraOrientation = Vector3D(), const Vector3D &gravity = Vector3D(0.0, -0.01, 0.0) */
   
	Scene* mainScene = new Scene(Vector3D(0.0f, 10.0f, 0.0f), Vector3D(100.0f, 10.0f, 10.0f));
	FlyingCamera mainCamera = mainScene->getCamera();
	mainCamera.setPosition(Vector3D(-4.0f, 10.0f, 0.0f));
	mainCamera.setOrientation(Vector3D(32.0f, 90.0f, 0.0f));
	mainScene->setCamera(mainCamera);


	//Configuramos Player
	Player player(Vector3D(4.0f, 3.0f, 0.0f));
	player.setColor(Color(1.0f, 1.0f, 1.0f));
	player.setOrientation(Vector3D(0.0f, 90.0f, 0.0f));
    player.LoadModel("Spaceship.obj");
	mainScene->setPlayer(player);

	//Creamos 5 cubos en el suelo a una distancia variable entre 50 y 100 de longitud
	int numberOfCubes = 3;
	Cube* cubes = new Cube[numberOfCubes];
	for (int index = 0; index < numberOfCubes; index++)
	{
		cubes[index] = Cube();
		cubes[index].setPosition(Vector3D(rand() % 50 + 50, 2.5f, rand() % 20 - 10));
		cubes[index].setOrientation(Vector3D(1.0f, 0.0f, 0.0f));
		cubes[index].setColor(Color(1.0f, 0.1f, 0.1f));
		cubes[index].setSize(2.0f);
		cubes[index].setIsAffectedByGravity(false);
		cubes[index].setSpeed(Vector3D(-0.2f, 0.0f, 0.0f));
		cubes[index].setOrientationSpeed(Vector3D(0.0f));
		cubes[index].LoadModel("Asteroid_round.obj");
		mainScene->addObstacleObject(cubes + index);
	}

	int numberOfCylinders = 3;
	Cylinder* cylinders = new Cylinder[numberOfCylinders];
	for (int index = 0; index < numberOfCylinders; index++)
	{
		cylinders[index] = Cylinder();
		cylinders[index].setPosition(Vector3D(rand() % 50 + 50, 2.5f, rand() % 19 - 9));
		cylinders[index].setOrientation(Vector3D(-90.0f, 0.0f, 0.0f));
		cylinders[index].setColor(Color(1.0f, 0.1f, 0.1f));
		cylinders[index].setIsAffectedByGravity(false);
		cylinders[index].setSpeed(Vector3D(-0.2f, 0.0f, 0.0f));
		cylinders[index].setOrientationSpeed(Vector3D(0.0f));
		cylinders[index].LoadModel("Asteroid.obj");
		mainScene->addObstacleObject(cylinders + index);
	}


	//Suelo
    Cuboid* floor = new Cuboid();
    floor->setPosition(Vector3D(50.0f, 0.0f, 0.0f));
    floor->setColor(Color(0.2f, 0.9f, 0.2f));
    floor->setHeight(2.0f);
    floor->setLength(200.0f);
    floor->setWidth(25.0f);
    floor->setIsAffectedByGravity(false);
	floor->setCollidable(false);
    mainScene->addSceneObject(floor);


    this->scenes.push_back(mainScene);
    this->activeScene = mainScene;
}

void Game::render()
{
	this->activeScene->render();
}

void Game::update()
{
	this->activeScene->update(this->deltaTime);
}

void Game::processMouseMovement(const int& xPosition, const int& yPosition)
{
    this->activeScene->processMouseMovement(xPosition, yPosition);
}

void Game::processKeyPressed(const unsigned char& key, const int& xPosition, const int& yPosition)
{
    this->activeScene->processKeyPressed(key, xPosition, yPosition);
    switch (key) {
    case 'p':
    case 'P':
        reset();
    break;
    }
}

void Game::processMouseClick(const int& button, const int& state, const int& xPosition, const int& yPosition)
{
    this->activeScene->processMouseClick(button, state, xPosition, yPosition);
}

void Game::reset() {
    this->activeScene->clearScene();
    create();
}