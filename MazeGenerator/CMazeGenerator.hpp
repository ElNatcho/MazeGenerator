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
#define IS_PATH 0x10 // Legt den Punkt als Teil eines Pfads fest

typedef unsigned char BYTE;
typedef std::vector<std::vector<BYTE>> Maze;

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
	void setConProbability(int p);
	void setMazeSize(int x, int y);
	void generateMaze();
	Maze getMaze();

private:

	// -- Member Vars --
	MazeSize *_mazeSize;

	Maze *_mazeData;

	std::vector<BYTE> *_availableOptions;
	BYTE *_curOption;

	int *_conProbability;

	// -- Member Methoden --
	void _createMazeData();
	int  _getCellData(int x, int y);
	void _getAvailableOptions(int x, int y);
	void _generateMaze(int x, int y);
	void _connectPixel(int x, int y);

};

#endif