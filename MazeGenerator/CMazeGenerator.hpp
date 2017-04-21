#ifndef CMAZEGENERATOR_HPP
#define CMAZEGENERATOR_HPP

// Includes
#include<iostream>
#include<vector>

// SAFE_DELETE Makro
#define SAFE_DELETE(x) {if(x!=nullptr){delete(x); x=nullptr;}}

// Path-Flags
#define PATH_L 0x0008 // Pfad links
#define PATH_U 0x0004 // Pfad hoch
#define PATH_D 0x0002 // Pfad runter
#define PATH_R 0x0001 // Pfad rechts

#define IS_PATH 0x0010 // Bit das bestimmt ob der Knoten ein Weg ist

#define MAX_ROOM_NUM 0xFFE // Maximale Anzahl der Räume

// CMazeGenerator
class CMazeGenerator {
public:

	// Struktur die die Größe des Labyrinths abspeichert
	struct MazeSize {
		int x;
		int y;
	};

	// -- CMazeGenerator --
	CMazeGenerator();
	~CMazeGenerator();

	// -- Methoden --
	void setMazeSize(int x, int y);
	void generateMaze();

private:

	// -- Member Vars --
	MazeSize *_mazeSize;

};

#endif