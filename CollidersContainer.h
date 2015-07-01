#pragma once
#include <vector>
#include <cmath>
#include <utility>
#include <algorithm>
#include "Particle.h"
#include <SFML/Graphics.hpp>
#include <iterator>

#define PI 3.14159265

class CollidersContainer
{
public:
	CollidersContainer();
	~CollidersContainer();

	void CreateParticle(Particle& NewParticle);
	void DeleteParticle(const unsigned int& ParticleNumber);
	unsigned int ParticlesQuantity();

	void SetParticle(const Particle& NewParticle, const unsigned int& ParticleNumber);
	Particle GetParticle(const unsigned int& ParticleNumber);

	void SetParticleMass(const double& NewMass, const unsigned int& ParticleNumber);
	double GetParticleMass(const unsigned int& ParticleNumber);

	void SetParticleRadius(const double& NewRadius, const unsigned int& ParticleNumber);
	double GetParticleRadius(const unsigned int& ParticleNumber);

	void SetParticlePosition(const double& NewPositionX, const double& NewPositionY, const unsigned int& ParticleNumber);
	double GetParticlePositionX(const unsigned int& ParticleNumber);
	double GetParticlePositionY(const unsigned int& ParticleNumber);

	void SetParticleVelocity(const double& NewVelocityX, const double& NewVelocityY, const unsigned int& ParticleNumber);
	double GetParticleVelocity(const unsigned int& ParticleNumber);
	double GetParticleVelocityX(const unsigned int& ParticleNumber);
	double GetParticleVelocityY(const unsigned int& ParticleNumber);

	void SetParticleActingForce(const double& NewActingForceX, const double& NewActingForceY, const unsigned int& ParticleNumber);
	double GetParticleActingForce(const unsigned int& ParticleNumber);
	double GetParticleActingForceX(const unsigned int& ParticleNumber);
	double GetParticleActingForceY(const unsigned int& ParticleNumber);

	void SetCollisionPrecision(const double& NewCollisionPrecision);
	double GetCollisionPrecision();

	void SetSearchPrecision(const double& NewSearchingPrecision);
	double GetSearchPrecision();

	void MoveParticles(const double& DeltaTime);
	void SimulateCollisions();
	void CalculateCollisions(const unsigned int& ParticleNumberA, const unsigned int& ParticleNumberB);
	void DeflectParticlesOutOfBorder();
	void SortParticlesByX();

	std::vector <std::pair<double, unsigned int> >::iterator LowerBound(std::vector <std::pair<double, unsigned int> >::iterator First,
		std::vector <std::pair<double, unsigned int> >::iterator Last, const double& Value);
	std::vector <std::pair<double, unsigned int> >::iterator UpperBound(std::vector <std::pair<double, unsigned int> >::iterator First,
		std::vector <std::pair<double, unsigned int> >::iterator Last, const double& Value);

private:
	std::vector <Particle> ParticlesContainer;
	std::vector <std::pair<double, unsigned int> > ParticlesByX;

	double CollisionPrecision;
	double SearchPrecision;

	unsigned int WindowWidth;
	unsigned int WindowHeight;
};

