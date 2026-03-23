LDFLAGS = -lglfw -lvulkan -ldl -lpthread

vulkantest: triangle.c
	gcc triangle.c $(LDFLAGS) -o triangle

.PHONY: test clean

test: triangle
	./triangle

clean:
	rm triangle
