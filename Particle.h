#pragma once
#include "pVector.h"
#include <cmath>
#include <set>

class Particle
{
public:
	Particle();
	~Particle();

	void SetMass(const double& NewParticleMass);
	double GetMass();

	void SetRadius(const double& NewRadius);
	double GetRadius();

	void SetPosition(const double& VectorX, const double& VectorY);
	double GetPostitonX();
	double GetPostitonY();

	void SetVelocity(const double& VectorX, const double& VectorY);
	double GetVelocity();
	double GetVelocityX();
	double GetVelocityY();

	void SetActingForce(const double& VectorX, const double& VectorY);
	double GetActingForce();
	double GetActingForceX();
	double GetActingForceY();

	bool AddNewCollision(const unsigned int& CollidedParticleNumber);
	bool CheckCollision(const unsigned int& CollidedParticleNumber);
	void ClearCollisons();

	void Move(const double& DeltaTime);
	void ReverseMove(const double& DeltaTime);
	/*
	void Freeze();
	void UnFreeze();
	bool isFreezed();
	*/
private:

	//Particle Constants 
	double OneOverMass; // 1/Kg
	double Mass; // Kg 
	double Radius; // m *10^-12
	//bool Freezed;

	//Set containing Particles numbers in ParticlesContainer that had collided with this Particle
	std::set<unsigned int> ParticlesCollided;

	//Vectors for Particle Position, Velocity and Acting Force
	pVector Position;
	pVector Velocity;
	pVector ActingForce;
};
