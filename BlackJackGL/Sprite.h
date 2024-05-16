#ifndef SPRITE_H
#define SPRITE_H

#include "Globals.h"
#include "GlutRender.h"

class Sprite {

public:

	Sprite();

	int get_texture() const;
	void load_texture(const char* p_path);
	void render(float p_x, float p_y, float p_w, float p_h) const;

private:

	int texture_;
};
#endif