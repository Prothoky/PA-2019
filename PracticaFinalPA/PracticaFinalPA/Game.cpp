#include <stdlib.h>

#include "Game.h"
#include "Cube.h"
#include "Sphere.h"
#include "Teapot.h"
#include "Cylinder.h"
#include "Torus.h"
#include "Cuboid.h"

void Game::create()
{
	/*
	const Vector3D &sizeToSet = Vector3D(10.0, 10.0, 10.0), const Vector3D &cameraPosition = Vector3D(5.0, 0.0,
		20.0),
		const Vector3D &cameraOrientation = Vector3D(), const Vector3D &gravity = Vector3D(0.0, -0.01, 0.0) */
   
	Scene* mainScene = new Scene(Vector3D(0.0f, 10.0f, 0.0f), Vector3D(100.0f, 10.0f, 10.0f));
	FlyingCamera mainCamera = mainScene->getCamera();
    mainCamera.setPosition(Vector3D(0.0f, 8.0f, 0.0f));
    mainCamera.setOrientation(Vector3D(20.0f, 90.0f, 0.0f));
    mainScene->setCamera(mainCamera);

	//Configuramos Player
	Player player(Vector3D(4.0f, 3.0f, 0.0f));
	player.setColor(Color(1.0f, 1.0f, 1.0f));
	player.setOrientation(Vector3D(0.0f, 90.0f, 0.0f));
    player.LoadModel("Spaceship.obj");
	mainScene->setPlayer(player);

	//Creamos 5 cubos en el suelo a una distancia variable entre 50 y 100 de longitud
	int numberOfCubes = 7;
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
        //cubes[index].LoadModel("Moon.obj");
        mainScene->addObstacleObject(cubes + index);
    }

    //Cube* pointerToCubes = new Cube[4];
    //if (pointerToCubes != nullptr) {
    //    for (int index = 0; index < 4; index++) {
    //        pointerToCubes[index] = Cube(
    //                Vector3D((0.2 + index * 0.1), (0.3 + index * 0.1), (0.1 + index * 0.1)),
    //                Color((0.2 + index * 0.2), (0.4 + index * 0.1), (0.7 + index * 0.1)),
    //                Vector3D((0.02 + index * 0.01), (0.2 + index * 0.01), (0.1 + index * 0.01)),
    //                0.1 + index * 0.1
    //        );
    //        pointerToCubes[index].setOrientationSpeed(Vector3D(10.0f, 1.0f, 0.0f));
    //        mainScene->addObstacleObject(pointerToCubes + index);
    //    }
    //}

   /* 
   Sphere* pointerToSphere = nullptr;


    pointerToSphere = new Sphere(
            Vector3D((0.3), (0.4), (0.9)),
            Color((0.8), (0.7), (0.2)),
            Vector3D((0.2), (0.3), (0.1)),
            Vector3D(),
            0.4
    );
    mainScene->addSceneObject(pointerToSphere);
    */

	//Suelo
    Cuboid* floor = new Cuboid();
    floor->setPosition(Vector3D(50.0f, 0.0f, 0.0f));
    floor->setColor(Color(0.2f, 0.9f, 0.2f));
    floor->setHeight(2.0f);
    floor->setLength(200.0f);
    floor->setWidth(20.0f);
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
}

void Game::processMouseClick(const int& button, const int& state, const int& xPosition, const int& yPosition)
{
    this->activeScene->processMouseClick(button, state, xPosition, yPosition);
}