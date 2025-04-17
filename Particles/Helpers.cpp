#include "Helpers.h"

int Helpers::getRandomNum(int lowerRange, int upperRange)
{
    //generate random number that only regenerates on new function call
    //float randomNum = (rand() % upperRange) + 1;

    //https://stackoverflow.com/questions/13445688/how-to-generate-a-random-number-in-c
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(lowerRange, upperRange); // distribution

    return dist(rng);
}

sf::Color Helpers::getRandomColour()
{
    int colourKey = getRandomNum(0, colourMap.size() - 1);

    return colourMap.at(colourKey);
}

sf::Vector2<int> Helpers::getRandomDirection()
{
    int directionKey = getRandomNum(0, directionMap.size() - 1);

    return directionMap.at(directionKey);
}

sf::Vector2<int> Helpers::getCollisionAngle(std::string screenSide)
{
    int screenSideKey;

    if (screenSide == "Up")
    {
        screenSideKey = getRandomNum(0, collidingUp.size() - 1);
        return collidingUp.at(screenSideKey);
    }
    if (screenSide == "Down")
    {
        screenSideKey = getRandomNum(0, collidingDown.size() - 1);
        return collidingDown.at(screenSideKey);
    }
    if (screenSide == "Right")
    {
        screenSideKey = getRandomNum(0, collidingRight.size() - 1);
        return collidingRight.at(screenSideKey);
    }
    if (screenSide == "Left")
    {
        screenSideKey = getRandomNum(0, collidingLeft.size() - 1);
        return collidingLeft.at(screenSideKey);
    }

    return sf::Vector2<int>();
}
