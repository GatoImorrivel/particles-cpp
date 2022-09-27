#ifndef SIMULATION_HPP_
#define SIMULATION_HPP_

#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include "particle.h"

class Simulation {
    private:
        std::vector<Particle> particles;
        std::vector<sf::Uint8> textureData;
        sf::Texture texture;
        sf::Sprite renderSprite;

        uint32_t width;
        uint32_t height;
    public:
        Simulation(const uint32_t width, const uint32_t height, const uint32_t particleDimensions);
        const inline size_t indexOf(const size_t x, const size_t y);
        const sf::Sprite getSprite();
        void swap(const size_t p1idx, const size_t p2idx);
        void update();
};

#endif // SIMULATION_HPP_