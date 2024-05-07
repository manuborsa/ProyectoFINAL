/**
* @file Camera.h
* @version 0.5
* @date 12/28/2020
* @author Nicolas Capel
* @brief Clase Camera para simular proyecciones de escenas con SFML 2.5. Hereda de View.
* @code
* //Ejemplo de uso en archivo main.cpp
* @endcode
*/

#ifndef CAMERA_H
#define CAMERA_H

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

/**
* @brief Clase que se encarga de manipular la visualización de escena, hereda de View por ende incorpora todos sus métodos y propiedades
*/

class Camera : public View {
private:
	
	/**
	* @brief Propiedad puntero a la ventana que aplica la View
	*/
	RenderWindow *window;
	
	/**
	* @brief Propiedad para recordar las dimensiones de la ventana
	*/
	Vector2f windowDimension;
	
	/**
	* @brief Propiedad para recordar el tamaño del mundo o escena más allá de los límites de la ventana
	*/
	Vector2f worldDimension;
	
	/**
	* @brief Posición a la que enfoca la cámara en la escena
	*/
	Vector2f cameraPosition;
	
	
	/**
	* @brief Calcula la posición de la cámara según la posición del objetivo.
	* @param target Punto X e Y de la posición del elemento seguido
	*/
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
	
	/**
	* @brief Centra la cámara según lo obtenido en el método anterior.
	*/
	void MoveCamera() {
		setCenter(cameraPosition);
	}
	
public:
	/**
	* @brief Constructor.
	* @param w Puntero a la ventana donde se aplica la cámara
	* @param width Ancho de la ventana
	* @param heifht Alto de la ventana
	* @param worldLimitWidth Ancho del mundo o escena
	* @param worldLimitHeight Alto del mundo o escena
	*/
	Camera(RenderWindow *w, int width, int height, int worldLimitWidth, int worldLimitHeight) {
		window = w;
		windowDimension.x = width;
		windowDimension.y = height;
		worldDimension.x = worldLimitWidth;
		worldDimension.y = worldLimitHeight;
		setSize(width, height);
		setCenter(worldLimitWidth / 2, worldLimitHeight / 2);
	}
	
	/**
	* @brief Método que sigue a una posición en pantalla y actualización de cámara.
	* @param target Posición de centro de cámara
	* @param camera Dirección de memoria de la propia instancia (menor código en implementaciones)
	*/
	void FollowAndUpdate(Vector2f target, Camera *camera) {
		CalculateCameraPosition(target);
		MoveCamera();
		window->setView(*camera);
	}
};
#endif
