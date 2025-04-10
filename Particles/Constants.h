#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <map>
#include <algorithm>
#include <random>

// CONSTANTS
const sf::Vector2<int> K_WINDOWXY = { 800, 600 };
const int K_NUMPARTICLES = 10;
const float K_PARTICLERADIUS = 5.f;
const float K_PARTICLEVELOCITY = 20.f;

const sf::Vector2<int> K_UP = { 0, -1 };
const sf::Vector2<int> K_UPRIGHT = { 1, -1 };
const sf::Vector2<int> K_UPLEFT = { -1, -1 };
const sf::Vector2<int> K_DOWN = { 0, 1 };
const sf::Vector2<int> K_DOWNRIGHT = { 1, 1 };
const sf::Vector2<int> K_DOWNLEFT = { -1, 1 };

// associate directions with numbers to get a random value
const std::map<int, sf::Vector2<int>> directionMap = {
	{0, K_UP},
	{1, K_UPRIGHT},
	{2, K_UPLEFT},
	{3, K_DOWN},
	{4, K_DOWNRIGHT},
	{5, K_DOWNLEFT}
};

// associate colours with numbers to get a random value
const std::map<int, sf::Color> colourMap = {
	{0, sf::Color::Red},
	{1, sf::Color::Blue},
	{2, sf::Color::Green},
	{3, sf::Color::Yellow},
	{4, sf::Color::Magenta},
};