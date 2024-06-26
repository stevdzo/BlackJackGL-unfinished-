#ifndef GUI_H
#define GUI_H

#include "GUIElement.h"
#include "Button.h"
#include "GUIText.h"

class GUI {

public:

	GUI();

	~GUI() = default;

	void add_element(std::unique_ptr<GUIElement> guie);

	void on_element_click(vec2 mouse);

	void render() const;

	void update_text(std::string tag, int v);

private:

	std::vector<std::unique_ptr<GUIElement>> elements_;

	bool rec_shape(Button* btn, vec2 mouse);
	bool circle_shape(Button* btn, vec2 mouse);

};
#endif