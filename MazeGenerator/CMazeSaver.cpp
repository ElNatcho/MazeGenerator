#include"CMazeSaver.hpp"

// -- Konstruktor --
CMazeSaver::CMazeSaver() {
	// Alloc Memory
	_img = new sf::Image();

}

// -- exportMaze --
// Methode die das Labyrinth in eine Datei exportiert
// @param path: Pfad zur/Name der Datei in die das Labyrinth exportiert werden soll
// @param maze: Labyrinth, dass exportiert werden soll
//
void CMazeSaver::exportMaze(const std::string path, const Maze &maze) {
	if (maze.size() <= 0 || maze.at(0).size() <= 0) {
		throw std::exception("EXCEPTION: BAD_MAZE_SIZE");
		return;
	} else {
		_img->create(maze.at(0).size() * 2 + 1, maze.size() * 2 + 1);
		for (int y = 0; y < maze.size(); y++) {
			for (int x = 0; x < maze.at(y).size(); x++) {
				if (maze.at(y).at(x) > 0) {
					_img->setPixel(x * 2 + 1, y * 2 + 1, sf::Color::White);
					if (static_cast<bool>(maze.at(y).at(x) & PATH_R)) {
						_img->setPixel(x * 2 + 2, y * 2 + 1, sf::Color::White);
						_img->setPixel(x * 2 + 3, y * 2 + 1, sf::Color::White);
					} if (static_cast<bool>(maze.at(y).at(x) & PATH_D)) {
						_img->setPixel(x * 2 + 1, y * 2 + 2, sf::Color::White);
						_img->setPixel(x * 2 + 1, y * 2 + 3, sf::Color::White);
					} if (static_cast<bool>(maze.at(y).at(x) & PATH_U)) {
						_img->setPixel(x * 2 + 1, y * 2    , sf::Color::White);
						_img->setPixel(x * 2 + 1, y * 2 - 1, sf::Color::White);
					} if (static_cast<bool>(maze.at(y).at(x) & PATH_L)) {
						_img->setPixel(x * 2    , y * 2 + 1, sf::Color::White);
						_img->setPixel(x * 2 - 1, y * 2 + 1, sf::Color::White);
					}
				}
			}
		}
	}
	_img->saveToFile(path);
}

// -- Destruktor --
CMazeSaver::~CMazeSaver() {
	// Free Memory
	SAFE_DELETE(_img);
}