#include<windows.h>

void playWinSound(void)
{
    Beep(1500, 300);
    Sleep(100);
    Beep(1700, 300);
    Sleep(100);
    Beep(1900, 300);
    Beep(1500, 300);
    Sleep(100);
    Beep(1700, 300);
    Sleep(100);
    Beep(1900, 300);
}

/**************************************************************************/

void playErrorSound(void)
{
    Beep(300, 500);
    Sleep(200);
    Beep(250, 600);
    Sleep(200);
    Beep(200, 700);
}

/**************************************************************************/

void playButtonPressSound(void)
{
    Beep(1000, 100);  // Play sharp beep (higher frequency)
}

/**************************************************************************/

void playWelcomeSound(void)
{
    Beep(800, 300);
    Sleep(100);
    Beep(1000, 400);
    Sleep(100);
    Beep(1200, 500);
}
