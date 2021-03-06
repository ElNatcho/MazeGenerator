#ifndef CIMGRENDERER_HPP
#define CIMGRENDERER_HPP

// Includes
#include<SFML\Graphics.hpp>
#include<iostream>

#define SAFE_DELETE(X) {if(X!=nullptr){delete(X); X=nullptr;}}

#define LONGER_SIDE 600.F

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
	sf::RenderWindow *_win;
	sf::Event *_sfEvent;

	sf::Sprite  *_spr;
	sf::Texture *_tex;

	float *_tmpScale;
	bool  *_isSet;

};

#endif