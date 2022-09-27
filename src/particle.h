#ifndef PARTICLE_HPP_
#define PARTICLE_HPP_

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

class Particle;

enum Particles {
    Empty,
    Sand,
    Water,
};

using ParticleUpdater = uint32_t (*)(uint32_t, std::unique_ptr<std::vector<Particle>>);

class Particle {
    private:
        Particles type;
        sf::Color color;
        ParticleUpdater updater;

    public:
        Particle(Particles type, sf::Color color, ParticleUpdater updater);
        Particle empty();
        Particle sand();
        Particle water();
};

#endif // PARTICLE_HPP_