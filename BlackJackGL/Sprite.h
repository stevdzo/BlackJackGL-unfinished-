#ifndef SPRITE_H
#define SPRITE_H

#include "Globals.h"
#include "Render_Func.h"

class Sprite {

public:

	Sprite();

	int get_texture() const;
	std::vector<int> get_textures() const;

	void set_tex(int);

	void load_texture(const char* p_path);
	void render(float p_x, float p_y, float p_w, float p_h) const;

private:

	int texture_;
	std::vector<int> textures_;
};
#endif