/*
Brendan Clarke 07/2023 PROJECT 1
SNHU CS
*/
#include <sstream>
#include "extra.h"


/*Establishes the clock variables which we will be interacting with to declare value and the make user inputted changes*/
Clock::Clock(int h, int m, int sec)
    : h(h), m(m), sec(sec) {}



void Clock::minadd() 
{
    m++;
    if (m >= 60) {
        m = 0;
        houradd();
    }
}


void Clock::secadd() 
{
 sec++;
    if (sec >= 60) {
        sec = 0;
        minadd();
    }
}
void Clock::houradd()
{
    h = (h + 1) % 24;
}

/*Declares the format of the 12 hour clock*/
string Clock::h12form() const
{
    int hours12 = (h % 12 == 0) ? 12 : h % 12;
    string period = (h >= 12) ? "am" : "pm";
    stringstream ss;
    ss << form(hours12) << ":"
        << form(m) << ":"
        << form(sec) << " " << period;
    return ss.str();
}
string Clock::form(int number) const 
{
    if (number < 10) {
        return "0" + to_string(number);
    }
    return to_string(number);
}
/*declares the 24 hour clock format*/
string Clock::h24form() const 
{
    stringstream ss;
    ss << form(h) << ":"
        << form(m) << ":"
        << form(sec);
    return ss.str();
}
/*


 _
| |
| |__   ___
| '_ \ / __|
| |_) | (__
|_.__/ \___|

*/