#ifndef GAME_OBJECT_H_
#define GAME_OBJECT_H_

#include "Globals.h"
#include "Sprite.h"
#include "vec2.h"

class GameObject {

public:

	GameObject();

	void set_pos(vec2);
	void set_size(vec2);
	void add_sprite(const char*);

private:

	vec2 pos_;
	vec2 size_;
	Sprite sprite_;

};

#endif