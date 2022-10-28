#include "simulation.hpp"
#include <iostream>

Simulation::Simulation(const uint32_t width,
                       const uint32_t height,
                       const uint32_t particleDimensions) {
  auto simWidth = width / particleDimensions;
  auto simHeight = height / particleDimensions;

  this->width = simWidth;
  this->height = simHeight;
  this->particles =
      std::vector<Particle>(simWidth * simHeight, Particle::sand());
  this->textureData =
      std::vector<sf::Uint8>(simWidth * simHeight * 4,
                             sf::Uint8(0));  // 4 colors channels

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
  for (int yPos = this->height; yPos-- > 0;) {
    for (size_t xPos = 0; xPos < this->width; xPos++) {
      size_t index = this->indexOf(xPos, yPos);
      uint32_t newPos = this->particles[index].updater(index, &this->particles);
      this->swapParticle(index, newPos);
    }
  }
  this->texture.update(this->textureData.data());
}

void Simulation::draw(sf::RenderWindow* window) const {
  window->draw(this->renderSprite);
}

inline size_t Simulation::indexOf(const size_t xPos, const size_t yPos) const {
  return yPos * this->width + xPos;
}

void Simulation::swapParticle(const size_t p1idx, const size_t p2idx) {
  Particle* particle1 = &this->particles[p1idx];
  Particle* particle2 = &this->particles[p2idx];

  Particle temp = *particle1;
  *particle1 = *particle2;
  *particle2 = temp;

  this->writeToTextureData(p1idx, particle1->getColor());
  this->writeToTextureData(p2idx, particle2->getColor());
}

void Simulation::writeToTextureData(const size_t pidx, const sf::Color color) {
  this->textureData[pidx * 4] = color.r;
  this->textureData[pidx * 4 + 1] = color.g;
  this->textureData[pidx * 4 + 2] = color.b;
  this->textureData[pidx * 4 + 3] = color.a;
}

sf::Sprite Simulation::getSprite() const {
  return this->renderSprite;
}
