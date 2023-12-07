#include "headers.h"

void display()
{

    system("cls");
    cout << "=========" << endl;
    cout << "||" << u1 << "|" << u2 << "|" << u3 << "||" << endl;
    cout << "---------" << endl;
    cout << "||" << m1 << "|" << m2 << "|" << m3 << "||" << endl;
    cout << "---------" << endl;
    cout << "||" << d1 << "|" << d2 << "|" << d3 << "||" << endl;
    cout << "=========" << endl << endl;

    cout << "Credits: " << credits << endl << endl;
}

bool check_win()
{
    if (m1 == m2 && m1 == m3)
    {
        switch (m1)
        {
            case '5':
                credits += bet*2;
                break;
            case '6':
                credits += bet*3;
                break;
            case '7':
                credits += bet*10;
                break;
            case '8':
                credits += bet*4;
                break;
            case '9':
                credits += bet*5;
                break;
        }

        display();
        return true;
    }
    else return false;
}

void display_result(bool check)
{
    if (check) {
        cout << endl << "---- WIN ----" << endl;
    } else {
        cout << endl << "---- LOSE ----" << endl;
    }
}

void spin()
{
    random_device rd;
    uniform_int_distribution<> spinTimes(10, 20);

    int s{};
    int columns[3] = {spinTimes(rd), spinTimes(rd), spinTimes(rd)};

    credits -= bet;

    do {

        if ((*columns) > 0)
        {
            d1 = m1;
            m1 = u1;
            if (u1 == '9') u1 = '5';
            else u1 += 1;
            (*columns)--;
        }

        if ((*(columns+1)) > 0)
        {
            d2 = m2;
            m2 = u2;
            if (u2 == '9') u2 = '5';
            else u2 += 1;
            (*(columns+1))--;
        }

        if ((*(columns+2)) > 0)
        {
            d3 = m3;
            m3 = u3;
            if (u3 == '9') u3 = '5';
            else u3 += 1;
            (*(columns+2))--;
        }

        display();
        Sleep(s);
        s += 25;

    }while(*columns || *(columns+1) || *(columns+2));

}

bool spin_again()
{
    if(credits > 0)
        {
            cout << "Spin again? Y/N" << endl;
        }
        else
        {
            cout << "You are bankrupt" << endl;
            system("pause");
            return false;
        }
    while (true)
    {
        char again{};
        again = getch();
        if (again == 'Y' || again == 'y') return true;
        else if(again == 'N' || again == 'n') return false;
        else cout << "Wrong key, please try again" << endl;
    }
}

void betting()
{
    char choice{};

    start:
    cout << "How much you are betting?" << endl;
    cout << "1. 100" << endl;
    cout << "2. 500" << endl;
    cout << "3. 1000" << endl;
    cout << "4. Other" << endl;
    try {
        choice = getch();

        if (choice == '1' || choice == '2' || choice == '3' || choice == '4') {}
        else throw ChoiceExceptions();

        switch (choice)
        {
            case '1':
                bet = 100;
                break;
            case '2':
                bet = 500;
                break;
            case '3':
                bet = 1000;
                break;
            case '4':
                cout << "Enter the sum: ";
                cin >> bet;
                if(cin.fail()) cin.clear();
                cin.ignore(1024, '\n');
                if(!(bet > 0 && typeid(bet) == typeid(int) && bet <= credits)) throw ValueException();
                break;
        }
    }

    catch(ChoiceExceptions)
    {
        cout << "Wrong key, please try again" << endl;
        betting();
    }
    catch(ValueException)
    {
        cout << "Wrong bet value! You could only bet a sum which is equal to or greater than 0 and less than your balance" << endl;
        betting();
    }
}

void Hello()
{
        cout << "Hello, to spin click ENTER" << endl;
}

string transform_symbol(char value)
{
    string end_value{};
    switch(value)
    {
        case '5':
            end_value = "\x06";
        case '6':
            end_value = "\x03";
            break;
        case '7':
            end_value = "7";
            break;
        case '8':
            end_value = "\x04";
            break;
        case '9':
            end_value = "\x05";
            break;
    }
    return end_value;
}
