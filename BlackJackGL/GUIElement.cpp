#include "GUIElement.h"

GUIElement::GUIElement() : GameObject() {
}

GUIElement::GUIElement(std::string tag, vec2 pos, vec2 size) : GameObject(tag, pos, size) {
}

void GUIElement::render() const {
	GameObject::render();
}
