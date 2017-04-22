#include"CAStar.hpp"

// -- Konstruktor --
CAStar::CAStar() {
	// Free Memory
	/*_img = new sf::Image();
	_endP = new Point;
	_tmpP = new Point;
	_curP = new Point;
	_beginP = new Point;
	_tmpDist = new double;
	_openList = new std::vector<Point>();
	_closedList = new std::vector<Point>();*/
}

// -- solve --
// Methode löst ein monochromes Labyrinth und gibt das gelöste Labyrinth zurück
// @param path: Pfad zum/Name des Labyrinths, dass gelöst werden soll
//
sf::Image CAStar::solve(std::string path) {
	if(!_img.loadFromFile(path)) // Bild sicher laden
		throw std::exception(std::string("EXCEPTION: Cannot_load_Image: " + path).c_str());

	setPoints(1, 1, _img.getSize().x - 2, _img.getSize().y - 2);
	_openList.push_back(_beginP);
	_getBestPoint();
	_img.setPixel(_curP.x, _curP.y, sf::Color::Red);
	_imgRenderer.render(_img);

	while (true && _openList.size() > 0) {
		// Testen ob der Endpunkt erreicht wurde
		if (_curP.x == _endP.x && _curP.y == _endP.y)
			break;

		// Umliegende Punkte in _openList einfügen
		_getSurroundingPoints();

		// Aktuellen Punkt aus der _openList entfernen und in die _closedList einfügen
		for (int i = 0; i < _openList.size(); i++) {
			if (_curP.x == _openList.at(i).x && _curP.y == _openList.at(i).y) {
				_closedList.push_back(_curP);
				_openList.erase(_openList.begin() + i);
				break;
			}
		}

		// Den besten Punkt suchen und in _curP speichern
		_getBestPoint();

		_img.setPixel(_curP.x, _curP.y, sf::Color::Red);
		_imgRenderer.render(_img);
	}

	_buildPath();

	return _img;
}

// -- setPoints --
// Methode setzt den Start- und Endpunkt
// @param bx, by: Position des Startpunkts
// @param ex, ey: Position des Endpunkts
//
void CAStar::setPoints(int bx, int by, int ex, int ey) {
	_endP.x = ex;
	_endP.y = ey;
	_endP.dist = 0;
	_beginP.x = bx;
	_beginP.y = by;
	_beginP.dist = _getDist(_endP, _beginP);
}

// -- _getDist --
// Methode gibt die Entfernung von zwei Punkten zurück
// @param p1, p2: Punkte deren Entfernung berechnet werden sollen
//
double CAStar::_getDist(Point p1, Point p2) {
	return std::sqrt(
		std::pow(std::abs(p1.x - p2.x), 2) + 
		std::pow(std::abs(p1.y - p2.y), 2));
}

// -- _getBestPoint --
// Methode sucht den besten Punkt aus der openList und speichert ihn in _curP
//
void CAStar::_getBestPoint() {
	_tmpDist = _openList.at(0).dist;
	for (int i = 0; i < _openList.size(); i++) {
		_tmpDist = std::min(_openList.at(i).dist, _tmpDist);
		if (_tmpDist == 0) {
			_curP = _openList.at(i);
			return;
		}
	}
	for (int i = 0; i < _openList.size(); i++) {
		if (_tmpDist == _openList.at(i).dist) {
			_curP = _openList.at(i);
			break;
		}
	}
}

// -- getSurroundingPoints --
// Methode fügt die Umliegenden Labyrinth-Knoten in die _openList ein
//
void CAStar::_getSurroundingPoints() {
	if (_img.getPixel(_curP.x - 1, _curP.y) == sf::Color::White &&
		_pointIsValid(_curP.x - 2, _curP.y)) {
		_addPoint(&_openList, _curP.x - 2, _curP.y, _curP.x, _curP.y);
	}
	if (_img.getPixel(_curP.x + 1, _curP.y) == sf::Color::White &&
		_pointIsValid(_curP.x + 2, _curP.y)) {
		_addPoint(&_openList, _curP.x + 2, _curP.y, _curP.x, _curP.y);
	}
	if (_img.getPixel(_curP.x, _curP.y - 1) == sf::Color::White &&
		_pointIsValid(_curP.x, _curP.y - 2)) {
		_addPoint(&_openList, _curP.x, _curP.y - 2, _curP.x, _curP.y);
	}
	if (_img.getPixel(_curP.x, _curP.y + 1) == sf::Color::White &&
		_pointIsValid(_curP.x, _curP.y + 2)) {
		_addPoint(&_openList, _curP.x, _curP.y + 2, _curP.x, _curP.y);
	}
}

// -- _addPoint --
// Methode fügt einen Punkt in eine Liste ein
// @param l: Liste in die der Punkt eingefügt werden soll
// @param x, y: Position des Punkts
// @param ox, oy: Herkunft
//
void CAStar::_addPoint(std::vector<Point> *l, int x, int y, int ox, int oy) {
	_tmpP.x = x;
	_tmpP.y = y;
	_tmpP.origin_x = ox;
	_tmpP.origin_y = oy;
	_tmpP.dist = _getDist(_tmpP, _endP);
	l->push_back(_tmpP);
}

// -- _pointIsValid --
// Methode überprüft ob ein Punkt in der _closedList vorhanden ist
// @paran x, y: Punkt der geprüft werden soll
//
bool CAStar::_pointIsValid(int x, int y) {
	for (int i = 0; i < _closedList.size(); i++) {
		if (x == _closedList.at(i).x && y == _closedList.at(i).y)
			return false;
	}
	return true;
}

// -- _buildPath --
// Methode zeichnet den Lösungsweg in das Labyrinth ein
//
void CAStar::_buildPath() {
	_img.setPixel(_curP.x, _curP.y, sf::Color::Yellow);
	_imgRenderer.render(_img);
	for (int i = _closedList.size() - 1; i >= 0; i--) {
		if (_curP.origin_x == _closedList.at(i).x &&
			_curP.origin_y == _closedList.at(i).y) {
			_curP = _closedList.at(i);
			_img.setPixel(_curP.x, _curP.y, sf::Color::Yellow);
			_imgRenderer.render(_img);
		}

	}
}

// -- Destruktor --
CAStar::~CAStar() {
	// Free Memory
	/*SAFE_DELETE(_img);
	SAFE_DELETE(_endP);
	SAFE_DELETE(_tmpP);
	SAFE_DELETE(_curP);
	SAFE_DELETE(_beginP);
	SAFE_DELETE(_tmpDist);
	SAFE_DELETE(_openList);
	SAFE_DELETE(_closedList);*/
}