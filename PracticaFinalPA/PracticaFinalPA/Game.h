//
// Created by rcabido on 7/11/19.
//
#ifndef ENGINE_HERENCIA_GAME_H
#define ENGINE_HERENCIA_GAME_H
#include "Scene.h"

class Game
{
private:
	float time;
	float deltaTime;

	Scene* activeScene;
	std::vector<Scene*> scenes;

public:

	Game() : time(0.0), deltaTime(0.025), activeScene(nullptr) {}

	void create();
	void render();
	void update();

    void processMouseMovement(const int& xPosition, const int& yPosition);
    void processKeyPressed(const unsigned char& key, const int& xPosition, const int& yPosition);
    void processMouseClick(const int& button, const int& state, const int& xPosition, const int& yPosition);
};
#endif