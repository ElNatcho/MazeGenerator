#include"CMazeGenerator.hpp"

// -- Konstruktor --
CMazeGenerator::CMazeGenerator() {
	// Alloc Memory
	_mazeSize = new MazeSize();
	_mazeData = new Maze();
	_curOption = new BYTE;
	_availableOptions = new std::vector<BYTE>();

}

// -- setMazeSize --
// Methode legt die Größe des Labyrinths fest
// @param x, y: Neue Größe
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
}

// -- getMaze --
// Methode git das generierte Labyrinth zurück
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
// Methode prüft welche Richtungen von einem bestimmten Punkt aus verfügbar sind
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
		*_curOption = _availableOptions->at(rand() % _availableOptions->size());
		_mazeData->at(y).at(x) |= *_curOption;
		if (*_curOption == PATH_L)
			x--;
		else if (*_curOption == PATH_R)
			x++;
		else if (*_curOption == PATH_U)
			y--;
		else if (*_curOption == PATH_D)
			y++;
		_getAvailableOptions(x, y);
	}
}


// -- Destruktor --
CMazeGenerator::~CMazeGenerator() {
	// Free Memory
	SAFE_DELETE(_mazeSize);
	SAFE_DELETE(_mazeData);
	SAFE_DELETE(_curOption);
	SAFE_DELETE(_availableOptions);
}