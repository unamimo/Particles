#include "Helpers.h"

//int Maths::getRandomNum(int lowerRange, int upperRange)
//{
//    //generate random number that only regenerates on new function call
//    //float randomNum = (rand() % upperRange) + 1;
//
//    //https://stackoverflow.com/questions/13445688/how-to-generate-a-random-number-in-c
//    std::random_device dev;
//    std::mt19937 rng(dev());
//    std::uniform_int_distribution<std::mt19937::result_type> dist(lowerRange, upperRange); // distribution
//
//    return dist(rng);
//}
//
//sf::Color Maths::getRandomColour()
//{
//    int colourKey = getRandomNum(0, colourMap.size() - 1);
//
//    return colourMap.at(colourKey);
//}
//
//sf::Vector2<int> Maths::getRandomDirection()
//{
//    int directionKey = getRandomNum(0, directionMap.size() - 1);
//
//    return directionMap.at(directionKey);
//}