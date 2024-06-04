#include "Update_Func.h"
#include "Chip.h"

void move_chip(Chip& chip, vec2 destination, float delta_time) {
	chip.set_pos(destination);
}
