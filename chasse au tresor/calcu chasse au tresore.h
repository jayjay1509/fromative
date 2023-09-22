#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#define width 4
#define height 4

extern int cases[width * height];
static int j = 5;


int input();
void drawplayfield(bool debugmode = false);
void randomarray();
int tresor();

