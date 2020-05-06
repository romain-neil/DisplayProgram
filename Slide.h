//
// Created by romain on 20/04/2020.
//

#ifndef DISPLAYPROGRAM_SLIDE_H
#define DISPLAYPROGRAM_SLIDE_H

#include <ctime>
#include <vector>
#include <SFML/Graphics.hpp>
#include <list>

enum Element {
	Texte = 0,
	Image
};

/**
 * Classe qui représente un écran dans une liste de lecture
 */
class Slide {

	public:

		Slide() = default;

		/**
		 * Ajoute un texte
		 * @param t Texte à ajouter
		 */
		void addText(const sf::Text& t);

		/**
		 * Ajoute une image
		 * @param i Image à ajouter
		 */
		void addSprite(const sf::Sprite& i);

		/**
		 * Lance le rendu des éléments attachés à ce slide
		 * @param window
		 */
		void Run(sf::RenderWindow &window);

		void setId(int id) { m_id = id; }
		[[nodiscard]] int getId() const { return m_id; }

		/**
		 * Règle la durée du slide
		 * @param d Durée en secondes
		 */
		void setDuration(int d) { m_duration = d; }
		[[nodiscard]] int getDuration() const { return m_duration; }

		bool operator<(const Slide &left) const {
			return m_id < left.getId();
		}

		/**
		 * Horloge pour la durée du slide
		 */
		sf::Clock timer;

	private:

		int m_id{};

		/**
		 * Liste contenant les textes
		 */
		std::list<sf::Text> m_texts;

		/**
		 * Liste contenant les images
		 */
		std::list<sf::Sprite> m_images;

		int m_duration{};

};

#endif //DISPLAYPROGRAM_SLIDE_H
