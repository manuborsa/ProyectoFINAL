#include "Camera.h"
#include <SFML/Graphics.hpp>

Camera::Camera(RenderWindow *w, int width, int height, int worldLimitWidth, int worldLimitHeight) {
	window = w;
	windowDimension.x = width;
	windowDimension.y = height;
	worldDimension.x = worldLimitWidth;
	worldDimension.y = worldLimitHeight;
	setSize(width, height);
	setCenter(worldLimitWidth / 2, worldLimitHeight / 2);
}
Camera::Camera(){
	
}

void Camera::CalculateCameraPosition(Vector2f target){
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
void Camera::MoveCamera(){
	setCenter(cameraPosition);
}

void Camera::FollowAndUpdate(Vector2f target, Camera *camera) {
	CalculateCameraPosition(target);
	MoveCamera();
	window->setView(*camera);
}

