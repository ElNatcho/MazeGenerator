#ifndef CMAZESAVER_HPP
#define CMAZESAVER_HPP

// Includes
#include<SFML\Graphics.hpp>
#include<iostream>
#include<exception>
#include"CMazeGenerator.hpp"

// CMazeSaver
class CMazeSaver {
public:

	// -- Kon/Destruktor --
	CMazeSaver();
	~CMazeSaver();

	// -- Methoden --
	void exportMaze(const std::string path, const Maze &maze);

private:

	// -- Member Vars --
	sf::Image *_img;

};

#endif