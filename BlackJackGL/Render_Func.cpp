#include "Render_Func.h"

int load_texture(const char* file_path) {
	return SOIL_load_OGL_texture
	(
		file_path,
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_COMPRESS_TO_DXT
	);
}

void render_sprite(int texture, float pos_x, float pos_y, float size_w, float size_h) {
	// transparentnost sprajta
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	// omogucavanje da se tekstura iscrta 
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);

	glBegin(GL_QUADS);
	glTexCoord2f(0, 1);	glVertex2f(pos_x - size_w / 2, pos_y - size_h / 2);
	glTexCoord2f(1, 1); glVertex2f(pos_x + size_w / 2, pos_y - size_h / 2);
	glTexCoord2f(1, 0);	glVertex2f(pos_x + size_w / 2, pos_y + size_h / 2);
	glTexCoord2f(0, 0);	glVertex2f(pos_x - size_w / 2, pos_y + size_h / 2);
	glEnd();

	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
}

void render_fill_rectangle(float pos_x, float pos_y, float size_w, float size_h, float red, float green, float blue) {
	glColor3f(red, green, blue);
	glBegin(GL_QUADS);
	glVertex2f(pos_x - size_w / 2, pos_y - size_h / 2);
	glVertex2f(pos_x + size_w / 2, pos_y - size_h / 2);
	glVertex2f(pos_x + size_w / 2, pos_y + size_h / 2);
	glVertex2f(pos_x - size_w / 2, pos_y + size_h / 2);
	glEnd();
	glColor3f(1.0f, 1.0f, 1.0f);
}

void render_wireframe_rectangle(float pos_x, float pos_y, float size_w, float size_h, float red, float green, float blue) {
	glLineWidth(2.0f);
	glColor3f(red, green, blue);
	glBegin(GL_LINE_LOOP);
	glVertex2f(pos_x - size_w / 2, pos_y - size_h / 2);
	glVertex2f(pos_x + size_w / 2, pos_y - size_h / 2);
	glVertex2f(pos_x + size_w / 2, pos_y + size_h / 2);
	glVertex2f(pos_x - size_w / 2, pos_y + size_h / 2);
	glEnd();
	glColor3f(1.0f, 1.0f, 1.0f);
}

void render_circle(float pos_x, float pos_y, float radius, float red, float green, float blue) {

	int segments = 360;
	glBegin(GL_TRIANGLE_FAN);
	for (int i = 0; i <= segments; ++i) {
		float angle = 2. * PI * float(i) / float(segments);
		glColor3f(red, green, blue);
		glVertex2f(pos_x + radius * cos(angle), pos_y + radius * sin(angle));
	}
	glEnd();
	glColor3f(1.0f, 1.0f, 1.0f);
}

void render_text(const char* string, float pos_x, float pos_y, float red, float green, float blue, float scale) {

	char* c;

	glColor3f(red, green, blue);
	glPushMatrix();
	glTranslatef(pos_x, pos_y + 8, 0.0);
	glLineWidth(2.0);
	glScalef(0.14f * scale, 0.12f * scale, 0.0);

	for (c = (char*) string; *c != '\0'; c++)
		glutStrokeCharacter(GLUT_STROKE_ROMAN, *c);

	glPopMatrix();

	glColor3f(1.0f, 1.0f, 1.0f);
}