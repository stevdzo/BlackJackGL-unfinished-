#ifndef GLUT_UPDATE_H
#define GLUT_UPDATE_H

#include "Globals.h"

class Chip;

void move_chip(Chip& chip, vec2 destination, float delta_time);

#endif