#include <iostream>
#include <random>
#include <windows.h>
#include <conio.h>
#include <string>
#include <stdio.h>
#include <typeinfo>

#ifndef headers_H
#define headers_H

using namespace std;

static char u1 = '6', u2 = '6', u3 = '6';
static char m1 = '7', m2 = '7', m3 = '7';
static char d1 = '8', d2 = '8', d3 = '8';

static unsigned int credits = 1000;
static int bet{};

class ChoiceExceptions {};
class ValueException {};


void Hello();
void display();
bool check_win();
void display_result(bool check);
void spin();
bool spin_again();
void betting();
string transform_symbol(char value);

#endif