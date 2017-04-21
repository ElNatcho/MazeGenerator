#include"CMazeSaver.hpp"

int main() {
	CMazeGenerator *mazeGenerator = new CMazeGenerator();
	CMazeSaver	   *mazeSaver	  = new CMazeSaver();

	mazeGenerator->setMazeSize(7, 7);
	mazeGenerator->generateMaze();
	mazeSaver->exportMaze("test.png", mazeGenerator->getMaze());

	return 0;
}