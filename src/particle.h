#ifndef PARTICLE_HPP_
#define PARTICLE_HPP_

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

class Particle;

enum Particles {
  Empty,
  Sand,
  Water,
};

using ParticleUpdater = const uint32_t (*)(const uint32_t,
                                           const std::vector<Particle>*);

class Particle {
 private:
  Particles type;
  sf::Color color;

 public:
  ParticleUpdater updater;
  Particle(Particles type, sf::Color color, ParticleUpdater updater);
  const sf::Color getColor();
  const static Particle empty();
  const static Particle sand();
  const static Particle water();
};

#endif  // PARTICLE_HPP_