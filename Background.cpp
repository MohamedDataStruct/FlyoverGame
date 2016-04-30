#include "Background.h"

Background::Background() {
    groundColor = sf::Color::Black;
    particleColor = sf::Color::White;
    intensity = 1;
}

void Background::setGroundColor(sf::Color color) { groundColor = color; }

void Background::setParticleColor(sf::Color color) { particleColor = color; }

void Background::setIntensity(int x) { intensity = x; }

sf::Color Background::getGroundColor() { return groundColor; }

sf::Color Background::getParticleColor() { return particleColor; }

int Background::getIntesity() { return intensity; }

void Background::logic() {
    for(std::list<particle>::iterator it = particleList.begin(); it != particleList.end(); it++) {
        it->y+=intensity;
        it->look.setPosition(it->y-intensity,it->x-intensity);

    }
    particle newP = particle();
    newP.y = -2*intensity;
    newP.x = rand()%(500-intensity);
    newP.look = sf::RectangleShape(sf::Vector2f(2*intensity,2*intensity));
    newP.look.setPosition(newP.x,newP.y);
    particleList.push_front(newP);
}

void Background::render(sf::RenderWindow *window) {
    for(std::list<particle>::iterator it = particleList.begin(); it != particleList.end(); it++) {
        window->draw(it->look);
    }
}
