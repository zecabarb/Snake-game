#pragma once
#include <curses.h>
#include <iostream>
#include "Element.h"

class Comida : public Element {
private:
	WINDOW* gamewin;
	size_t yPos, xPos, xMax, yMax;//X e Y m�ximo da janela recebida e posi��o X e Y actual da fruta/comida
public:
	Comida(WINDOW* win);//Recebe a janela onde o jogo vai decorrer
	size_t getComidaX()const;//Obter a posi��o X atual da fruta
	size_t getComidaY()const;//Obter a posi��o Y atual da fruta
	void randomPosition();// Coloca as coordenadas da  fruta numa zona nova e aleat�ria na janela do jogo
	void draw();//Desenha a comida
};