#ifndef PARTICLE_HPP_
#define PARTICLE_HPP_

#include <SFML/Graphics/Color.hpp>
#include <cstdint>
#include "direction.hpp"

const static 
enum Particles {
  Empty,
  Sand,
  Water
};


struct Particle {
  Particles type;
  sf::Color color;
  uint_fast32_t flow_rate;
  Direction move_rules[possible_directions];
  Particles swappable_particles[];
};

const static Particle particle_empty_ = {
  Particles::Empty,
  sf::Color(0,0,0,255),
  0,
  {},
};

const static Particle particle_sand_ = {
  Particles::Sand,
  sf::Color(100,100,0,255),
  1,
  {
    down_dir_,
    down_left_dir_,
    down_right_dir_
  },
};

const static Particle particle_water_ = {
  Particles::Water,
  sf::Color(0,0,230,100),
  1,
  {
    down_dir_,
    down_left_dir_,
    down_right_dir_,
    left_dir_,
    right_dir_
  },
};

#endif  // PARTICLE_HPP_
