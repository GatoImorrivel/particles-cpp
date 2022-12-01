#ifndef SIMULATION_HPP_
#define SIMULATION_HPP_

#include <SFML/Graphics.hpp>
#include <cstdint>
#include <memory>
#include <vector>
#include "particle.hpp"

class Simulation {
 private:
  std::vector<Particle> particles;
  std::vector<sf::Uint8> texture_data;
  sf::Texture texture;
  sf::Sprite render_sprite;

  uint32_t width;
  uint32_t height;

  void swapParticle(size_t p1idx, size_t p2idx);
  void writeToTextureData(size_t pidx);
  uint_fast32_t computeNewPosition(int x_pos, int y_pos) const;
  inline bool isPositionValid(int x_pos, int y_pos) const;
  inline size_t indexOf(size_t x_pos, size_t y_pos) const;

 public:
  Simulation(uint32_t width,
             uint32_t height,
             uint32_t particle_dimensions);
  sf::Sprite getSprite() const;
  void draw(sf::RenderWindow &window) const;
  void update();
};

#endif  // SIMULATION_HPP_
