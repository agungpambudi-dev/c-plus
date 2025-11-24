#include <ncurses.h>
#include <unistd.h>
#include <string.h>

int main(){

    initscr();
    noecho();
    curs_set(FALSE);
    nodelay(stdscr, TRUE);

    const char *text = "Selamat Datang di Pengenalan Pemrograman";
    int len = strlen(text);

    int max_y, max_x;
    getmaxyx(stdscr, max_y, max_x);

    int x = 0;
    int y = max_y/2;

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

            if (x > max_x) x = -len;

            int ch = getch();
            if (ch != ERR){
                break;
            }
    }
    endwin();
    return 0;
}