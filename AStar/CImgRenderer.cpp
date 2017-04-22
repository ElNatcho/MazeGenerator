#include"CImgRenderer.hpp"

// -- Konstruktor --
CImgRenderer::CImgRenderer() {
	// Alloc Memory
	_win = new sf::RenderWindow(sf::VideoMode(600, 600), "Labyrinth Renderer");
	_spr = new sf::Sprite();
	_tex = new sf::Texture();
	_sfEvent = new sf::Event();
}

// -- render --
// Methode rendert das Labyrinth Image
// @param img: Image, dass gerendert werden soll
//
void CImgRenderer::render(sf::Image &img) {
	while (_win->pollEvent(*_sfEvent)) {

	}

	_win->clear(sf::Color(255, 0, 80));

	_tex->loadFromImage(img);
	_spr->setTexture(*_tex);
	_spr->setScale(_win->getSize().x / img.getSize().x,
				   _win->getSize().y / img.getSize().y);

	_win->draw(*_spr);

	_win->display();
}

// -- Destruktor --
CImgRenderer::~CImgRenderer() {
	// Free Memory
	SAFE_DELETE(_win);
	SAFE_DELETE(_spr);
	SAFE_DELETE(_tex);
	SAFE_DELETE(_sfEvent);
}