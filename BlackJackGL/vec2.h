#ifndef vec_2_h
#define vec_2_h

class vec2 {

public:

	float x_, y_;

	vec2();
	vec2(float p_x, float p_y);

	const vec2 operator+(const vec2&);
	const vec2 operator-(const vec2&);
	const vec2 operator+(float);
	const vec2 operator-(float);

};
#endif