#ifndef PARTICLE_HPP_
#define PARTICLE_HPP_

#include <SFML/Graphics/Color.hpp>

enum Particles {
  Empty,
  Sand,
  Water
};

struct Particle {
  Particles type;
  sf::Color color;
};

static const Particle particle_empty_ = {
  Particles::Empty,
  sf::Color(0,0,0,255)
};

static const Particle particle_sand_ = {
  Particles::Sand,
  sf::Color(100,100,0,255)
};

static const Particle particle_water_ = {
  Particles::Water,
  sf::Color(0,0,230,100)
};

#endif  // PARTICLE_HPP_
