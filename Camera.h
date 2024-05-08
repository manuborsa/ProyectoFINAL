#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

class Camera : public View {
private:
	//Atributos
	RenderWindow *window;
	Vector2f windowDimension;
	Vector2f worldDimension;
	Vector2f cameraPosition;
	
	//Metodos private
	void CalculateCameraPosition(Vector2f target);
	void MoveCamera();
	
public:
	Camera();
	Camera(RenderWindow *w, int width, int height, int worldLimitWidth, int worldLimitHeight);
	void FollowAndUpdate(Vector2f target, Camera *camera);
};
