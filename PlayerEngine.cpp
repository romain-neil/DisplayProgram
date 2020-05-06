//
// Created by romain on 18/04/2020.
//

#include "PlayerEngine.h"

void PlayerEngine::loadFile(const std::string& fileName, const sf::Font& font) {

	std::string text, line;

	std::ifstream in(fileName);

	while(std::getline(in, line)) {
		text += line;
	}

	std::vector<std::string> symbols;

	if(doc.Parse(text.c_str()).HasParseError()) {
		throw std::runtime_error("Error while parsing JSON provided");
	}

	const rj::Value &allSlides = doc["slides"];
	assert(allSlides.IsArray());

	assert(doc["width"].IsInt());
	windowX = static_cast<float>(doc["width"].GetInt());

	assert(doc["height"].IsInt());
	windowY = static_cast<float>(doc["height"].GetInt());

	//Itérer à travers tous les slides
	for(rj::SizeType i = 0; i  < allSlides.Size(); i++) {
		Slide slide;

		slide.setId(allSlides[i]["id"].GetInt());

		const rj::Value &elements = allSlides[i]["elements"];

		assert(allSlides[i]["duration"].IsInt());
		slide.setDuration(allSlides[i]["duration"].GetInt());

		//On itère à travers les éléments
		for(rj::SizeType j = 0; j < elements.Size(); j++) {

			auto position = elements[j]["position"].GetArray();

			int x, y;

			for(const auto & it : position) {
				auto pos = it.GetObject();

				x = pos["x"].GetInt();
				y = pos["y"].GetInt();

			}

			sf::Vector2f pos(static_cast<float>(x), static_cast<float>(y));

			switch(elements[j]["type"].GetInt()) { //Gestion du type
				case Element::Texte:
					slide.addText(getText(elements[j]["text"].GetString(), elements[j]["size"].GetInt(), pos, font));
					break;
				case Element::Image:
					slide.addSprite(getSprite(elements[j]["image"].GetString(), pos));
					break;
			}
		}

		addSlide(slide);

	}

	//On trie les slides par leur id
	m_slides.sort();

}

sf::Vector2f PlayerEngine::getWindowDimensions() const {
	return sf::Vector2f(windowX, windowY);
}

void PlayerEngine::addSlide(const Slide& slide) {
    m_slides.push_back(slide);
}

void PlayerEngine::Run(sf::RenderWindow &window) {

	sf::Event e{};

	while(window.isOpen()) {

		for(Slide s : m_slides) {

			while(window.pollEvent(e)) {
				if (e.type == sf::Event::Closed)
					window.close();
			}

			s.Run(window);
		}

	}

}

sf::Text PlayerEngine::getText(const std::string& text, int characterSize, sf::Vector2f pos, const sf::Font& font) {
	sf::Text temp;

	temp.setFont(font);
	temp.setString(sf::String(text));
	temp.setCharacterSize(characterSize);
	temp.setPosition(pos);

	return temp;
}

sf::Sprite PlayerEngine::getSprite(const std::string &file, sf::Vector2f pos) {
	sf::Sprite temp;
	sf::Texture t;

	t.loadFromFile(file);

	temp.setTexture(t);
	temp.setPosition(pos);

	return temp;
}