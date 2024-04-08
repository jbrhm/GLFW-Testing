#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cstdlib>
#include <map>
#include <iostream>
#include <chrono>
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 1280
#define HEIGHT 720

struct key{
	bool cur, prev;
};

GLFWwindow* window;
GLFWmonitor* monitor;
bool running, fullscreen;
std::map<int, key> keyMap;

void update(){}
void input(){
	glfwPollEvents();
	if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
		running = false;
		glfwSetWindowShouldClose(window, 1);
	}

	if(glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS && keyMap[GLFW_KEY_F].prev){
		if(!fullscreen) glfwSetWindowMonitor(window, monitor, 0, 0, WIDTH, HEIGHT, 0);
		if(fullscreen) glfwSetWindowMonitor(window, NULL, 0, 0, WIDTH, HEIGHT, 0);
		fullscreen = !fullscreen;
	}

	keyMap[GLFW_KEY_F].prev = glfwGetKey(window, GLFW_KEY_F);
}

void draw(){
	glClearColor(0.0, 0.0, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);


	glfwSwapBuffers(window);
}

int main(){
	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	if(!glfwInit()) std::cerr << "Failed to init GLFW" << std::endl;
	window = glfwCreateWindow(WIDTH, HEIGHT, "OpenGL Window", NULL, NULL);

	if(window == NULL){
		std::cerr << "Failed to open window" << std::endl;
		glfwTerminate();
		return EXIT_FAILURE;
	}

	glfwMakeContextCurrent(window);
	monitor = glfwGetPrimaryMonitor();
	running = true;
	fullscreen = false;

	double lastTime = 0.0;
	while(running){
		double time = glfwGetTime();
		double deltaTime = time-lastTime;

		if(deltaTime >= 1/60.0){
			lastTime = time;
			draw();
		}

		update();
		input();
		draw();
	}
	glfwDestroyWindow(window);
	glfwTerminate();
}
