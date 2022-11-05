#ifndef SIMULATION_HPP_
#define SIMULATION_HPP_

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>
#include "particle.hpp"

class Simulation {
 private:
  std::vector<std::shared_ptr<Particle>> particles;
  std::vector<sf::Uint8> texture_data;
  sf::Texture texture;
  sf::Sprite render_sprite;

  uint32_t width;
  uint32_t height;

  void swapParticle(size_t p1idx, size_t p2idx);
  void writeToTextureData(size_t pidx);
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
