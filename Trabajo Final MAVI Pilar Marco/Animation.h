/**
* @file Animation.h
* @version 1.0
* @date 03/04/2022
* @author Nicol�s Capel
* @brief Clase de utilidad para Afichmation recordar animaciones.
*/

#ifndef ANIMATION_H
#define ANIMATION_H

#include <vector>
#include <initializer_list>
#include <iostream>

using namespace std;

/**
* @brief Clase de utilidad para Afichmation recordar animaciones.
*/

class Animation {
	friend class Afichmation;
private:
	
	/**
	* @brief Propiedad para recordar el nombre de la animaci�n
	*/
	string name;
	
	/**
	* @brief Propiedad del tipo lista de enteros, contiene una lista de valores que representan en enteros los frames
	*/
	vector<int> frames;

	/**
	* @brief Propiedad que funcoina de iterador para la lista de frames
	*/
	
	vector<int>::iterator it;

	/**
	* @brief Propiedad para recordar si debe estar en loop o no la animaci�n
	*/
	bool loop;
	
	/**
	* @brief Cantidad de fotogramas por segundo de la animaci�n
	*/
	int fps;
	
	/**
	* @brief N�mero de frame a visualizar en pantalla
	*/
	int frame;
	
	/**
	* @brief Indice de frame actual
	*/
	int indexFrame;
	
	/**
	* @brief Indica si finaliz� la animaci�n
	*/
	bool finish;
	
public:
	
	/**
	* @brief M�todo constructor
	* @param name Nombre de la animaci�n
	* @param frames Lista de enteros que contiene los n�meros de frame de la animaci�n
	* @param fps Cantidad de fotogramas por segundo
	* @param loop Establece si la animaci�n se ejecutar� en loop o no
	*/
	Animation(string name, initializer_list<int> frames, int fps, bool loop) {
		this->name = name;
		this->loop = loop;
		this->fps = fps;
		this->frame = 0;
		finish = false;
		initializer_list<int>::iterator iter = frames.begin();
		while (iter != frames.end()) {
			this->frames.push_back(*iter);
			iter++;
		}
		this->indexFrame = *this->frames.begin();
	}
	
	/**
	* @brief M�todo que realiza el intercambio de frames
	*/

	void NextFrame() {
		if (frame >= frames.size()) {
			frame = 0;
			if (!loop) {
				finish = true;
			}
		}
		it = frames.begin() + frame;
		indexFrame = *it;
		frame++;
	}
	
};
#endif
