#include <Windows.h>
#ifndef CONSOLETEXT_H_INCLUDED
#define CONSOLETEXT_H_INCLUDED

void SetWindowSize(SHORT width, SHORT height);
void SetScreenBufferSize(SHORT width, SHORT height);
void DisableResizeWindow();
void DisableCtrButton(bool Close, bool Min, bool Max);
void SetBGColor(WORD color);
void clrscr(void);
void gotoxy(short x,short y);
void SetColor(WORD color);

#endif // !CONSOLETEXT_H_INCLUDED