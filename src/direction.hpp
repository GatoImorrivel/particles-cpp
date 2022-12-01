#ifndef __DIRECTION_HPP__
#define __DIRECTION_HPP__

#include <cstdint>

struct Direction {
  int_fast8_t xOffset;
  int_fast8_t yOffset;
};

const static Direction down_dir_ = {
  0, -1
};

const static Direction down_left_dir_ = {
  -1, -1
};

const static Direction down_right_dir_ = {
  1, -1
};

const static Direction up_dir_ = {
  0, 1
};

const static Direction up_left_dir_ = {
  -1, 1
};

const static Direction up_right_dir_ = {
  1, 1
};

const static Direction left_dir_ = {
  -1, 0
};

const static Direction right_dir_ = {
  1, 0
};

#endif //__DIRECTION_HPP__
