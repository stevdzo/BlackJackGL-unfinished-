#ifndef BUTTON_H
#define BUTTON_H

#include "GUIElement.h"
#include <functional>

enum class ButtonType {
	PLAY,
	SETTINGS,
	QUIT,
	RESUME,
	PAUSE,
	BACK
};

class Button : public GUIElement {

public:

	Button();
	Button(vec2 pos, vec2 size, ButtonType type, std::function<void()> callback);

	~Button() override = default;

	void click();


private:

	ButtonType type_;
	bool clicked_;
	std::function<void()> callback_;

};
#endif