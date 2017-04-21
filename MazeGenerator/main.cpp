#include"CMazeGenerator.hpp"

int main() {
	CMazeGenerator *mazeGenerator = new CMazeGenerator();

	mazeGenerator->setMazeSize(7, 7);
	mazeGenerator->generateMaze();

	return 0;
}