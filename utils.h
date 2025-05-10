#pragma once
#include <windows.h>
#include <string>

namespace Colors {
    const int WHITE = 7;
    const int LIGHT_BLUE = 11;
    const int LIGHT_GREEN = 10;
    const int LIGHT_RED = 12;
    const int YELLOW = 14;
}

void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void drawLine(char c = '-', int length = 80) {
    std::string line(length, c);
    std::cout << line << std::endl;
}

void clearScreen() {
    system("cls");
}
