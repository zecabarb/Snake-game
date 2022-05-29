#pragma once
#include <curspriv.h>

//Nota: estas funções são utilizadas para imprimir os desenhos no ecrã
void imprimeMacas(WINDOW* window)
{
    init_pair(1, COLOR_RED, COLOR_RED);
    wattron(window, COLOR_PAIR(1));
    mvwprintw(window, 10, 50, "AAAAAA");
    mvwprintw(window, 11, 49, "AAAAA");
    mvwprintw(window, 12, 50, "AAAAAA");
    
    for (unsigned char i = 0; i <= 4; i++) 
        mvwprintw(window, 30 - i, 9 + i, "AAAAAAAAAAAAAAAAA");
    
    mvwprintw(window, 25, 14, "AAAAA");
    mvwprintw(window, 25, 23, "AAAAA");
    mvwprintw(window, 31, 10, "AAAAAAAAAAAAAAAAA");
    mvwprintw(window, 32, 11, "AAAAAAAAAAAAAAAAA");
    mvwprintw(window, 33, 12, "AAAAAAAAAAAAAAAAAA");
    mvwprintw(window, 34, 13, "AAAAAAAAAAAAAAAA");
    mvwprintw(window, 35, 14, "AAAAAAAAAAAAAA");

    for (unsigned char i = 0; i <= 3; i++)
        mvwprintw(window, 30 - i, 73 - i, "AAAAAAAAAAAAAAAAA");

    mvwprintw(window, 26, 71, "AAAAAAAAAAAAAAA");
    mvwprintw(window, 25, 72, "AAAAA");
    mvwprintw(window, 25, 80, "AAAAA");

    for (unsigned char i = 0; i <= 2; i++) {
        mvwprintw(window, 31 + i, 72 - i, "AAAAAAAAAAAAAAAAA");
        mvwprintw(window, 34, 71, "AAAAAAAAAAAAAAA");
    }
    wattroff(window, COLOR_PAIR(1));

    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    wattron(window, COLOR_PAIR(2));
    for (unsigned char i = 0; i <= 2; i++) {
        mvwprintw(window, 25 - i, 20 + i, "/");
        mvwprintw(window, 25 - i, 78 - i, "\\");
        mvwprintw(window, 9, 53, "/");
    }
    wattroff(window, COLOR_PAIR(2));
}
void imprimeSnake(WINDOW* window)
{
    init_pair(3, COLOR_YELLOW, COLOR_YELLOW);
    wattron(window, COLOR_PAIR(3));

//Letra S
//----------------------------------------------------
    for (unsigned char i = 0; i <= 4; i++) {
        if (i <= 1)
            mvwprintw(window, 2 + i, 9, "SSSSSSSSSSSSS");
        else if (i == 2)
            mvwprintw(window, 2 + i + 3, 9, "SSSSSSSSSSSSS");
        else
            mvwprintw(window, 2 + i + 6, 9, "SSSSSSSSSSSSS");
    }

    for (unsigned char i = 0; i <= 5; i++) {
        if (i <= 2)
            mvwprintw(window, 4 + i, 9, "SSS");
        else
            mvwprintw(window, 4 + i + 1, 19, "SSS");
    }
//---------------------------------------------------

//Letra N
//---------------------------------------------------------------
    for (unsigned char i = 0; i <= 2; i++) {
        if (i <= 1)
            mvwprintw(window, 2 + i, 24, "NNNNNNNN");
        else
            mvwprintw(window, 2 + i + 8, 34, "NNNNNNNN");
    }
    unsigned char j = 2;
    for (unsigned char i = 0; i <= 18; i++) {
        if (i <= 8) 
            mvwprintw(window, 4 + i, 24, "NNNNN");
        else {
            mvwprintw(window, (4 + i) - j, 37, "NNNNN");
            j += 2;
        }
    }
    for (unsigned char i = 0; i <= 7; i++) {
        if (i <= 1)
            mvwprintw(window, 4 + i, 30, "NNN");
        else if (i <= 3)
            mvwprintw(window, 4 + i, 31, "NNN");
        else if (i <= 5)
            mvwprintw(window, 4 + i, 32, "NNN");
        else
            mvwprintw(window, 4 + i, 33, "NNN");    
    }
//----------------------------------------------------------------

//Letra A
//----------------------------------------------------------------------
    for (unsigned char i = 0; i <= 3; i++) {
        if (i <= 1)
            mvwprintw(window, 2 + i, 44, "AAAAAAAAAAAAAAAAAA");
        else
            mvwprintw(window, 2 + i + 3, 44, "AAAAAAAAAAAAAAAAAA");
    }

    for (unsigned char i = 0; i <= 8; i++) {
        if (i <= 4)
            mvwprintw(window, 2 + i, 44, "AAAA");
        else
            mvwprintw(window, 2 + i + 2, 44, "AAAA");
    }

    for (unsigned char i = 0; i <= 8; i++) {
        if (i <= 4)
            mvwprintw(window, 2 + i, 58, "AAAA");
        else
            mvwprintw(window, 2 + i + 2, 58, "AAAA");
    }
//---------------------------------------------------------------------

//Letra K
//-------------------------------------------------------------
    for (unsigned char i = 0; i <= 10; i++)
        mvwprintw(window, 2 + i, 64, "KKKK");

    for (unsigned char i = 0; i <= 2; i++)
        mvwprintw(window, 8 - i, 68, "KKK");

    for (unsigned char i = 0; i <= 3; i++) {
        if (i <= 1)
            mvwprintw(window, 4 + i, 71, "KKK");
        else
            mvwprintw(window, 4 + i + 3, 71, "KKK");
    }
    for (unsigned char i = 0; i <= 3; i++) {
        if (i <= 1)
            mvwprintw(window, 2 + i, 74, "KKK");
        else
            mvwprintw(window, 2 + i + 7, 74, "KKK");
    }
//------------------------------------------------------------

//Letra E
//------------------------------------------------------------
    for (unsigned char i = 0; i <= 3; i++) {
        if (i <= 1)
            mvwprintw(window, 2 + i, 79, "EEEEEEEEEEEE");
        else
            mvwprintw(window, 2 + i + 7, 79, "EEEEEEEEEEEE");
    }

    for (unsigned char i = 0; i <= 5; i++) {
        if (i > 2)
            mvwprintw(window, 4 + i + 1, 79, "EEEE");
        else
            mvwprintw(window, 4 + i, 79, "EEEE");
    }

    mvwprintw(window, 7, 79, "EEEEEEEEEEEE");
//-------------------------------------------------------------
    wattroff(window, COLOR_PAIR(3));
}
void imprimeCobra(WINDOW* window)
{
    init_pair(4, COLOR_GREEN, COLOR_GREEN);
    wattron(window, COLOR_PAIR(4));
    for (unsigned char i = 0; i <= 29; i++) {
        if (i <= 3)
            mvwprintw(window, 21, i + 1, "S");
        else if (i <= 9)
            mvwprintw(window, 21, i + 11, "S");
        else if (i <= 15)
            mvwprintw(window, 21, i + 21, "S");
        else if (i <= 21)
            mvwprintw(window, 21, i + 49, "S");
        else if (i <= 27)
            mvwprintw(window, 21, i + 59, "S");
        else
            mvwprintw(window, 21, i + 69, "S");
    }
    unsigned char k = 0;
    for (unsigned char i = 0; i <= 1; i++) {
        for (unsigned char j = 0; j <= 1; j++) 
            mvwprintw(window, 20, 4 + k + j, "S");
        k += 10;
    }

    k = 0;
    for (unsigned char i = 0; i <= 4; i++) {
        for (unsigned char j = 0; j <= 1; j++)
            mvwprintw(window, 20, 20 + k + j, "S");
        if (i == 1 || i == 2)
            k += 20;
        else
            k += 10;
    }

    for (unsigned char i = 0; i <= 70; i += 10) {
        for (unsigned char j = 0; j <= 1; j++)
            mvwprintw(window, 20, 36 + i + j, "S");
        if (i == 0)
            i += 40;
    }
    k = 0;

    for (unsigned char i = 0; i <= 1; i++)
        mvwprintw(window, 20, 48 + i, "S");
    mvwprintw(window, 20, 53, "S");

    for (unsigned char i = 0; i <= 9; i++)
        mvwprintw(window, 19, 45 + i, "S");

    for (unsigned char i = 0; i <= 97; i += 8) {
        for (unsigned char j = 0; j <= 1; j++)
            mvwprintw(window, 19, 5 + i + j, "S");
        if (i == 32)
            i += 26;
    }

    for (unsigned char j = 0; j <= 3; j++)
        mvwprintw(window, 18, 48 + j, "S");

    unsigned char f = 0;
    for (unsigned char i = 0; i <= 88; i+=6) {
        for (unsigned char j = 0; j <= 1; j++)
            mvwprintw(window, 18, 6 + i + j, "S");
        f++;
        k = f % 2;
        if (i == 38)
            i += 22;
        else if (!k)
            i += 4;
    }
    mvwprintw(window, 18, 53, "S");

    for (unsigned char i = 0; i <= 82; i += 16) {
        for (unsigned char j = 0; j <= 5; j++)
            mvwprintw(window, 17, 7 + i + j, "S");
        if (i == 32)
            i += 18;
    }
    wattroff(window, COLOR_PAIR(4));

    init_pair(5, COLOR_RED, COLOR_YELLOW);
    wattron(window, COLOR_PAIR(5));
    mvwprintw(window, 18, 52, "O");
    mvwprintw(window, 20, 52, "O");
    wattroff(window, COLOR_PAIR(5));

    init_pair(6, COLOR_YELLOW, COLOR_BLACK);
    wattron(window, COLOR_PAIR(6));
    mvwprintw(window, 21, 64, "|");
    mvwprintw(window, 20, 64, "\\");
    mvwprintw(window, 22, 64, "/");
    mvwprintw(window, 20, 63, "/");
    mvwprintw(window, 22, 63, "\\");
    mvwprintw(window, 21, 63, "|");
    mvwprintw(window, 21, 62, "<");
    wattroff(window, COLOR_PAIR(6));

    init_pair(7, COLOR_RED, COLOR_BLACK);
    wattron(window, COLOR_PAIR(7));
    mvwprintw(window, 19, 55, "---<");
    wattroff(window, COLOR_PAIR(7));
}
void imprimeMenu(WINDOW* window) {
    imprimeCobra(window);
    imprimeMacas(window);
    imprimeSnake(window);
    wrefresh(window);
}

