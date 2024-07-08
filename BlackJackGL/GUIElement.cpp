#include "GUIElement.h"

GUIElement::GUIElement() : GameObject() {
}

GUIElement::GUIElement(std::string tag, vec2 pos, vec2 size, bool visible) : GameObject(tag, pos, size, visible) {
}

void GUIElement::render() const {
	GameObject::render();
}