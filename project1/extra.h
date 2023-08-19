#ifndef extra_h
#define extra_h
/*Above declares the name*/
#include <string>

using namespace std;
/*Creating a class for Clock has helped consolidate all of my code into an easy mental map through this header file*/
class Clock 
{

public:

    /*Declares each function and variable in use for Clock and for the addition to the clocks*/
    Clock(int h, int m, int sec);
    void secadd();

    void minadd();

    void houradd();

    string h12form() const;
    string h24form() const;

private:
    /*declares the h = hour, m = minute, sec = second intergers */
    int h;

    int m;

    int sec;

    string form(int number) const;
};

#endif

/*


 _
| |
| |__   ___
| '_ \ / __|
| |_) | (__
|_.__/ \___|

*/