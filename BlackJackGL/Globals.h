#ifndef GLOBALS_H_
#define GLOBALS_H_

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>
#include <memory>
#include <string>

#include <GL/freeglut.h>

#define PI 3.14159

class vec2;

extern const float window_width;
extern const float window_height;
extern const float window_pos_x;
extern const float window_pos_y;
extern const std::string title;

extern const float player_1_pos_x;
extern const float player_1_pos_y;

extern const float player_2_pos_x;
extern const float player_2_pos_y;

extern const std::string TXT_TOTAL_BET;
extern const std::string TXT_PLAYER_HAND;
extern const std::string TXT_DEALER_HAND;
extern const std::string TXT_TOTAL_BET_LABEL;
extern const std::string TXT_PLACE_BET;

#endif