#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <cstdint>
#include <memory>
#include <vector>
#include <iostream>

#include "simulation.hpp"

void Simulation::update() {
  std::cout << "TODO!" << "\n";
}

Simulation::Simulation(uint32_t width,
                       uint32_t height,
                       uint32_t particle_dimensions)
    : width(width / particle_dimensions),
      height(height / particle_dimensions),
      particles((width / particle_dimensions) * (height / particle_dimensions),
                std::make_shared<Particle>(particle_empty_)) {
  sf::Texture texture;
  if (!texture.create(this->width, this->height)) {
    throw "FAILED TO CREATE TEXTURE";
  }

  this->texture = texture;

  sf::Sprite sprite;
  sprite.setTexture(this->texture, false);
  sprite.setScale(particle_dimensions, particle_dimensions);

  this->render_sprite = sprite;
}

void Simulation::draw(sf::RenderWindow& window) const {
  window.draw(this->render_sprite);
}

inline size_t Simulation::indexOf(const size_t x_pos, const size_t y_pos) const {
  return y_pos * this->width + x_pos;
}

void Simulation::swapParticle(const size_t p1idx, const size_t p2idx) {

  this->writeToTextureData(p1idx);
  this->writeToTextureData(p2idx);
}

void Simulation::writeToTextureData(const size_t pidx) {
  auto color = this->particles[pidx]->color;

  this->texture_data[pidx * 4] = color.r;
  this->texture_data[pidx * 4 + 1] = color.g;
  this->texture_data[pidx * 4 + 2] = color.b;
  this->texture_data[pidx * 4 + 3] = color.a;
}

sf::Sprite Simulation::getSprite() const {
  return this->render_sprite;
}
