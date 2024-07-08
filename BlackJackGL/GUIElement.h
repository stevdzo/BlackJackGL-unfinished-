#ifndef GUI_ELEMENT_H
#define GUI_ELEMENT_H

#include "GameObject.h"

class GUIElement : public GameObject {

public:

	GUIElement();
	GUIElement(std::string tag, vec2 pos, vec2 size, bool visible=true);

	~GUIElement() override = default;

	void render() const override;

protected:

};
#endif