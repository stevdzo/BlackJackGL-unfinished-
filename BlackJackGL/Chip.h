#ifndef CHIP_H
#define CHIP_H

#include "Button.h"

class Chip : public Button {

public:
	
	Chip();
	Chip(std::string tag, vec2 pos, vec2 size, ButtonShape shape, std::function<void()> callback, bool visible=true, bool enabled = true);

	~Chip() override = default;

	void click() override;

	int get_value() const;

	void render() const override;

private:

	int value_;

};
#endif