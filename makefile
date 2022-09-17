

.PHONY: build

build:
	g++ src/test.cpp src/glad.c src/shader.cpp src/stb_image.cpp src/camera.cpp -lglfw3 -lGL -lX11 -lpthread -lXrandr -lXi -ldl -I ./include -L ./lib
