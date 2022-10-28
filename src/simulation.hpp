#ifndef SIMULATION_HPP_
#define SIMULATION_HPP_

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>
#include "particle.hpp"

class Simulation {
 private:
  std::vector<Particle> particles;
  std::vector<sf::Uint8> textureData;
  sf::Texture texture;
  sf::Sprite renderSprite;

  uint32_t width;
  uint32_t height;

  void swapParticle(size_t p1idx, size_t p2idx);
  void writeToTextureData(size_t pidx, sf::Color color);
  inline size_t indexOf(size_t xPos, size_t yPos) const;

 public:
  Simulation(uint32_t width,
             uint32_t height,
             uint32_t particleDimensions);
  sf::Sprite getSprite() const;
  void draw(sf::RenderWindow* window) const;
  void update();
};

#endif  // SIMULATION_HPP_
