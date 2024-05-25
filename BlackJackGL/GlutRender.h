#ifndef GLUT_RENDER_H_
#define GLUT_RENDER_H_

#include "Globals.h"
#include "SOIL2/SOIL2.h"

int load_texture(const char* file_path);
void render_sprite(int texture, float pos_x, float pos_y, float size_w, float size_h);
void render_fill_rectangle(float pos_x, float pos_y, float size_w, float size_h, float red, float green, float blue);
void render_wireframe_rectangle(float pos_x, float pos_y, float size_w, float size_h, float red, float green, float blue);
void render_circle(float pos_x, float pos_y, float radius, float red, float green, float blue);
void render_text(const char* string, float pos_x, float pos_y, float red, float green, float blue, float scale=2.0f);

#endif