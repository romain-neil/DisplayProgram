//
// Created by romain on 20/04/2020.
//

#include "Slide.h"

void Slide::addText(const sf::Text& t) {
    m_texts.push_back(t);
}

void Slide::addSprite(const sf::Sprite& i) {
    m_images.push_back(i);
}

void Slide::Run(sf::RenderWindow &window) {

	auto duree = static_cast<float>(getDuration());

	//On s'assure que le timer commence à 0
	timer.restart();

	while(timer.getElapsedTime().asSeconds() <= duree) {
		window.clear(sf::Color::Black);

		for(sf::Text const &t : m_texts) { //On dessine les textes ...
			window.draw(t);
		}

		for(sf::Sprite const &s : m_images) { //Puis les images
			window.draw(s);
		}

		window.display();
	}

}
