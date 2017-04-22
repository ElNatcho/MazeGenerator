#include"CMazeSaver.hpp"

int main(int argc, char **argv) {
	if (argc != 5 && argc != 4) {
		std::cout << "CMazeSaver.exe <size_x> <size_y> <img_path> [con_probability]" << std::endl;
		return 0;
	}

	srand(time(0));

	CMazeGenerator *mazeGenerator = new CMazeGenerator();
	CMazeSaver	   *mazeSaver	  = new CMazeSaver();

	if (argc == 4)
		mazeGenerator->setConProbability(5);
	else
		mazeGenerator->setConProbability(std::stoi(argv[4]));

	try {
		mazeGenerator->setMazeSize(std::stoi(argv[1]), std::stoi(argv[2]));
		mazeGenerator->generateMaze();
		mazeSaver->exportMaze(argv[3], mazeGenerator->getMaze());
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}