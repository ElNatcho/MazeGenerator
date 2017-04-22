#ifndef CASTAR_HPP
#define CASTAR_HPP

// Includes
#include<SFML\Graphics.hpp>
#include<iostream>
#include<exception>
#include<vector>
#include<cmath>
#include"CImgRenderer.hpp"

#define SAFE_DELETE(X) {if(X!=nullptr){delete(X); X=nullptr;}}

// CAStar
class CAStar {
public:

	struct Point {
		int x;
		int y;
		int origin_x;
		int origin_y;
		double dist;
	};

	// -- Kon/Destruktor --
	CAStar();
	~CAStar();

	// -- Methoden --
	sf::Image solve(std::string path);
	void setPoints(int bx, int by, int ex, int ey);

private:

	// -- Member Vars --
	Point _beginP;
	Point _curP;
	Point _endP;
	Point _tmpP;
	std::vector<Point> _openList;
	std::vector<Point> _closedList;

	sf::Image _img;

	double _tmpDist;

	CImgRenderer *_imgRenderer;

	// -- Member Methoden --
	double _getDist(Point p1, Point p2);
	void   _getBestPoint();
	void   _getSurroundingPoints();
	void   _addPoint(std::vector<Point> *l, int x, int y, int ox, int oy);
	bool   _pointIsValid(int x, int y);
	void   _buildPath();

};

#endif