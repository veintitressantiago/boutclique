#include "Cursor.h"

void Cursor::setup()
{
    m_x = 15;
    m_y = 5;
}

void Cursor::draw()
{
    mvaddch(m_y, m_x, ACS_HLINE);
    mvaddch(m_y, m_x + 1, ACS_HLINE);
    mvaddch(m_y, m_x + 2, ACS_HLINE);
    mvaddch(m_y, m_x - 1, ACS_HLINE);
    mvaddch(m_y, m_x - 2, ACS_HLINE);
    mvaddch(m_y + 3, m_x, ACS_HLINE);
    mvaddch(m_y + 3, m_x + 1, ACS_HLINE);
    mvaddch(m_y + 3, m_x + 2, ACS_HLINE);
    mvaddch(m_y + 3, m_x - 1, ACS_HLINE);
    mvaddch(m_y + 3, m_x - 2, ACS_HLINE);

    mvaddch(m_y, m_x - 3, ACS_ULCORNER);
    mvaddch(m_y + 3, m_x - 3, ACS_LLCORNER);
    mvaddch(m_y, m_x + 3, ACS_URCORNER);
    mvaddch(m_y + 3, m_x + 3, ACS_LRCORNER);

    mvaddch(m_y + 1, m_x - 3, ACS_VLINE);
    mvaddch(m_y + 2, m_x - 3, ACS_VLINE);
    mvaddch(m_y + 1, m_x + 3, ACS_VLINE);
    mvaddch(m_y + 2, m_x + 3, ACS_VLINE);

    mvaddch(m_y + 2, m_x, ACS_CKBOARD);
    mvaddch(m_y + 2, m_x - 1, ACS_CKBOARD);
    mvaddch(m_y + 2, m_x - 2, ACS_CKBOARD);
    mvaddch(m_y + 2, m_x + 1, ACS_CKBOARD);
    mvaddch(m_y + 2, m_x + 2, ACS_CKBOARD);
    mvaddch(m_y + 1, m_x, ACS_CKBOARD);
    mvaddch(m_y + 1, m_x - 1, ACS_CKBOARD);
    mvaddch(m_y + 1, m_x - 2, ACS_CKBOARD);
    mvaddch(m_y + 1, m_x + 1, ACS_CKBOARD);
    mvaddch(m_y + 1, m_x + 2, ACS_CKBOARD);
}

void Cursor::setX(int x) { m_x = x; }
void Cursor::setY(int y) { m_y = y; }
int Cursor::getX() { return m_x; }
int Cursor::getY() { return m_y; }