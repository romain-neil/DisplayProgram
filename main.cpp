#include <exception>
#include <iostream>
#include <cstdlib>
#include <SFML/Graphics.hpp>

#include "PlayerEngine.h"

void write(const std::string& t) {
	std::cout << t << std::endl;
}

int main(int argc, char* argv[]) {

	write("Starting player engine ...");

	PlayerEngine engine;

	sf::Font arial;
	arial.loadFromFile("./arial.ttf");

	try {
		engine.loadFile("./test.json", arial);
	} catch(std::exception &e) {
		std::cerr << "Error : " << e.what() << std::endl;
		exit(EXIT_FAILURE);
	}

	write("Parsing done. Creating window ...");

	sf::Vector2f dimensions = engine.getWindowDimensions();

	sf::RenderWindow window(sf::VideoMode(static_cast<uint32_t>(dimensions.x), static_cast<uint32_t>(dimensions.y)), "Screen Player");
	window.setFramerateLimit(60);

	write("Window created. Starting rendering.");

	engine.Run(window);

	write("Exiting ...");

	return EXIT_SUCCESS;
}
