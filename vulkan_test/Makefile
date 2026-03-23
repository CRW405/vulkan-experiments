LDFLAGS = -lglfw -lvulkan -ldl -lpthread

vulkantest: vulkan_test.c
	gcc vulkan_test.c $(LDFLAGS) -o vulkan_test

.PHONY: test clean

test: vulkantest
	./vulkan_test

clean:
	rm vulkan_test
