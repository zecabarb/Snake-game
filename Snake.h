#pragma once
#include<vector>
#include "Comida.h"
using namespace std;

class Snake : public Element {
public:
	Snake(WINDOW* win, size_t nElemento, bool advLevel); //Recebe o n�mero de elementos iniciais da cobra; advLevel, vari�vel para saber se o jogador escolheu o n�vel avan�ado
	//( o jogo acaba se a cobra embate numa das extremidades) 
	void incElementos(Comida& fruta);
	bool comeu(const Comida& fruta);
	bool up();
	bool down();
	bool left();
	bool right();
	void refreshPos(); //Atualiza os vectores das posi��es para cada mudan�a da posi��o da cabe�a da cobra.
	void draw();
	void end(); //Verifica as posi��es e caso a cabe�a da cobra embata no seu corpo, acaba o jogo.
private:
	vector<size_t> xPos; // Vector com os valores de x dos "elementos" da cobra
	vector<size_t> yPos; //Vector com os valores de y dos "elementos" da cobra
	size_t nElementos, yMax, xMax, maxElementos; //N�mero de "elementos" da cobra;  yMax, xMax -> coordenadas m�ximas da janela
	bool isRight, isUp, isLeft, isDown, advLevel; // Para saber para onde a cobra se est� a mover, Escolher a dificuldade(advLevel = true, maior dificuldade)
	WINDOW* gamewin;
};