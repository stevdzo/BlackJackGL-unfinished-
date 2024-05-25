#ifndef GUI_H
#define GUI_H

#include "GUIElement.h"
#include "Button.h"

class GUI {

public:

	GUI();

	~GUI() = default;

	void add_element(std::unique_ptr<GUIElement> guie);

	void on_button_click(vec2 mouse);

	void render() const;

private:

	std::vector<std::unique_ptr<GUIElement>> elements_;

};
#endif