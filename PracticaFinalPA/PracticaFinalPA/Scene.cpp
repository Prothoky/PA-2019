//
// Created by rcabido on 12/11/19.
//

#include <stdlib.h>
#include <iostream>

#include "Scene.h"

void Scene::addObstacleObject(GameObject* solidToAdd)
{
    this->ObstaclesObjects.push_back(solidToAdd);
}

void Scene::addSceneObject(GameObject* solidToAdd)
{
    this->SceneObjects.push_back(solidToAdd);
}

void Scene::clearScene()
{
    this->ObstaclesObjects.clear();
    this->SceneObjects.clear();
}

void Scene::render()
{
    this->camera.render();
	this->player.render();

    for (int idx = 0; idx < this->ObstaclesObjects.size(); idx++)
    {
        this->ObstaclesObjects[idx]->render();
        this->ObstaclesObjects[idx]->setSpeed(Vector3D(this->ObstaclesObjects[idx]->getSpeed().getX()-aceleracion, this->ObstaclesObjects[idx]->getSpeed().getY(), this->ObstaclesObjects[idx]->getSpeed().getZ()));
    }

    for (int idx = 0; idx < this->SceneObjects.size(); idx++)
    {
        this->SceneObjects[idx]->render();
    }
    if (loose) {
        string str = "YOU LOSE";
        RenderText(str);
    }
    if (win) {
        string str = "YOU WIN";
        RenderText(str);
    }
}

void Scene::update(const float &deltaTime)
{
    if (!loose && !win) {
        if (timer > 0) {
            timer -= deltaTime;
            cout << timer << endl;
            for (int idx = 0; idx < this->ObstaclesObjects.size(); idx++)
            {
                //Cambiar this->gameObject[idx]por una variable que la uso todo el rato
                this->ObstaclesObjects[idx]->update(deltaTime, this->gravity);//, this->getGravity());

                if (this->ObstaclesObjects[idx]->getPosition().getX() > this->getSize().getX() || this->ObstaclesObjects[idx]->getPosition().getX() < 0) {
                    this->ObstaclesObjects[idx]->setPosition(Vector3D(rand() % 50 + 50, 2.5f, rand() % 20 - 10));
                }

                //Comprobamos colisiones
                if (this->ObstaclesObjects[idx]->getCollidable() == true) {
                    //Hasta aquí llega
                    for (int iter = 0; iter < getPlayer()->getCollisionPointsNumber(); iter++) {	//Sustituír el 2 por el player.getCollisionPointsNumber()
                        //Hasta aquí también
                        //if (this->gameObjects[idx]->checkCollisionZX(*(getPlayer()->getCollisionPoints() + iter), *(getPlayer()->getCollisionPoints() + iter + 1))) {
                        //CheckCollision, primera cordenada positivo hacia la derecha segunda coordenada hacia delante me imagino
                        if (this->ObstaclesObjects[idx]->checkCollisionZX(*(getPlayer()->getCollisionPoints() + iter * 2), *(getPlayer()->getCollisionPoints() + 1 + iter * 2))) {
                            std::cout << "Ha habido colisión" << std::endl;
                            loose = true;
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

            for (int idx = 0; idx < this->SceneObjects.size(); idx++)
            {
                //Cambiar this->gameObject[idx]por una variable que la uso todo el rato
                this->SceneObjects[idx]->update(deltaTime, this->gravity);//, this->getGravity());

                if (this->SceneObjects[idx]->getPosition().getX() > this->getSize().getX() || this->SceneObjects[idx]->getPosition().getX() < 0) {
                    this->SceneObjects[idx]->setPosition(Vector3D(rand() % 50 + 50, 2.5f, rand() % 19 - 9));
                }

                //Comprobamos colisiones
                if (this->SceneObjects[idx]->getCollidable() == true) {
                    //Hasta aquí llega
                    for (int iter = 0; iter < getPlayer()->getCollisionPointsNumber(); iter++) {	//Sustituír el 2 por el player.getCollisionPointsNumber()
                        //Hasta aquí también
                        //if (this->gameObjects[idx]->checkCollisionZX(*(getPlayer()->getCollisionPoints() + iter), *(getPlayer()->getCollisionPoints() + iter + 1))) {
                        //CheckCollision, primera cordenada positivo hacia la derecha segunda coordenada hacia delante me imagino
                        if (this->SceneObjects[idx]->checkCollisionZX(*(getPlayer()->getCollisionPoints() + iter * 2), *(getPlayer()->getCollisionPoints() + 1 + iter * 2))) {
                            std::cout << "Ha habido colisión" << std::endl;
                            loose = true;
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
            if (loose) {
                cout << "HAS PERDIDO" << endl;
                cout << "Pulsa la tecla 'P' para reiniciar el nivel" << endl;
            }
        }
        else {
            win = true;
            cout << "TIME OUT!" << endl;
            cout << "YOU WIN!" << endl;
            cout << "Pulsa la tecla 'P' para reiniciar el nivel" << endl;
        }
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
    if (!win && !loose) {
        this->camera.processKeyPressed(key, px, py);
	    this->player.processKeyPressed(key, px, py);
    }
}

void Scene::RenderText(string str)
{
    glColor3f(1.0f, 0.0f, 0.0f);
    glRasterPos3f(7.5f, 5.0f, -1.0f);
    stringstream strm;
    strm << str << endl;
    string text = strm.str();
    for (string::iterator it = text.begin(); it != text.end(); ++it) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *it);
    }
}