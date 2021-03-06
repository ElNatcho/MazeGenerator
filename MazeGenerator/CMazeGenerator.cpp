#include"CMazeGenerator.hpp"

// -- Konstruktor --
CMazeGenerator::CMazeGenerator() {
	// Alloc Memory
	_mazeSize = new MazeSize();
	_mazeData = new Maze();
	_curOption = new BYTE;
	_conProbability = new int;
	_availableOptions = new std::vector<BYTE>();

}

// -- setConProbability --
// Methode legt die Wahrscheinlichkeit f�r Verbindungen fest
// @param p: Verbindungs Wahrscheinlichkeit
void CMazeGenerator::setConProbability(int p) {
	*_conProbability = p;
}

// -- setMazeSize --
// Methode legt die Gr��e des Labyrinths fest
// @param x, y: Neue Gr��e
//
void CMazeGenerator::setMazeSize(int x, int y) {
	_mazeSize->x = x;
	_mazeSize->y = y;
	_createMazeData();
}

// -- generateMaze --
// Methode erstellt das Labyrinth
//
void CMazeGenerator::generateMaze() {
	_generateMaze(0, 0);
	for (int y = 0; y < _mazeData->size(); y++) {
		for (int x = 0; x < _mazeData->at(y).size(); x++) {
			if (_mazeData->at(y).at(x) == 0) {
				_connectPixel(x, y);
				_generateMaze(x, y);
			}
		}
	}
}

// -- getMaze --
// Methode git das generierte Labyrinth zur�ck
//
Maze CMazeGenerator::getMaze() {
	return *_mazeData;
}

// -- resetMazeData --
// Methode erstellt die _mazeData-Matrix
//
void CMazeGenerator::_createMazeData() {
	_mazeData->clear();
	for (int y = 0; y < _mazeSize->y; y++) {
		_mazeData->push_back(std::vector<BYTE>());
		for (int x = 0; x < _mazeSize->x; x++) {
			_mazeData->at(y).push_back(0);
		}
	}
}

// -- _getCellData --
// Methode mit der man sicher auf den Inhalt einer Zelle zugreifen kann
// @param x, y: Position der Zelle
//
int CMazeGenerator::_getCellData(int x, int y) {
	if (x < 0 || x >= _mazeSize->x ||
		y < 0 || y >= _mazeSize->y) {
		return -1;
	} else {
		return _mazeData->at(y).at(x);
	}
}

// -- _getAvailableOptions --
// Methode pr�ft welche Richtungen von einem bestimmten Punkt aus verf�gbar sind
// @param x, y: Punkt
//
void CMazeGenerator::_getAvailableOptions(int x, int y) {
	_availableOptions->clear();
	if (_getCellData(x + 1, y) == 0)
		_availableOptions->push_back(PATH_R);
	if (_getCellData(x - 1, y) == 0)
		_availableOptions->push_back(PATH_L);
	if (_getCellData(x, y + 1) == 0)
		_availableOptions->push_back(PATH_D);
	if (_getCellData(x, y - 1) == 0)
		_availableOptions->push_back(PATH_U);
}

// -- _generateMaze --
// Methode die ein Labyrinth von einem bestimmten Punkt aus erzeugt
// @param x, y: Punkt von dem aus gestartet werden soll
//
void CMazeGenerator::_generateMaze(int x, int y) {
	_getAvailableOptions(x, y);
	while (_availableOptions->size() > 0) {
		// Zuf�llige Bewegungsrichtung ausw�hlen
		*_curOption = _availableOptions->at(rand() % _availableOptions->size());
		_mazeData->at(y).at(x) |= *_curOption;
		// Zuf�llige Verbindungen erzeugen
		if (_availableOptions->size() <= 2) {
			if (rand() % 100 < *_conProbability) {
				_connectPixel(x, y);
			}
		}
		if (*_curOption == PATH_L)
			x--;
		else if (*_curOption == PATH_R)
			x++;
		else if (*_curOption == PATH_U)
			y--;
		else if (*_curOption == PATH_D)
			y++;
		// Alle zurzeit verf�gbaren Bewegungsrichtungen abfragen
		_getAvailableOptions(x, y);
		_mazeData->at(y).at(x) |= IS_PATH;
	}
}

// -- _connectPixel --
// Methode Verbindet einen Pixel bzw einen Knoten mit einer anderen
// Labyrinth-Bahn und erzeugt so eine neue Kreuzung
// @param x, y: Punkt der mit einem umliegenden Punkt verbunden werdens soll
//
void CMazeGenerator::_connectPixel(int x, int y) {
	_availableOptions->clear();
	if (_getCellData(x + 1, y) > 0)
		_availableOptions->push_back(PATH_R);
	if (_getCellData(x - 1, y) > 0)
		_availableOptions->push_back(PATH_L);
	if (_getCellData(x, y + 1) > 0)
		_availableOptions->push_back(PATH_D);
	if (_getCellData(x, y - 1) > 0)
		_availableOptions->push_back(PATH_U);
	if(_availableOptions->size() > 0)
		_mazeData->at(y).at(x) |= _availableOptions->at(rand() % _availableOptions->size());
}

// -- Destruktor --
CMazeGenerator::~CMazeGenerator() {
	// Free Memory
	SAFE_DELETE(_mazeSize);
	SAFE_DELETE(_mazeData);
	SAFE_DELETE(_curOption);
	SAFE_DELETE(_availableOptions);
	SAFE_DELETE(_conProbability);
}