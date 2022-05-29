#pragma once
#include<vector>
#include "Comida.h"
using namespace std;

class Snake : public Element {
public:
	Snake(WINDOW* win, size_t nElemento, bool advLevel); //Recebe o número de elementos iniciais da cobra; advLevel, variável para saber se o jogador escolheu o nível avançado
	//( o jogo acaba se a cobra embate numa das extremidades) 
	void incElementos(Comida& fruta);
	bool comeu(const Comida& fruta);
	bool up();
	bool down();
	bool left();
	bool right();
	void refreshPos(); //Atualiza os vectores das posições para cada mudança da posição da cabeça da cobra.
	void draw();
	void end(); //Verifica as posições e caso a cabeça da cobra embata no seu corpo, acaba o jogo.
private:
	vector<size_t> xPos; // Vector com os valores de x dos "elementos" da cobra
	vector<size_t> yPos; //Vector com os valores de y dos "elementos" da cobra
	size_t nElementos, yMax, xMax, maxElementos; //Número de "elementos" da cobra;  yMax, xMax -> coordenadas máximas da janela
	bool isRight, isUp, isLeft, isDown, advLevel; // Para saber para onde a cobra se está a mover, Escolher a dificuldade(advLevel = true, maior dificuldade)
	WINDOW* gamewin;
};