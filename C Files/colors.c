#include <windows.h>
#include <stdio.h>

void setConsoleColor(int textColor)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, textColor);
}

/*
    // Blue color is 9, Green color is 10
    setConsoleColor(9);
    printf("hello ");

    setConsoleColor(10);
    printf("world\n");

    setConsoleColor(7); // Reset to default color


1. Black
2. Dark Blue
3. Dark Green
4. Dark Cyan
5. Dark Red
6. Dark Magenta
7. Dark Yellow (or Light Gray)
8. Gray
9. Blue
10. Green
11. Cyan
12. Red
13. Magenta
14. Yellow
15. White

*/
