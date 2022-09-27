#include "particle.h" 


Particle::Particle(Particles type, sf::Color color, ParticleUpdater updater){
	this->type = type;
	this->color = color;
	this->updater = updater;
}

// EMPTY PARTICLE
uint32_t updateEmpty(uint32_t position, std::unique_ptr<std::vector<Particle>> particles) {
	return position;
}

Particle Particle::empty(){
	return Particle(
		Particles::Empty,
		sf::Color::Black,
		updateEmpty
	);
}


// SAND PARTICLE
uint32_t updateSand(uint32_t position, std::unique_ptr<std::vector<Particle>> particles) {
	return position;
}

Particle Particle::sand(){
	return Particle(
		Particles::Sand,
		sf::Color::Yellow,
		updateSand
	);
}

// WATER PARTICLE
uint32_t updateWater(uint32_t position, std::unique_ptr<std::vector<Particle>> particles) {
	return position;
}

Particle Particle::water(){
	return Particle(
		Particles::Water,
		sf::Color::Blue,
		updateWater
	);
}

