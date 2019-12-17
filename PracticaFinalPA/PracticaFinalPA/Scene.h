//
// Created by rcabido on 12/11/19.
//

#ifndef ENGINE_POLIMORFISMO_SCENE_SCENE_H
#define ENGINE_POLIMORFISMO_SCENE_SCENE_H

#include <vector>

#include "FlyingCamera.h"
#include "Player.h"
#include "GameObject.h"

class Scene {
private:
    bool win = false;
    bool loose = false;
    float timer = 1000;
    const float aceleracion = 0.00005;
    FlyingCamera camera;
	Player player;
    vector<GameObject*> ObstaclesObjects; 
    vector<GameObject*> SceneObjects;
    Vector3D size;
    Vector3D gravity;
public:
    Scene(const Vector3D &playerPosition, const Vector3D &sizeToSet = Vector3D(10.0, 10.0, 10.0), const Vector3D &cameraPosition = Vector3D(5.0, 0.0, 20.0), 
		const Vector3D &cameraOrientation = Vector3D(), const Vector3D &gravity = Vector3D(0.0, -0.01, 0.0)) :
            size(sizeToSet), gravity(gravity), camera(FlyingCamera(cameraPosition, cameraOrientation)), player(Player(playerPosition)) {}

    Vector3D getSize() const { return this->size; };//inline const Vector3D& getSize() const { return this->size; }
    Vector3D getGravity() const { return this->gravity; };// inline const Vector3D& getGravity() const { return this->gravity; }
    FlyingCamera getCamera() const { return this->camera; }//  inline const Camera& getCamera() const { return this->camera; }
    void setCamera(FlyingCamera cameraToSet) { this->camera = cameraToSet; }// inline void setCamera(FlyingCamera cameraToSet) { this->camera = cameraToSet; }
	Player* getPlayer() { return &(this->player); }
	void setPlayer(Player playerToSet) { this->player = playerToSet; }

    void addObstacleObject(GameObject* solidToAdd);
    void addSceneObject(GameObject* solidToAdd);
    void clearScene();
    void render();
    void update(const float &deltaTime);

    void processMouseMovement(const int& x, const int& y);
    void processMouseClick(const int& button, const int& state, const int& x, const int& y);
    void processKeyPressed(unsigned char key, int px, int py);
    void RenderText(string str);
};


#endif //ENGINE_POLIMORFISMO_SCENE_SCENE_H
