/*
    $$$$ The virtual "One Armed Bandit" machine by Kurzawa $$$$
*/




#include "headers.h"

int main()
{
    display();
    Hello();
    while(getch() != 13);

    do {
        display();
        betting();
        spin();
        display_result(check_win());
    }while(spin_again());
    return 0;
}