#pragma once
#include <curses.h>
#include <iostream>
#include "Element.h"

class Comida : public Element {
private:
	WINDOW* gamewin;
	size_t yPos, xPos, xMax, yMax;//X e Y máximo da janela recebida e posição X e Y actual da fruta/comida
public:
	Comida(WINDOW* win);//Recebe a janela onde o jogo vai decorrer
	size_t getComidaX()const;//Obter a posição X atual da fruta
	size_t getComidaY()const;//Obter a posição Y atual da fruta
	void randomPosition();// Coloca as coordenadas da  fruta numa zona nova e aleatória na janela do jogo
	void draw();//Desenha a comida
};