void printv(int h, int w) { // Função para auxiliar nos desenhos (imprime uma coluna no ecrã)
    for (int i = -2; i < 3; i++)
        mvwaddch(stdscr, h + i, w, 219);
}
void printh(int h, int w) { // Função para auxiliar nos desenhos (imprime uma linha no ecrã)
    for (int i = -2; i < 3; i++)
        mvwaddch(stdscr, h, w + i, 219);
}
void printGameOver() {

    start_color();
    init_pair(8, COLOR_GREEN, COLOR_GREEN);
    init_pair(9, COLOR_RED, COLOR_RED);
    init_pair(10, COLOR_GREEN, COLOR_BLACK);
    attron(COLOR_PAIR(10));
    mvwprintw(stdscr, 10, 86, "/");
    attroff(COLOR_PAIR(10));

    attron(COLOR_PAIR(9));
    mvwprintw(stdscr, 11, 83, "AAAAAA");
    mvwprintw(stdscr, 12, 82, "AAAAA");
    mvwprintw(stdscr, 13, 83, "AAAAAA");
    attroff(COLOR_PAIR(9));
    refresh();

    attron(COLOR_PAIR(8));
    for (unsigned char i = 10; i <= 16; i++)
        mvwaddch(stdscr, 10, i, 219);
    mvwaddch(stdscr, 10, 19, 219);
    mvwaddch(stdscr, 10, 20, 219);

    for (size_t i = 50; i <= 68; i += 4) {
        for (unsigned char j = 0; j <= 1; j++)
            mvwaddch(stdscr, 10, i + j, 219);
        if (i == 54)
            i += 10;
    }

    mvwaddch(stdscr, 11, 29, 219);
    mvwaddch(stdscr, 11, 31, 219);

    for (unsigned char k = 11; k <= 12; k++)
        for (size_t i = 50; i <= 68; i += 4) {
            for (unsigned char j = 0; j <= 1; j++)
                mvwaddch(stdscr, k, i + j, 219);
            if (i == 54)
                i += 10;
        }
    
    for (unsigned char i = 14; i <= 16; i++)
        mvwaddch(stdscr, 12, i, 219);

    mvwaddch(stdscr, 12, 30, 219);

    for (unsigned char i = 15; i <= 67; i += 52)
        for (unsigned char j = 0; j <= 1; j++)
            mvwaddch(stdscr, 13, i + j, 219);

    mvwaddch(stdscr, 13, 51, 219);
    mvwaddch(stdscr, 13, 54, 219);

    for (unsigned char i = 10; i <= 16; i++)
        mvwaddch(stdscr, 14, i, 219);

    for (unsigned char k = 11; k <= 14; k++)
        for (unsigned char i = 10; i <= 19; i += 9)
            for (unsigned char j = 0; j <= 1; j++)
                mvwaddch(stdscr, k, i + j, 219);

    for (unsigned char j = 12; j <= 16; j++)
        mvwaddch(stdscr, 14, j, 219);

    for (unsigned char j = 51; j <= 54; j++)
        mvwaddch(stdscr, 14, j, 219);

    for (unsigned char j = 67; j <= 69; j++)
        mvwaddch(stdscr, 14, j, 219);

    printh(10, 22);
    printh(10, 37);
    printh(10, 46);
    printh(10, 59);
    printh(10, 65);
    printh(12, 22);
    printv(12, 24);
    printv(12, 25);
    printv(12, 27);
    printv(12, 28);
    printv(12, 32);
    printv(12, 33);
    printv(12, 35);
    printv(12, 36);
    printh(12, 37);
    printv(12, 43);
    printv(12, 44);
    printv(12, 47);
    printv(12, 48);
    printv(12, 57);
    printv(12, 58);
    printh(12, 59);
    printv(12, 63);
    printv(12, 64);
    printh(12, 65);
    printh(14, 46);
    printh(14, 59);
    printh(14, 37);

    attroff(COLOR_PAIR(8));

    int snakey[5] = { 10,11,12,13,14 };
    int snakeytemp[5] = { 10,11,12,13,14 };
    int y;
    y = getmaxy(stdscr);

    for (size_t j = 0; j < 20; j++) {
        for (size_t i = 0; i < 5; i++) {

            if (i == 4) {
                move(snakey[i], 71);
                init_pair(11, COLOR_WHITE, COLOR_BLACK);
                attron(COLOR_PAIR(11));
                addch(219);
                attroff(COLOR_PAIR(11));
                refresh();
            }
            else {
                move(snakey[i], 71);
                init_pair(12, COLOR_GREEN, COLOR_BLACK);
                attron(COLOR_PAIR(12));
                addch(219);
                attroff(COLOR_PAIR(12));
                refresh();
            }

            if (j == 0)
                delay_output(100);

            for (size_t p = 0; p < 5; p++)
                snakeytemp[p] = snakey[p];
            
            if (j) {
                move(snakeytemp[i] - 4, 71);
                init_pair(13, COLOR_BLACK, COLOR_BLACK);
                attron(COLOR_PAIR(13));
                addch(219);
                attroff(COLOR_PAIR(13));
                refresh();
            }

            if (snakey[i] == (y - 5))
                for (size_t i = 0; i < 5; i++) {
                    move(snakeytemp[i], 71);
                    init_pair(14, COLOR_BLACK, COLOR_BLACK);
                    attron(COLOR_PAIR(14));
                    addch(219);
                    attroff(COLOR_PAIR(14));
                    refresh();
                }
        }

        delay_output(50);
        snakey[0]++;

        for (size_t i = 1; i < 5; i++)
            snakey[i] = snakeytemp[i - 1];
    }
    refresh();
    clear();
}