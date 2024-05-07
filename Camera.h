#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

/**
* @brief Clase que se encarga de manipular la visualización de escena, hereda de View por ende incorpora todos sus métodos y propiedades
*/

class Camera : public View {
private:
	
	RenderWindow *window;
	Vector2f windowDimension;
	Vector2f worldDimension;
	Vector2f cameraPosition;
	
	
	void CalculateCameraPosition(Vector2f target) {
		cameraPosition = target;
		if (cameraPosition.x < windowDimension.x / 2) {
			cameraPosition.x = windowDimension.x / 2;
		}
		if (cameraPosition.x > worldDimension.x - windowDimension.x / 2) {
			cameraPosition.x = worldDimension.x - windowDimension.x / 2;
		}
		if (cameraPosition.y < windowDimension.y / 2) {
			cameraPosition.y = windowDimension.y / 2;
		}
		if (cameraPosition.y > worldDimension.y - windowDimension.y / 2) {
			cameraPosition.y = worldDimension.y - windowDimension.y / 2;
		}
	}
	
	void MoveCamera() {
		setCenter(cameraPosition);
	}
	
public:

	Camera(RenderWindow *w, int width, int height, int worldLimitWidth, int worldLimitHeight) {
		window = w;
		windowDimension.x = width;
		windowDimension.y = height;
		worldDimension.x = worldLimitWidth;
		worldDimension.y = worldLimitHeight;
		setSize(width, height);
		setCenter(worldLimitWidth / 2, worldLimitHeight / 2);
	}
	

	void FollowAndUpdate(Vector2f target, Camera *camera) {
		CalculateCameraPosition(target);
		MoveCamera();
		window->setView(*camera);
	}
};
