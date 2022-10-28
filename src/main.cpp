#include <SFML/Graphics.hpp>
#include <cstdint>
#include "simulation.h"

int main() {
  const uint32_t width = 848;
  const uint32_t height = 484;
  const uint32_t particleDimension = 2;
  const uint32_t bitsPerPixel = 32;

  sf::RenderWindow window(sf::VideoMode(width, height, bitsPerPixel), "Teste");
  Simulation simulation = Simulation(width, height, particleDimension);

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }

    window.clear(sf::Color::Red);
    simulation.update();
    simulation.draw(&window);
    window.display();
  }

  return 0;
}
