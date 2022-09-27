#include "particle.h" 


Particle::Particle(Particles type, sf::Color color, ParticleUpdater updater){
	this->type = type;
	this->color = color;
	this->updater = updater;
}

// EMPTY PARTICLE
const uint32_t updateEmpty(const uint32_t position, const std::vector<Particle> particles) {
	return position;
}

const Particle Particle::empty(){
	return Particle(
		Particles::Empty,
		sf::Color::Black,
		updateEmpty
	);
}


// SAND PARTICLE
const uint32_t updateSand(const uint32_t position, const std::vector<Particle> particles) {
	return position;
}

const Particle Particle::sand(){
	return Particle(
		Particles::Sand,
		sf::Color::Yellow,
		updateSand
	);
}

// WATER PARTICLE
const uint32_t updateWater(const uint32_t position, const std::vector<Particle> particles) {
	return position;
}

const Particle Particle::water(){
	return Particle(
		Particles::Water,
		sf::Color::Blue,
		updateWater
	);
}

