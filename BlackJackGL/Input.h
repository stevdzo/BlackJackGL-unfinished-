#ifndef INPUT_H
#define INPUT_H

#include "Globals.h"
#include "vec2.h"

class Input {

public:

	static Input& instance();

	void mouse(int button, int state, int x, int y);

	bool is_mouse_key_pressed() const;
	void press_mouse_key();
	void release_mouse_key();

	vec2 get_mouse_vector() const;

	void ui_element_click();

private:

	vec2 mouse_;
	bool mouse_pressed_;

	Input();

	void set_mouse_vector(vec2);
};
#endif

