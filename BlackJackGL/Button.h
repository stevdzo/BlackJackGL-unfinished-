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
	Button(std::string tag, vec2 pos, vec2 size, ButtonShape shape, std::function<void()> callback, bool visible = true, bool enabled = true);

	~Button() override = default;

	ButtonShape get_shape() const;

	void enabled(bool);
	bool enabled(void);

	virtual void click();

	void set_callback(std::function<void()> c);

	void render() const override;

protected:

	ButtonShape shape_;
	bool enabled_;
	std::function<void()> callback_;

};
#endif