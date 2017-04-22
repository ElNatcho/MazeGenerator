#include"CImgRenderer.hpp"

// -- Konstruktor --
CImgRenderer::CImgRenderer() {
	// Alloc Memory
	_win = new sf::RenderWindow(sf::VideoMode(600, 600), "Labyrinth Renderer");
	_spr = new sf::Sprite();
	_tex = new sf::Texture();
	_isSet = new bool;
	_sfEvent = new sf::Event();
	_tmpScale = new float;

	// Werte setzen
	*_isSet = false;
	_tex->setSmooth(false);

}

// -- render --
// Methode rendert das Labyrinth Image
// @param img: Image, dass gerendert werden soll
//
void CImgRenderer::render(sf::Image &img) {
	if (!(*_isSet)) { // Fenster und Labyrinth richtig skallieren
		if (img.getSize().x == img.getSize().y) { // Testen ob die Seiten des Labyrinths gleich lang sind
			*_tmpScale = LONGER_SIDE / (float)img.getSize().x;
		} else { // Wenn die Seiten nicht gleich groß sind ...
			*_tmpScale = LONGER_SIDE / (float)(img.getSize().x > img.getSize().y ? img.getSize().x : img.getSize().y);
			if (img.getSize().x > img.getSize().y) { // Testen welche Seite länger ist
				_win->create(sf::VideoMode(LONGER_SIDE, img.getSize().y * (*_tmpScale)), "Labyrinth-Renderer");
			} else {
				_win->create(sf::VideoMode(img.getSize().x * *_tmpScale, LONGER_SIDE), "Labyrinth-Renderer");
			}
		}
		_spr->setScale(*_tmpScale, *_tmpScale); // Sprite Skallierung setzen
		*_isSet = true;
	}

	while (_win->pollEvent(*_sfEvent)) {

	}

	_win->clear(sf::Color(255, 0, 80));

	_tex->loadFromImage(img);
	_spr->setTexture(*_tex);

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
	SAFE_DELETE(_tmpScale);
}