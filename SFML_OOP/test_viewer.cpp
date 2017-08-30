/*
    Example of using a class with SFML functions
    To compile:
        g++ test_viewer.cpp Viewer.cpp -o viewer -lsfml-graphics -lsfml-window -lsfml-system -std=c++11 -g
*/

#include <iostream>
#include "Viewer.h"

void menu(std::string *greeting)
{
    char option = 'a';

    while (option != 'q')
    {
        std::cout << "\nUSER MENU\n";
        std::cout << "\ta. Say Hello\n";
        std::cout << "\tb. Say Goodbye\n";
        std::cout << "\tq. Quit program\n";
        std::cout << "Choose an option: ";
        std::cin >> option;

        switch(option)
        {
            case 'a':
                *greeting = "Hello";
                std::cout << "Setting message to: " << *greeting << std::endl;
                break;
            case 'b':
                *greeting = "Goodbye";
                std::cout << "Setting message to: " << *greeting << std::endl;
                break;
            case 'q':
                std::cout << "Finishing program" << std::endl;
                exit(0);
                break;
            default:
                std::cout << "Unknown option. Try again" << std::endl;
        }
    }
}

int main()
{
    Viewer test("Viewer test", "Akashi.ttf", &menu);

    test.windowListener();

    return 0;
}
