#include"CAStar.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "CAStar.exe <Img_Path>" << std::endl;
		return 0;
	}
	
	CAStar *astar = new CAStar();

	std::string file_name = argv[1];
	file_name = file_name.substr(0, file_name.size() - 4);
	file_name += "_solved.png";

	try {
		astar->solve(argv[1]).saveToFile(file_name);
	} catch (std::exception e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}