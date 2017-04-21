#include"CMazeSaver.hpp"

int main(int argc, char **argv) {
	if (argc != 4) {
		std::cout << "CMazeSaver.exe <size_x> <size_y> <img_path>" << std::endl;
		return 0;
	}

	srand(time(0));

	CMazeGenerator *mazeGenerator = new CMazeGenerator();
	CMazeSaver	   *mazeSaver	  = new CMazeSaver();

	mazeGenerator->setMazeSize(std::stoi(argv[1]), std::stoi(argv[2]));
	mazeGenerator->generateMaze();
	mazeSaver->exportMaze(argv[3], mazeGenerator->getMaze());

	return 0;
}