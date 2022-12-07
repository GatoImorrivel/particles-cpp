#ifndef PARTICLE_HPP_
#define PARTICLE_HPP_

#include <SFML/Graphics/Color.hpp>
#include <cstdint>
#include <array>
#include <vector>
#include "direction.hpp"

enum ParticleType {
  Empty,
  Sand,
  Water
};

struct Particle {
  ParticleType type;
  sf::Color color;
  uint_fast32_t flow_rate;
  std::array<Direction, possible_directions> move_rules;
  std::vector<ParticleType> swappable_particles;
};

const static Particle particle_empty_ = {
  ParticleType::Empty,
  sf::Color(0,0,0,255),
  0,
  {},
};

const static Particle particle_sand_ = {
  ParticleType::Sand,
  sf::Color(100,100,0,255),
  1,
  {
    down_dir_,
    down_left_dir_,
    down_right_dir_
  },
  {
    ParticleType::Empty
  }
};

const static Particle particle_water_ = {
  ParticleType::Water,
  sf::Color(0,0,230,100),
  1,
  {
    down_dir_,
    down_left_dir_,
    down_right_dir_,
    left_dir_,
    right_dir_
  },
  {
    ParticleType::Empty
  }
};

#endif  // PARTICLE_HPP_
