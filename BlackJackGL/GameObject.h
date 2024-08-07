#ifndef GAME_OBJECT_H_
#define GAME_OBJECT_H_

#include "dbg.h"
#include "Sprite.h"
#include "vec2.h"

class GameObject {

public:

	GameObject();
	GameObject(std::string tag,
		       vec2 pos, 
			   vec2 size,
			   bool visible=true);

	virtual ~GameObject() = default;

	void set_pos(vec2);
	void set_size(vec2);
	void add_sprite(const char*);

	std::string get_tag() const;
	vec2 get_pos() const;
	vec2 get_size() const;

	bool visible() const;
	void visible(bool);

	virtual void render() const;
	void update(float delta_time);

protected:

	std::string tag_;
	vec2 pos_;
	vec2 size_;
	Sprite sprite_;

	bool visible_;

};
#endif