/*Brendan Clarke 07/2023 SNHU CS*/
#include <iostream>
#include "extra.h"

/*The next 4 void functions are for determining the next phase of the dialog*/
void printMenu()
{
    std::cout << "Would you like to add an hour?" << std::endl;
    std::cout << "To start over, type q" << std::endl;
    std::cout << "y/n? :";
}

void printMenu2()
{
    std::cout << "You did not add an hour. Would you like to add a minute?" << std::endl;
    std::cout << "y/n? :";
}

void printMenu3()
{
    std::cout << "You did not add a minute. Would you like to add a second?" << std::endl;
    std::cout << "y/n? :";
}

void printMenu4()
{
    std::cout << "You did not add a second. Application self-destructs!" << std::endl;
    std::cout << "END";
}

/*Main function which establishes the inital values of each clock, then begins the while loop which follows the flowchart */
int main()
{
    Clock firstclock(0, 0, 0);
    Clock secondclock(12, 30, 45);
    char choice;
    char choicequit = ' ';

    while (choicequit != 'q') {
        printMenu();
        std::cin >> choice;
        /*Determining based on the above user input if to add an hour to the clock*/
        if (choice == 'y' || choice == 'Y') {
            /*calling the function houradd to the firstclock from the clock.cpp*/
            firstclock.houradd();
            secondclock.houradd();
            std::cout << "Clock 1: " << firstclock.h12form() << " | "
                << firstclock.h24form() << std::endl;

            std::cout << "Clock 2: " << secondclock.h12form() << " | "
                << secondclock.h24form() << std::endl;
        }
        else if (choice == 'n' || choice == 'N') {
            printMenu2();
            /*if user states not to add an hour they will be prompted to add a minute*/
            std::cin >> choice;
            if (choice == 'y' || choice == 'Y') {
                firstclock.minadd();
                secondclock.minadd();
                std::cout << "Clock 1: " << firstclock.h12form() << " | "
                    << firstclock.h24form() << std::endl;

                std::cout << "Clock 2: " << secondclock.h12form() << " | "
                    << secondclock.h24form() << std::endl;
            }
            else if (choice == 'n' || choice == 'N') {

                /*if user states not to add a minute they will be prompted to add a second*/
                printMenu3();
                std::cin >> choice;
                if (choice == 'y' || choice == 'Y') {
                    firstclock.secadd();
                    secondclock.secadd();
                    std::cout << "Clock 1: " << firstclock.h12form() << " | "
                        << firstclock.h24form() << std::endl;

                    std::cout << "Clock 2: " << secondclock.h12form() << " | "
                        << secondclock.h24form() << std::endl;
                }
                else if (choice == 'n' || choice == 'N') {
                    printMenu4();
                }
            }
        }
        /*Allows the exiting of the loop*/
        std::cout << "Enter 'q' to quit or any other key to continue: ";
        std::cin >> choicequit;
    }

    std::cout << "Application quit" << std::endl;
    return 0;
}

/*


 _
| |
| |__   ___
| '_ \ / __|
| |_) | (__
|_.__/ \___|

*/