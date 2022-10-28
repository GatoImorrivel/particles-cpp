#include "particle.hpp"

Particle::Particle(Particles type, sf::Color color, ParticleUpdater updater) {
  this->type = type;
  this->color = color;
  this->updater = updater;
}

sf::Color Particle::getColor() const {
  return this->color;
}

// EMPTY PARTICLE
static uint32_t updateEmpty(const uint32_t position,
                            const std::vector<Particle>* particles) {
  return position;
}

Particle Particle::empty() {
  return Particle(Particles::Empty, sf::Color::Black, updateEmpty);
}

// SAND PARTICLE
static uint32_t updateSand(const uint32_t position,
                           const std::vector<Particle>* particles) {
  return position;
}

Particle Particle::sand() {
  return Particle(Particles::Sand, sf::Color::Yellow, updateSand);
}

// WATER PARTICLE
static uint32_t updateWater(const uint32_t position,
                            const std::vector<Particle>* particles) {
  return position;
}

Particle Particle::water() {
  return Particle(Particles::Water, sf::Color::Blue, updateWater);
}
