//
// Created by rcabido on 12/11/19.
//

#include <stdlib.h>
#include <iostream>

#include "Scene.h"

void Scene::addGameObject(GameObject* solidToAdd)
{
    this->gameObjects.push_back(solidToAdd);
}

void Scene::clearScene()
{
    this->gameObjects.clear();
}

void Scene::render()
{
    this->camera.render();
	this->player.render();

    for (int idx = 0; idx < this->gameObjects.size(); idx++)
    {
        this->gameObjects[idx]->render();
    }

}

void Scene::update(const float &deltaTime)
{
    for (int idx = 0; idx < this->gameObjects.size(); idx++)
    {
		//Cambiar this->gameObject[idx]por una variable que la uso todo el rato
        this->gameObjects[idx]->update(deltaTime, this->gravity);//, this->getGravity());

        if (this->gameObjects[idx]->getPosition().getX() > this->getSize().getX() || this->gameObjects[idx]->getPosition().getX() < 0) {
            this->gameObjects[idx]->setPosition(Vector3D(rand() % 50 + 50, 2.5f, rand() % 20 - 10));
        }

		//Comprobamos colisiones
		if (this->gameObjects[idx]->getCollidable() == true) {
			//Hasta aquí llega
			for (int iter = 0; iter < getPlayer()->getCollisionPointsNumber(); iter++) {	//Sustituír el 2 por el player.getCollisionPointsNumber()
				//Hasta aquí también
				//if (this->gameObjects[idx]->checkCollisionZX(*(getPlayer()->getCollisionPoints() + iter), *(getPlayer()->getCollisionPoints() + iter + 1))) {
				//CheckCollision, primera cordenada positivo hacia la derecha segunda coordenada hacia delante me imagino
				if (this->gameObjects[idx]->checkCollisionZX(*(getPlayer()->getCollisionPoints() + iter * 2), *(getPlayer()->getCollisionPoints() + 1 + iter * 2))) {
					std::cout << "Ha habido colisión" << std::endl;
				}
			}
		}
		/*
		if (this->gameObjects[idx]->getPosition().getY() > this->getSize().getY() || this->gameObjects[idx]->getPosition().getY() < 0) {
            this->gameObjects[idx]->setSpeed(Vector3D(this->gameObjects[idx]->getSpeed().getX(), this->gameObjects[idx]->getSpeed().getY() * -1, this->gameObjects[idx]->getSpeed().getZ()));
        }
        if (this->gameObjects[idx]->getPosition().getZ() > this->getSize().getZ() || this->gameObjects[idx]->getPosition().getZ() < 0) {
            this->gameObjects[idx]->setSpeed(Vector3D(this->gameObjects[idx]->getSpeed().getX(), this->gameObjects[idx]->getSpeed().getY(), this->gameObjects[idx]->getSpeed().getZ() * -1));
        }
		*/
    }
}

void Scene::processMouseMovement(const int& x, const int& y)
{
    this->camera.processMouseMovement(x, y);
}

void Scene::processMouseClick(const int& button, const int& state, const int& x, const int& y)
{
    this->camera.processMouseClick(button, state, x, y);
}

void Scene::processKeyPressed(unsigned char key, int px, int py)
{
    this->camera.processKeyPressed(key, px, py);
	this->player.processKeyPressed(key, px, py);
}


