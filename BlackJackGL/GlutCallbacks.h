#include "Globals.h"
#include "Game.h"

Game game;

static void display_callback(void) {
	glClear(GL_COLOR_BUFFER_BIT);

	game.display();

	glutSwapBuffers();
}

static void reshape_callback(int w, int h) {

	glViewport(0, 0, (int)w, (int)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0f, w, 0.0f, h);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

static void idle_callback(void) {

	game.idle();

	glutPostRedisplay();
}

static void keyboard_callback(unsigned char key, int x, int y) {
}

static void keyboard_up_callback(unsigned char key, int x, int y) {
}

static void mouse_callback(int button, int state, int x, int y) {
	game.mouse(button, state, x, y);
}

int gl_main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowPosition((int)window_pos_x, (int)window_pos_y);
	glutInitWindowSize((int)window_width, (int)window_height);
	glutCreateWindow(title.c_str());

	//game.init();

	glutDisplayFunc(display_callback);
	glutReshapeFunc(reshape_callback);
	glutIdleFunc(idle_callback);

	glutKeyboardFunc(keyboard_callback);
	glutKeyboardUpFunc(keyboard_up_callback);
	glutMouseFunc(mouse_callback);

	glutMainLoop();

	return 0;
}