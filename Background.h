#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <SFML/Graphics.hpp>
#include <list>

class Background {
private:
    sf::Color groundColor;
    sf::Color particleColor;
    int intensity;
    struct particle {
        int x;
        int y;
        int size;
        int speed;
        sf::RectangleShape look;
    };
    std::list<particle> particleList;
    sf::RectangleShape backdrop;
public:
    Background();
    void setIntensity(int);
    void setGroundColor(sf::Color);
    void setParticleColor(sf::Color);
    sf::Color getGroundColor();
    sf::Color getParticleColor();
    int getIntesity();

    void logic();
    void render(sf::RenderWindow*);
};

#endif
