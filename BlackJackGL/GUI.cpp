#include "GUI.h"

GUI::GUI() {

}

void GUI::add_element(std::unique_ptr<GUIElement> guie) {
	elements_.push_back(std::move(guie));
}

void GUI::on_button_click(vec2 mouse) {

	float x = mouse.x_;
	float y = mouse.y_;

	for (auto& el : elements_) {
	
		auto btn = dynamic_cast<Button*>(el.get());

		if (!btn)
			continue;

		float left   = el->get_pos().x_ - el->get_size().x_ / 2.;
		float right  = el->get_pos().x_ + el->get_size().x_ / 2.;
		float top    = el->get_pos().y_ - el->get_size().y_ / 2.;
		float bottom = el->get_pos().y_ + el->get_size().y_ / 2.;

		if (x >= left && x <= right && y >= top && y <= bottom) {
		
			btn->click();
			
			break;
		}

	}
}

void GUI::render() const {
	for (auto& el : elements_) {
		el->render();
	}
}