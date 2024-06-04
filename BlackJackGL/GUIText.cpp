#include "GUIText.h"

GUIText::GUIText() : text_("Label") {
}

GUIText::GUIText(std::string tag, vec2 pos, std::string str) : GUIElement(tag, pos, vec2()), text_(str) {
}

void GUIText::set_text(std::string str) {
	text_ = str;
}

void GUIText::render() const {
	::render_text(text_.c_str(), pos_.x_, pos_.y_, 1.0f, 1.0f, 1.0f);
}