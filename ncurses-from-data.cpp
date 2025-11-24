#include <iostream>
#include <ncurses.h>
#include <unistd.h>
#include <string.h>
#include <fstream>

using namespace std;

int main()
{

    // ifstream FileData;

    string textFile;
    ifstream MyReadFile("text-animasi.txt");

    getline(MyReadFile, textFile);

    // cout << textFile << endl;

    // Close the file
    MyReadFile.close();
    

    initscr();
    noecho();
    curs_set(FALSE);
    nodelay(stdscr, TRUE);

    // const char *text = "Selamat Datang di Pengenalan Pemrograman";
    const char *text = textFile.c_str();
    int len = strlen(text);

    int max_y, max_x;
    getmaxyx(stdscr, max_y, max_x);

    int x = 0;
    int y = max_y / 2;

    while (true)
    {
        clear();
        start_color();
        init_pair(1, COLOR_RED, COLOR_BLACK);
        attron(COLOR_PAIR(1));
        mvprintw(y, x, "%s", text);
        attroff(COLOR_PAIR(1));
        refresh();

        usleep(80000);
        x++;

        if (x > max_x)
            x = -len;

        int ch = getch();
        if (ch != ERR)
        {
            break;
        }
    }
    endwin();

    return 0;
}