#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <map>
#include <algorithm>
#include <random>

// CONSTANTS
const int K_NUMTHREADS = 4;		// Number of threads to split particle processing accross

const sf::Vector2<int> K_WINDOWXY = { 800, 600 };

const int K_NUMPARTICLES = 10;
const float K_PARTICLERADIUS = 5.f;
//const float K_PARTICLESPEED = 5.f;
const float K_PARTICLESPEEDLOWER = 1.f;
const float K_PARTICLESPEEDUPPER = 10.f;

const sf::Vector2<int> K_UP = { 0, -1 };
const sf::Vector2<int> K_UPRIGHT = { 1, -1 };
const sf::Vector2<int> K_UPLEFT = { -1, -1 };
const sf::Vector2<int> K_DOWN = { 0, 1 };
const sf::Vector2<int> K_DOWNRIGHT = { 1, 1 };
const sf::Vector2<int> K_DOWNLEFT = { -1, 1 };
const sf::Vector2<int> K_LEFT = { -1, 0 };
const sf::Vector2<int> K_RIGHT = { 1, 0 };

// associate directions with numbers to get a random value
const std::map<int, sf::Vector2<int>> directionMap = {
	{0, K_UP},
	{1, K_UPRIGHT},
	{2, K_UPLEFT},
	{3, K_DOWN},
	{4, K_DOWNRIGHT},
	{5, K_DOWNLEFT},
	{6, K_LEFT},
	{7, K_RIGHT}
};

// Pick between values when colliding with screen sides
const std::map<int, sf::Vector2<int>> collidingRight = {
	{0, K_UPLEFT},
	{1, K_DOWNLEFT},
	{2, K_LEFT}
};

const std::map<int, sf::Vector2<int>> collidingLeft = {
	{0, K_UPRIGHT},
	{1, K_DOWNRIGHT},
	{2, K_RIGHT}
};

const std::map<int, sf::Vector2<int>> collidingUp = {
	{0, K_DOWNRIGHT},
	{1, K_DOWNLEFT},
	{2, K_DOWN}
};

const std::map<int, sf::Vector2<int>> collidingDown = {
	{0, K_UPRIGHT},
	{1, K_UPLEFT},
	{2, K_UP}
};

// associate colours with numbers to get a random value
const std::map<int, sf::Color> colourMap = {
	{0, sf::Color::Red},
	{1, sf::Color::Blue},
	{2, sf::Color::Green},
	{3, sf::Color::Yellow},
	{4, sf::Color::Magenta},
};