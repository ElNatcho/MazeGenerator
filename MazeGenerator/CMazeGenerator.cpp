#include"CMazeGenerator.hpp"

// -- Konstruktor --
CMazeGenerator::CMazeGenerator() {
	// Alloc Memory
	_mazeSize = new MazeSize();

}

// -- setMazeSize --
// Methode legt die Gr��e des Labyrinths fest
// @param x, y: Neue Gr��e
//
void CMazeGenerator::setMazeSize(int x, int y) {

}

// -- generateMaze --
// Methode erstellt das Labyrinth
//
void CMazeGenerator::generateMaze() {

}

// -- Destruktor --
CMazeGenerator::~CMazeGenerator() {
	// Free Memory
	SAFE_DELETE(_mazeSize);
}