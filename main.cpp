#include<ctime>
#include <ctype.h>
#include <string>
#include<map>
#include<fstream>
#include<Windows.h>
#include "Snake.h"
#include "Comida.h"
#include"Maça_Snake_Cobra_GameOver.h"

constexpr auto menuOptionsSize = 5;
constexpr auto dificultyOptionsSize = 3;

int main() {
    srand(time(0));//Permite gerar valores verdadeiramente aleatórios para a comida
    initscr();
    curs_set(0); //Retira o cursor intermitente da consola

    if (has_colors())
        start_color();

    int c = 0, cTemp = 0, subHighlight = 0, highlight = 0; // subHighlight -> highlight dos submenus //levelSpeed é o tempo de delay que consideramos como a "velocidade da cobra"

    unsigned char levelSpeed = 50, lastItem = menuOptionsSize - 1, subLastItem = dificultyOptionsSize - 1, yMax = 0, xMax = 0, yMaxMenu = 0, xMaxMenu = 0, columns = 100, pos_x;

    string menuOptions[menuOptionsSize] = { "Start", "LeaderBoard", "Dificulty", "Reset", "Quit" }, nameOrPoints, dificultyOptions[dificultyOptionsSize] = { "Easy", "Intermediate", "Advanced" };

    size_t points = 0;

    bool isPlaying = false, newPlayer = true, advLevel = false, menuSound = true;

    multimap<size_t, string, greater <size_t>>Players;//mapa dos jogadores, KEY=pontos, valor mapeado=nome do jogador (este mapa ordena automaticamente os pontos em ordem decrescente) 

    fstream playersDatabase;//objeto da classe fstream, que permite a manipulação de ficheiros
    playersDatabase.open("Jogadores.txt", ios::in);//abrir a base de dados no modo input (ler o conteúdo do ficheiro de texto)

    getmaxyx(stdscr, yMax, xMax);

    pos_x = (xMax - columns) / 2;

    WINDOW* Win = newwin(30, 100, 0, pos_x);//janela principal (maior)
    refresh();

    WINDOW* menuwin = subwin(Win, lastItem + 3, menuOptions[2].length() + 9, 22, 52);
    getmaxyx(menuwin, yMaxMenu, xMaxMenu);
    box(menuwin, 0, 0);

    WINDOW* scorewin = newwin(yMax, 30, 0, 0);//janela da tabela de liderança
    box(scorewin, 0, 0);

    WINDOW* gamewin = newwin(28, xMax, 2, 0);//janela do jogo
    box(gamewin, 0, 0);

    vector<string> temp_str;
    vector<size_t> temp_int;

    if (playersDatabase.is_open()) {
        while (getline(playersDatabase, nameOrPoints))
            if (isdigit(nameOrPoints[0]))
                temp_int.push_back(atoi(nameOrPoints.c_str()));
            else
                temp_str.push_back(nameOrPoints);

        for (size_t i = 0; i < temp_int.size(); i++)
            Players.insert(make_pair(temp_int[i], temp_str[i]));
    }
    playersDatabase.close();

    do {//loop onde o menu e o jogo em si irão decorrer
        if (!isPlaying) {
            for (unsigned char i = 0; i < 2; i++) {//para reparar o bug esquisito (quando acaba o jogo normalmente ou com a tecla HOME)
                clear();
                refresh();

                if (menuSound)
                    PlaySound(TEXT("musica_menu.wav"), NULL, SND_LOOP | SND_ASYNC); //Inicia o som do menu principal
                menuSound = false;

                wattron(Win, A_ALTCHARSET);
                wborder(Win, 48, 48, 48, 48, 48, 48, 48, 48);
                wattroff(Win, A_ALTCHARSET);

                box(menuwin, 0, 0);
                wrefresh(menuwin);
                keypad(menuwin, true);
                newPlayer = true;

                imprimeMenu(Win);
                wrefresh(Win);
            }
            highlight = 0;

            while (true) {

                //Este loop serve pra mostrar ao utilizador qual a opção que está atualmente selecionada no menu
                for (size_t i = 0; i < lastItem + 1; i++) {
                    int temp_val = (xMaxMenu / 2) - (menuOptions[i].size() / 2);//Imprime todas as opções do menu no centro
                    mvwprintw(menuwin, i + 1, temp_val, menuOptions[i].c_str());
                    mvwprintw(menuwin, i + 1, 1, "  ");

                    if (i == highlight) {
                        wattron(menuwin, A_ALTCHARSET);
                        mvwprintw(menuwin, i + 1, 1, "+");
                        wattroff(menuwin, A_ALTCHARSET);
                    }
                }

                c = wgetch(menuwin);

                switch (c)
                {
                case KEY_UP:
                    highlight--;
                    if (highlight < 0)
                        highlight = 0;
                    break;
                case KEY_DOWN:
                    highlight++;
                    if (highlight > lastItem)
                        highlight = lastItem;
                    break;
                default:
                    break;
                }

                if (c == 10)//10=key_enter
                    break;
            }

            switch (highlight)
            {
            case 0: //Start
                isPlaying = true;
                break;
            case 1: //LeaderBoard
                do {
                    clear();
                    refresh();
                    box(scorewin, 0, 0);
                    wrefresh(scorewin);

                    int i = 0;
                    if (!Players.empty()) {
                        for (auto pair : Players) {//Imprime na janela da tabela de liderança todos os jogadores e os seus respectivos pontos
                            mvwprintw(scorewin, i + 1, 1, "%d. ", i + 1);
                            mvwprintw(scorewin, i + 1, 4, pair.second.c_str());
                            mvwprintw(scorewin, i + 1, pair.second.length() + 4, " - ");
                            mvwprintw(scorewin, i + 1, pair.second.length() + 7, "%d", pair.first);
                            wrefresh(scorewin);
                            i++;
                        }
                    }
                    else {
                        mvwprintw(scorewin, i + 1, 1, "No player data available"); //se não há jogadores imprime esta mensagem
                        wrefresh(scorewin);
                    }
                    c = wgetch(scorewin);
                } while (c != 10);
                wclear(scorewin);
                break;

            case 2: //Dificuldade

                werase(menuwin);
                box(menuwin, 0, 0);
                wrefresh(menuwin);
                subHighlight = 0;

                while (true)
                {
                    //Este loop serve pra mostrar ao utilizador qual a opção que está atualmente selecionada no menu
                    for (size_t i = 0; i < subLastItem + 1; i++) {
                        int temp_val = (xMaxMenu / 2) - (dificultyOptions[i].size() / 2);//Imprime todas as opções do menu no centro
                        mvwprintw(menuwin, i + 1, temp_val, dificultyOptions[i].c_str());
                        mvwprintw(menuwin, i + 1, 1, "  ");

                        if (i == subHighlight) {
                            wattron(menuwin, A_ALTCHARSET);
                            mvwprintw(menuwin, i + 1, 1, "+");
                            wattroff(menuwin, A_ALTCHARSET);
                        }
                    }

                    c = wgetch(menuwin);

                    switch (c)
                    {
                    case KEY_UP:
                        subHighlight--;
                        if (subHighlight < 0)
                            subHighlight = 0;
                        break;
                    case KEY_DOWN:
                        subHighlight++;
                        if (subHighlight > subLastItem)
                            subHighlight = subLastItem;
                        break;
                    default:
                        break;
                    }

                    werase(menuwin);
                    box(menuwin, 0, 0);
                    wrefresh(menuwin);

                    if (c == 10)//10=key_enter
                        break;
                }
                switch (subHighlight) {
                case 0://facil
                    levelSpeed = 95;//95 é o tempo de delay que consideramos como a velocidade da cobra
                    advLevel = false;
                    break;
                case 1://intermedio
                    levelSpeed = 50;
                    advLevel = false;
                    break;
                case 2://dificil
                    levelSpeed = 15;
                    advLevel = true;
                    break;
                }
                break;

            case 3: //Reset
                Players.clear();

                playersDatabase.open("Jogadores.txt", ios::out);
                if (playersDatabase.is_open())
                    playersDatabase << "";
                playersDatabase.close();
                break;
            case 4: //Quit
                break;
            }
        }
        else {
            menuSound = true;
            char* name = new char[30];

            do {
                werase(menuwin);
                mvwprintw(menuwin, 1, 1, "What's your name?");
                wmove(menuwin, 3, 1);
                wrefresh(menuwin);
                wgetnstr(menuwin, name, 14);//Limita o tamanho da string a 14 caracteres
            } while (!isalpha(name[0]));

            nameOrPoints = name;
            delete[] name;
            name = nullptr;
            werase(menuwin);
            clear();
            refresh();
            wrefresh(gamewin);
            keypad(gamewin, true);

            points = 0;

            PlaySound(TEXT("musica_jogo.wav"), NULL, SND_LOOP | SND_ASYNC);//Inicia o som do jogo

            Comida fruit(gamewin);
            fruit.randomPosition();

            Comida fruit2(gamewin);

            Element* gameElement = &fruit;
            gameElement->draw();

            if (levelSpeed == 95) {
                fruit2.randomPosition();
                while (fruit.getComidaX() == fruit2.getComidaX() && fruit.getComidaY() == fruit2.getComidaY()) {
                    fruit2.randomPosition();
                }
                gameElement = &fruit2;
                gameElement->draw();
            }

            Snake snake(gamewin, 4, advLevel);

            wrefresh(stdscr);
            cTemp = wgetch(gamewin);

            while (isPlaying) {
                mvwprintw(stdscr, 1, 1, "Press the Home key to exit");
                init_pair(18, COLOR_RED, COLOR_BLACK);
                attron(COLOR_PAIR(18));

                for (unsigned char i = 0; i < 3; i++)
                    mvwaddch(stdscr, 1, xMax / 2 + i, 219);
                attroff(COLOR_PAIR(18));

                init_pair(19, COLOR_GREEN, COLOR_BLACK);
                attron(COLOR_PAIR(19));
                mvwaddch(stdscr, 0, xMax / 2 + 1, 201);
                attroff(COLOR_PAIR(19));
                mvwprintw(stdscr, 1, xMax / 2 - 5, "%d", points);
                wrefresh(stdscr);

                wtimeout(gamewin, levelSpeed);
                c = wgetch(gamewin);

                if (c != KEY_DOWN && c != KEY_UP && c != KEY_LEFT && c != KEY_RIGHT && c != KEY_HOME)//nao pausar o jogo
                    c = ERR;

                if (c == ERR)
                    c = cTemp;
                else
                    cTemp = c;
                try {
                    switch (c) {

                    case KEY_UP:
                        snake.up();
                        break;

                    case KEY_DOWN:
                        snake.down();
                        break;

                    case KEY_LEFT:
                        snake.left();
                        break;

                    case KEY_RIGHT:
                        snake.right();
                        break;

                    case KEY_HOME:
                        isPlaying = false; //Sai do jogo e volta ao menu inicial
                        break;

                    default:
                        break;
                    }
                    gameElement = &snake;
                    gameElement->draw();
                    snake.end();

                    if (snake.comeu(fruit)) {
                        fruit.randomPosition();
                        snake.incElementos(fruit);
                        points += 10;
                    }
                    else if (levelSpeed == 95) {
                        if (snake.comeu(fruit2)) {
                            fruit2.randomPosition();
                            snake.incElementos(fruit2);
                            while (fruit.getComidaX() == fruit2.getComidaX() && fruit.getComidaY() == fruit2.getComidaY())
                                fruit2.randomPosition();

                            gameElement = &fruit2;
                            gameElement->draw();
                            points += 10;
                        }
                        else {
                            gameElement = &fruit2;
                            gameElement->draw();
                        }
                    }

                    gameElement = &fruit;
                    gameElement->draw();

                }
                catch (runtime_error& l) {
                    //Audio de game over
                    PlaySound(TEXT("audio_gameOver.wav"), NULL, SND_ASYNC);
                    isPlaying = false;

                    Sleep(300);
                    clear();
                    printGameOver();
                    playersDatabase.open("Jogadores.txt", ios::out);

                    if (Players.empty()) {
                        Players.insert(make_pair(points, nameOrPoints));

                        if (playersDatabase.is_open()) {
                            playersDatabase << nameOrPoints << endl;
                            playersDatabase << points << endl;
                        }
                    }
                    else {
                        for (auto pair : Players) {
                            if (!nameOrPoints.compare(pair.second.c_str())) {
                                newPlayer = false;//verifica se o nome introduzido corresponde a um dos nomes já existentes no mapa (se é um novo jogador ou se o jogador introduzido já existe)
                                if (points > pair.first) {
                                    Players.erase(pair.first);
                                    Players.insert(make_pair(points, nameOrPoints));

                                    if (playersDatabase.is_open()) {
                                        multimap<size_t, string> ::iterator it;
                                        for (it = Players.begin(); it != Players.end(); it++) {
                                            playersDatabase << it->second << endl;
                                            playersDatabase << it->first << endl;
                                        }
                                    }
                                    break;
                                }
                            }
                        }
                        if (newPlayer) {
                            Players.insert(make_pair(points, nameOrPoints));

                            if (playersDatabase.is_open())
                                for (auto pair : Players) {
                                    playersDatabase << pair.second << endl;
                                    playersDatabase << pair.first << endl;
                                }
                        }
                    }
                    playersDatabase.close();
                }
            }
        }
    } while (highlight != lastItem);
    timeout(false);
    endwin();
}