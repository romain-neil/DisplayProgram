//
// Created by romain on 18/04/2020.
//

#ifndef DISPLAYPROGRAM_PLAYERENGINE_H
#define DISPLAYPROGRAM_PLAYERENGINE_H

#include <iostream>
#include <stdexcept>
#include <fstream>
#include <string>
#include <tuple>
#include <list>

#include <SFML/Graphics.hpp>
#include <rapidjson/document.h>
#include "Slide.h"

namespace rj = rapidjson;

class PlayerEngine {

	public:

		PlayerEngine() = default;

		/**
		 * Charge un fichier et contruit les slides correspondantes
		 * @param fileName
		 */
		void loadFile(const std::string& fileName, const sf::Font& font);

		/**
		 * Retourne la dimension de la fenêtre à créer
		 * @return
		 */
		[[nodiscard]] sf::Vector2f getWindowDimensions() const;

		/**
		 * Lance la boucle principale
		 * @param window
		 */
		void Run(sf::RenderWindow &window);

		/**
		 * Retourne le nombre de slide
		 * @return
		 */
		[[nodiscard]] int getSlideCount() const { return m_slides.size(); }

	private:

		/**
		 * Permet d'obtenir un object sf::Text
		 * @param text Le texte
		 * @param characterSize La taille en pixel
		 * @param pos La position
		 * @param font La font à utiliser
		 * @return
		 */
		static sf::Text getText(const std::string& text, int characterSize, sf::Vector2f pos, const sf::Font& font);

		/**
		 * Permet d'obtenir un objet sf::Sprite
		 * @param file Le fichier de l'image
		 * @param pos
		 * @return
		 */
		static sf::Sprite getSprite(const std::string &file, sf::Vector2f pos);

		/**
		 * Ajouter un slide
		 * @param slide le slide à ajouter
		 */
		void addSlide(const Slide& slide);

		/**
		 * Liste des slide
		 */
        std::list<Slide> m_slides;

        float windowX{}, windowY{};

        /**
         * Document rapidjson
         * @see rapidjson::Document
         */
        rj::Document doc;

};


#endif //DISPLAYPROGRAM_PLAYERENGINE_H
