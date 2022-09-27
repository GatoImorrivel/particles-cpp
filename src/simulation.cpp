#include "simulation.h"
#include <iostream>

Simulation::Simulation(const uint32_t width, const uint32_t height, const uint32_t particleDimensions) {
	auto simWidth = width / particleDimensions;
	auto simHeight = width / particleDimensions;

	this->width = simWidth;
	this->width = simHeight;
	this->particles = std::vector(simWidth * simHeight, Particle::empty());
	this->textureData = std::vector(simWidth * simHeight * 4, sf::Uint8(255)); // 4 colors channels

	sf::Texture texture;
	if (!texture.create(simWidth, simHeight))
		std::cout << "ERROR CREATING TEXTURE"
				  << "\n";

	this->texture = texture;

	sf::Sprite sprite;
	sprite.setTexture(this->texture);
	sprite.setScale(particleDimensions, particleDimensions);

	this->renderSprite = sprite;
}

void Simulation::update() {
	for (size_t y = this->height; y > 0; y--)
		for (size_t x = 0; x < this->width; x++) {
			size_t i = this->indexOf(x,y);
			uint32_t newPos = this->particles[i].updater(i, this->particles);
			this->swap(i, newPos);
		}
	this->texture.update(this->textureData.data());
}

const inline size_t Simulation::indexOf(const size_t x, const size_t y) {
	return y * this->width + x;
}

void Simulation::swap(const size_t p1idx, const size_t p2idx) {
	Particle t = this->particles[p1idx];
	this->particles[p1idx] = this->particles[p2idx];
	this->particles[p2idx] = t;
}

const sf::Sprite Simulation::getSprite() {
	return this->renderSprite;
}
