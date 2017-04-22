#ifndef CIMGRENDERER_HPP
#define CIMGRENDERER_HPP

// Includes
#include<SFML\Graphics.hpp>
#include<iostream>

// CImgRenderer
class CImgRenderer {
public:

	// -- Kon/Destruktor --
	CImgRenderer();
	~CImgRenderer();

	// -- Methoden --
	void render(sf::Image &img);

private:

	// -- Member Vars --
	sf::RenderWindow _win;
	sf::Event _sfEvent;

	sf::Sprite _spr;
	sf::Texture _tex;
};

#endif