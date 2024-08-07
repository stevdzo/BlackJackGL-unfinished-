#include "GUI.h"

GUI::GUI() {

}

void GUI::add_element(std::unique_ptr<GUIElement> guie) {
	elements_.push_back(std::move(guie));
}

void GUI::on_element_click(vec2 mouse) {

	for (auto& el : elements_) {
	
		auto btn = dynamic_cast<Button*>(el.get());

		if (!btn)
			continue;

		switch (btn->get_shape()) {
		
		case ButtonShape::RECTANGLE: 
			if (rec_shape(btn, mouse)) return;
			break;
		case ButtonShape::CIRCLE:
			if (circle_shape(btn, mouse)) return;
			break;

		}
	}
}

void GUI::render() const {
	for (auto& el : elements_) {
		el->render();
	}
}

void GUI::update_text(const std::string& tag, int v) {
	for (auto& el : elements_) {
		if (el->get_tag() == tag) {
			auto txt = dynamic_cast<GUIText*>(el.get());

			if (v == 0)
				txt->set_text("?");
			else
				txt->set_text(std::to_string(v));
		}
	}
}

void GUI::disable_button(Button& btn) {
	btn.visible(false);
	btn.enabled(false);
}

void GUI::enable_button(Button& btn) {
	btn.visible(true);
	btn.enabled(true);
}

bool GUI::rec_shape(Button* btn, vec2 mouse) {

	float x = mouse.x_;
	float y = mouse.y_;

	float left = btn->get_pos().x_ - btn->get_size().x_ / 2.;
	float right = btn->get_pos().x_ + btn->get_size().x_ / 2.;
	float top = btn->get_pos().y_ - btn->get_size().y_ / 2.;
	float bottom = btn->get_pos().y_ + btn->get_size().y_ / 2.;

	if (x >= left && x <= right && y >= top && y <= bottom) {
		btn->click();
		return true;
	}
	return false;
}

bool GUI::circle_shape(Button* btn, vec2 mouse) {

	vec2 dist_vec = mouse - btn->get_pos();
	float distance = dist_vec.magnitude();
	float btn_radius = btn->get_size().x_;

	if (distance <= btn_radius) {
		btn->click();
		return true;
	}
	return false;
}