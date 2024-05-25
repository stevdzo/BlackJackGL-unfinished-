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

enum class ButtonShape {

	RECTANGLE,
	CIRCLE

};

class Button : public GUIElement {

public:

	Button();
	Button(vec2 pos, vec2 size, ButtonShape shape, std::function<void()> callback);

	~Button() override = default;

	ButtonShape get_shape() const;

	virtual void click();

	void render() const override;

protected:

	ButtonShape shape_;
	bool clicked_;
	std::function<void()> callback_;

};
#endif