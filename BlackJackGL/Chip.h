#ifndef CHIP_H
#define CHIP_H

#include "Button.h"

class Chip : public Button {

public:
	
	Chip();
	Chip(vec2 pos, vec2 size, ButtonShape shape, std::function<void()> callback);

	~Chip() override = default;

	void click() override;

	void render() const override;

private:

	int value_;

};
#endif