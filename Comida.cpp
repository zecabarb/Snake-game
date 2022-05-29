#include "Comida.h"

Comida::Comida(WINDOW* win)
	:gamewin(win)
{
	getmaxyx(gamewin, yMax, xMax);
	xPos = yPos = 0;
}

size_t Comida::getComidaX()const {
	return xPos;
}

size_t Comida::getComidaY()const {
	return yPos;
}

void Comida::draw() { //Desenha a comida

	if (has_colors())
		start_color();

	init_pair(17, COLOR_RED, COLOR_BLACK);
	wattron(gamewin, COLOR_PAIR(17));
	mvwaddch(gamewin, yPos, xPos, 219);
	wattroff(gamewin, COLOR_PAIR(17));
	wrefresh(gamewin);
}

void Comida::randomPosition() {// Coloca as coordenadas da  fruta numa zona nova e aleatória na janela do jogo
	size_t r = xMax - 2;
	size_t c = yMax - 2;
	xPos = rand() % r + 1;
	yPos = rand() % c + 1;
}