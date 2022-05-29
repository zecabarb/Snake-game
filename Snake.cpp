#include "Snake.h"

Snake::Snake(WINDOW* win, size_t nElementos, bool advLevel)
	:gamewin(win), nElementos(nElementos), maxElementos(3000), advLevel(advLevel) {

	for (size_t i = 0; i < nElementos; i++) {
		xPos.push_back(nElementos - i);
		yPos.push_back(2);
	}
	getmaxyx(gamewin, yMax, xMax);
	isRight = isUp = isLeft = isDown = false;
}

void Snake::incElementos(Comida& fruta) { // Quando a cobra come, o numero de elementos incrementa. Caso atinja o numero de elementos máximo o jogo acaba

	if (nElementos == maxElementos)
		throw runtime_error("");
	else
	{
		nElementos++;
		xPos.push_back(0);
		yPos.push_back(0);
	}

	for (size_t i = 0; i < xPos.size(); i++) {
		if (fruta.getComidaX() == xPos[i] && fruta.getComidaY() == yPos[i]) {
			fruta.randomPosition();
			i = 0;
		}
	}
}

bool Snake::comeu(const Comida& fruta) { //Testa se a cobra comeu a comida

	if ((fruta.getComidaX() == xPos[0]) && (fruta.getComidaY() == yPos[0]))
		return true;

	return false;
}

bool Snake::up() {

	if (isDown) {//Não deixa a cobra andar na direção oposta à atual
		down();
		isUp = false;
		isLeft = false;
		isRight = false;
		return false;
	}

	refreshPos();
	yPos[0]--;

	if (!advLevel) 
		if (yPos[0] < 1)//Se a cobra entrou nas bordas da janela do jogo ela sairá pelo outro lado
			yPos[0] = yMax - 2;
	
	isUp = true;
	isLeft = false;
	isRight = false;
	return true;
}

bool Snake::down() {

	if (isUp) {//Não deixa a cobra andar na direção oposta à atual
		up();
		isDown = false;
		isLeft = false;
		isRight = false;
		return false;
	}

	refreshPos();
	yPos[0]++;

	if (!advLevel) 
		if (yPos[0] > (yMax - 2))//Se a cobra entrou nas bordas da janela do jogo ela sairá pelo outro lado
			yPos[0] = 1;

	isDown = true;
	isLeft = false;
	isRight = false;
	return true;
}

bool Snake::left() {

	if (isRight) {//Não deixa a cobra andar na direção oposta à atual
		right();
		isLeft = false;
		isDown = false;
		isUp = false;
		return false;
	}

	refreshPos();
	xPos[0]--;

	if (!advLevel)
		if (xPos[0] < 1)//Se a cobra entrou nas bordas da janela do jogo ela sairá pelo outro lado
			xPos[0] = xMax - 2;

	isLeft = true;
	isDown = false;
	isUp = false;
	return true;
}

bool Snake::right() {

	if (isLeft) {//Não deixa a cobra andar na direção oposta à atual
		left();
		isRight = false;
		isDown = false;
		isUp = false;
		return false;
	}

	refreshPos();
	xPos[0]++;

	if (!advLevel)
		if (xPos[0] > (xMax - 2))//Se a cobra entrou nas bordas da janela do jogo ela sairá pelo outro lado
			xPos[0] = 1;
	
	isRight = true;
	isDown = false;
	isUp = false;
	return true;
}

void Snake::refreshPos() {//"Atualiza" a posição dos elementos da cobra  //Atualiza os vectores das posições para cada mudança da posição da cabeça da cobra.

	vector<int> xPosTemp;
	vector<int> yPosTemp;

	for (size_t i = 0; i < xPos.size(); i++) {

		xPosTemp.push_back(xPos[i]);
		yPosTemp.push_back(yPos[i]);

	}

	for (size_t i = 1; i < xPos.size(); i++) {

		xPos[i] = xPosTemp[i - 1];
		yPos[i] = yPosTemp[i - 1];

	}
}

void Snake::draw()//Desenha a cobra
{
	if (has_colors())
		start_color();

	init_pair(15, COLOR_WHITE, COLOR_BLACK);
	init_pair(16, COLOR_GREEN, COLOR_BLACK);
	wclear(gamewin);
	box(gamewin, 0, 0);

	for (size_t i = 0; i < xPos.size(); i++) {

		if (i == 0) {
			wattron(gamewin, COLOR_PAIR(15));
			mvwaddch(gamewin, yPos[i], xPos[i], 219);
			wattroff(gamewin, COLOR_PAIR(15));
		}
		else {
			wattron(gamewin, COLOR_PAIR(16));
			mvwaddch(gamewin, yPos[i], xPos[i], 219);
			wattroff(gamewin, COLOR_PAIR(16));
		}
	}
	wrefresh(gamewin);
}

void Snake::end() {
	if (advLevel)   //Quando a cobra embate nos lados o jogo acaba (apenas se advLevel = true)
		if (xPos[0] == (xMax - 1) || xPos[0] == 0 || yPos[0] == (yMax - 1) || yPos[0] == 0)
			throw runtime_error("");

	for (size_t i = 1; i < nElementos; i++) // Para verificar se a cobra embate nela própria
		if ((xPos[i] == xPos[0]) && (yPos[i] == yPos[0]))
			throw runtime_error("");
}