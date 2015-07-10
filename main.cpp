//Air Particles Simulation || Arkadiusz Placha || 21.06.2015
#include <SFML/Graphics.hpp>
#include "CollidersContainer.h"
#include <iostream>
#include <cstdlib>

int main()
{
	srand(time(NULL));
	sf::RenderWindow window(sf::VideoMode(800, 600), "Collisions");
	CollidersContainer Container;

	Particle A;
	A.SetMass(10);
	A.SetRadius(5);
	A.SetPosition(10, 10);
	A.SetActingForce(0, 0);

	sf::Clock clock;
	clock.restart();

	//Creating Particles
	//N2 - 156 | O2 - 42 | Ar - 2 | All - 200

	//Nitrogen Particles
	//Mass - 4.652 × 10^-26 kg
	//Radius - 112 * 10^-12 m
	A.SetMass(4.652 * pow(10, -26));
	A.SetRadius(5.6);

	for (int i = 0; i < 156; i++)
	{
		//Setting random values to Velocity and Position
		double RandomVelocityX = rand() % 1000 + 1000;
		double RandomVelocityY = rand() % 1000 + 1000;
		if (rand() % 2 == 0){ RandomVelocityX *= -1; }
		if (rand() % 2 == 0){ RandomVelocityY *= -1; }
		A.SetVelocity(RandomVelocityX, RandomVelocityY);
		A.SetPosition((rand()) % 800 + 1, (rand()) % 600 + 1);
		//Creating Particle from template A
		Container.CreateParticle(A);
	}

	//Oxygen Particles
	//Mass - 5.314 × 10^-26 kg
	//Radius - 96 * 10^-12 m
	A.SetMass(5.314 * pow(10, -26));
	A.SetRadius(4.8);

	for (int i = 0; i < 42; i++)
	{
		//Setting random values to Velocity and Position
		double RandomVelocityX = rand() % 1000 + 1000;
		double RandomVelocityY = rand() % 1000 + 1000;
		if (rand() % 2 == 0){ RandomVelocityX *= -1; }
		if (rand() % 2 == 0){ RandomVelocityY *= -1; }
		A.SetVelocity(RandomVelocityX, RandomVelocityY);
		A.SetPosition((rand()) % 800 + 1, (rand()) % 600 + 1);
		//Creating Particle from template A
		Container.CreateParticle(A);
	}

	//Argon Particles
	//Mass - 6.642 × 10^-26
	//Radius - 71 * 10^-12 m
	A.SetMass(6.642 * pow(10, -26));
	A.SetRadius(3.55);

	for (int i = 0; i < 2; i++)
	{
		//Setting random values to Velocity and Position
		double RandomVelocityX = rand() % 1000 + 1000;
		double RandomVelocityY = rand() % 1000 + 1000;
		if (rand() % 2 == 0){ RandomVelocityX *= -1; }
		if (rand() % 2 == 0){ RandomVelocityY *= -1; }
		A.SetVelocity(RandomVelocityX, RandomVelocityY);
		A.SetPosition((rand()) % 800 + 1, (rand()) % 600 + 1);
		//Creating Particle from template A
		Container.CreateParticle(A);
	}

	while (window.isOpen())
	{
		sf::Time T = clock.getElapsedTime();
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();

		Container.MoveParticles(0.0015);
		Container.SimulateCollisions();
		Container.DeflectParticlesOutOfBorder();

		for (unsigned int i = 0; i < Container.ParticlesQuantity(); i++)
		{
			sf::CircleShape shape(Container.GetParticleRadius(i));
			shape.setPosition(Container.GetParticlePositionX(i), Container.GetParticlePositionY(i));
			switch ((int)Container.GetParticleRadius(i))
			{
			case 5:
				shape.setFillColor(sf::Color::Blue);
				break;
			case 4:
				shape.setFillColor(sf::Color::White);
				break;
			default:
				shape.setFillColor(sf::Color::Magenta);
				break;
			}
			window.draw(shape);
		}
		while (T.asSeconds() < 0.001){ T = clock.getElapsedTime(); }
		window.display();
		clock.restart();
	}
	return 0;
}
