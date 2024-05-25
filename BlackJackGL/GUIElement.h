#ifndef GUI_ELEMENT_H
#define GUI_ELEMENT_H

#include "GameObject.h"

class GUIElement : public GameObject {

public:

	GUIElement();
	GUIElement(vec2 pos, vec2 size);

	~GUIElement() override = default;

	void render() const override;

protected:

};
#endif