#include "Button.h"

Button::Button() : GUIElement() {

}

Button::Button(vec2 pos, vec2 size, ButtonType type, std::function<void()> callback) : GUIElement(pos, size), type_(type), callback_(callback) {

}

void Button::click() {

	if (callback_)
		callback_();

	/*switch (type_) {
	
	case ButtonType::PLAY:
		std::cout << "Play button clicked" << '\n';
		break;
	case ButtonType::QUIT:
		std::cout << "Quit button clicked" << '\n';
		break;
	}*/
}