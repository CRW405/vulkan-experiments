#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <cglm/vec4.h>
#include <cglm/mat4.h>
#include <stdio.h>


int main(int argc, char *argv[])
{
	printf("%s", "Testing glfw\n");
	if (!glfwInit()) {
		printf("Failed to initialize GLFW\n");
		return -1;
	}

	GLFWwindow* window = glfwCreateWindow(800, 600, "Vulkan Window", NULL, NULL);
	glfwMakeContextCurrent(window);

	if (!window) {
		printf("Failed to create GLFW window\n");
		glfwTerminate();
		return -1;
	}

	printf("%s", "Testing Vulkan\n");
	int extensionCount = 0;
	vkEnumerateInstanceExtensionProperties(NULL, &extensionCount, NULL);
	printf("Number of Vulkan extensions supported: %d\n", extensionCount);

	printf("%s\n", "Testing cglm");
	mat4 matrix;
	vec4 vec;
	vec4 test;
	glm_mat4_mulv(matrix, vec, test);

	while (!glfwWindowShouldClose(window)) {
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}
