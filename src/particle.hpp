#ifndef PARTICLE_HPP_
#define PARTICLE_HPP_

#include <SFML/Graphics/Color.hpp>
#include <cstdint>
#include "direction.hpp"

enum Particles {
  Empty,
  Sand,
  Water
};

const static uint_fast32_t possible_directions = 8;

struct Particle {
  Particles type;
  sf::Color color;
  Direction move_rules[possible_directions];
  uint_fast32_t flow_rate;
};

static const Particle particle_empty_ = {
  Particles::Empty,
  sf::Color(0,0,0,255),
  {},
  0
};

static const Particle particle_sand_ = {
  Particles::Sand,
  sf::Color(100,100,0,255),
  {
    down_dir_,
    down_left_dir_,
    down_right_dir_
  },
  1
};

static const Particle particle_water_ = {
  Particles::Water,
  sf::Color(0,0,230,100),
  {
    down_dir_,
    down_left_dir_,
    down_right_dir_,
    left_dir_,
    right_dir_
  },
  1
};

#endif  // PARTICLE_HPP_
