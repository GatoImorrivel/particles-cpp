#include "simulation.h"
#include <iostream>

Simulation::Simulation(const uint32_t width,
                       const uint32_t height,
                       const uint32_t particleDimensions) {
  auto simWidth = width / particleDimensions;
  auto simHeight = height / particleDimensions;

  this->width = simWidth;
  this->height = simHeight;
  this->particles =
      std::vector<Particle>(simWidth * simHeight, Particle::water());
  this->textureData =
      std::vector<sf::Uint8>(simWidth * simHeight * 4,
                             sf::Uint8(255));  // 4 colors channels

  sf::Texture texture;
  if (!texture.create(simWidth, simHeight)) {
    std::cout << "ERROR CREATING TEXTURE"
              << "\n";
  }

  this->texture = texture;

  sf::Sprite sprite;
  sprite.setTexture(this->texture, false);
  sprite.setScale(particleDimensions, particleDimensions);

  this->renderSprite = sprite;
}

void Simulation::update() {
  for (size_t y = this->height - 1; y > 0; y--) {
    for (size_t x = 0; x < this->width; x++) {
      size_t i = this->indexOf(x, y);
      uint32_t newPos = this->particles[i].updater(i, &this->particles);
      this->swapParticle(i, newPos);
    }
  }
  this->texture.update(this->textureData.data());
}

const void Simulation::draw(sf::RenderWindow* window) {
  window->draw(this->renderSprite);
}

const inline size_t Simulation::indexOf(const size_t x, const size_t y) {
  return y * this->width + x;
}

void Simulation::swapParticle(const size_t p1idx, const size_t p2idx) {
  Particle* p1 = &this->particles[p1idx];
  Particle* p2 = &this->particles[p2idx];

  Particle t = *p1;
  *p1 = *p2;
  *p2 = t;

  this->writeToTextureData(p1idx, p1->getColor());
  this->writeToTextureData(p2idx, p2->getColor());
}

void Simulation::writeToTextureData(const size_t pidx, const sf::Color c) {
  this->textureData[pidx * 4] = c.r;
  this->textureData[pidx * 4 + 1] = c.g;
  this->textureData[pidx * 4 + 2] = c.b;
  this->textureData[pidx * 4 + 3] = c.a;
}

sf::Sprite Simulation::getSprite() {
  return this->renderSprite;
}
