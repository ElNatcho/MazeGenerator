#ifndef CMAZEGENERATOR_HPP
#define CMAZEGENERATOR_HPP

// Includes
#include<iostream>
#include<vector>

// SAFE_DELETE Makro
#define SAFE_DELETE(x) {if(x!=nullptr){delete(x); x=nullptr;}}

// Path-Flags
#define PATH_L 0x08 // Pfad links
#define PATH_U 0x04 // Pfad hoch
#define PATH_D 0x02 // Pfad runter
#define PATH_R 0x01 // Pfad rechts

typedef unsigned char BYTE;

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

	std::vector<std::vector<BYTE>> *_mazeData;

	std::vector<BYTE> *_availableOptions;
	BYTE *_curOption;

	// -- Member Methoden --
	void _createMazeData();
	int  _getCellData(int x, int y);
	void _getAvailableOptions(int x, int y);
	void _generateMaze(int x, int y);

};

#endif