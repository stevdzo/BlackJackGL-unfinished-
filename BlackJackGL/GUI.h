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
	void update_text(const std::string& tag, int v);
	void disable_button(Button& btn);
	void enable_button(Button& btn);

	template <typename T>
	inline T* get_element_by_tag(const std::string& tag) const {
		for (auto& el : elements_) {
			if (el->get_tag() == tag) {
				T* casted = dynamic_cast<T*>(el.get());
				if (casted) {
					return casted;
				}
			}
		}
		return nullptr;
	}

private:

	std::vector<std::unique_ptr<GUIElement>> elements_;

	bool rec_shape(Button* btn, vec2 mouse);
	bool circle_shape(Button* btn, vec2 mouse);

};
#endif