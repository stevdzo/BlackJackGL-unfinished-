#ifndef GUI_TEXT_H
#define GUI_TEXT_H

#include "GUIElement.h"

class GUIText : public GUIElement {

public:

	GUIText();
	GUIText(std::string tag, vec2 pos, std::string str);

	~GUIText() override = default;

	void set_text(std::string);

	void render() const override;

private:

	std::string text_;
	
};
#endif