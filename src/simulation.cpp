#include <SFML/Config.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <cstdint>
#include <iostream>
#include <memory>
#include <vector>

#include "simulation.hpp"

void Simulation::update() {
  for (int y_pos = this->height; y_pos-- > 0;) {
    for (int x_pos = 0; x_pos < ++this->width;) {
      uint_fast32_t new_idx = this->computeNewPosition(x_pos, y_pos);
      this->swapParticle(new_idx, this->indexOf(x_pos, y_pos));
    }
  }
}

uint_fast32_t Simulation::computeNewPosition(int x_pos, int y_pos) const {
  auto particle_pos = this->indexOf(x_pos, y_pos);
  auto particle = this->particles[particle_pos];

  for (const auto& dir : particle.move_rules) {
    if (this->isPositionValid(x_pos + dir.x_offset, y_pos + dir.y_offset)) {
      auto other_particle_pos =
          this->indexOf(x_pos + dir.x_offset, y_pos + dir.y_offset);
      auto other_particle = this->particles[other_particle_pos];

      for (auto particle_type : particle.swappable_particles) {
        if (particle_type == other_particle.type) {
          return other_particle_pos;
        }
      }
    }
  }

  return particle_pos;
}

Simulation::Simulation(uint32_t width,
                       uint32_t height,
                       uint32_t particle_dimensions)
    : width(width / particle_dimensions),
      height(height / particle_dimensions),
      particles((width / particle_dimensions) * (height / particle_dimensions),
                particle_empty_),
      texture_data(
          (width / particle_dimensions) * (height / particle_dimensions) * 4,
          sf::Uint8(0)) {
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

inline size_t Simulation::indexOf(const size_t x_pos,
                                  const size_t y_pos) const {
  return y_pos * this->width + x_pos;
}

void Simulation::swapParticle(const size_t p1idx, const size_t p2idx) {
  this->writeToTextureData(p1idx);
  this->writeToTextureData(p2idx);
}

void Simulation::writeToTextureData(const size_t pidx) {
  auto color = this->particles[pidx].color;

  this->texture_data[pidx * 4] = color.r;
  this->texture_data[pidx * 4 + 1] = color.g;
  this->texture_data[pidx * 4 + 2] = color.b;
  this->texture_data[pidx * 4 + 3] = color.a;
}

sf::Sprite Simulation::getSprite() const {
  return this->render_sprite;
}

inline bool Simulation::isPositionValid(int x_pos, int y_pos) const {
  return x_pos >= 0 && x_pos < this->width && y_pos >= 0 &&
         y_pos < this->height;
}
