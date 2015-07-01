#include "Particle.h"

Particle::Particle()
{
	Particle::OneOverMass - 0;
	Particle::Radius = 0;
	//Particle::Freezed = false;

	Particle::Position.x = 0;
	Particle::Position.y = 0;

	Particle::Velocity.x = 0;
	Particle::Velocity.y = 0;

	Particle::ActingForce.x = 0;
	Particle::ActingForce.y = 0;
}
Particle::~Particle()
{
}

void Particle::SetMass(const double& NewParticleMass)
{
	Mass = NewParticleMass;
	if (NewParticleMass != 0)
	{
		OneOverMass = (1 / NewParticleMass);
	}
}
double Particle::GetMass()
{
	return Mass;
}

void Particle::SetRadius(const double& NewRadius)
{
	Particle::Radius = NewRadius;
}
double Particle::GetRadius()
{
	return Particle::Radius;
}

void Particle::SetPosition(const double&  VectorX, const double&  VectorY)
{
	Particle::Position.x = VectorX;
	Particle::Position.y = VectorY;
}
double Particle::GetPostitonX()
{
	return Particle::Position.x;
}
double Particle::GetPostitonY()
{
	return Particle::Position.y;
}

void Particle::SetVelocity(const double&  VectorX, const double&  VectorY)
{
	Particle::Velocity.x = VectorX;
	Particle::Velocity.y = VectorY;
}
double Particle::GetVelocity()
{
	return sqrt(Particle::Velocity.x * Particle::Velocity.x + Particle::Velocity.y * Particle::Velocity.y);
}
double Particle::GetVelocityX()
{
	return Particle::Velocity.x;
}
double Particle::GetVelocityY()
{
	return Particle::Velocity.y;
}

void Particle::SetActingForce(const double& VectorX, const double& VectorY)
{
	Particle::ActingForce.x = VectorX;
	Particle::ActingForce.y = VectorY;
}
double Particle::GetActingForce()
{
	return sqrt(Particle::ActingForce.x * Particle::ActingForce.x + Particle::ActingForce.y * Particle::ActingForce.y);
}
double Particle::GetActingForceX()
{
	return Particle::ActingForce.x;
}
double Particle::GetActingForceY()
{
	return Particle::ActingForce.y;
}

bool Particle::AddNewCollision(const unsigned int& CollidedParticleNumber)
{
	//True - Collison was added, False - Collsion was already registed
	auto ret = ParticlesCollided.insert(CollidedParticleNumber);
	return ret.second;
}
bool Particle::CheckCollision(const unsigned int& CollidedParticleNumber)
{
	if (ParticlesCollided.find(CollidedParticleNumber) == ParticlesCollided.end())
	{
		return false; //The value was not found
	}
	else
	{
		return true; //The value was found
	}
}
void Particle::ClearCollisons()
{
	ParticlesCollided.clear();
}

void Particle::Move(const double& DeltaTime)
{
//	if (!Particle::Freezed)
//	{
		//Calculating new velocity vector
		Particle::Velocity.x = Particle::Velocity.x + (Particle::ActingForce.x * DeltaTime * OneOverMass);
		Particle::Velocity.y = Particle::Velocity.y + (Particle::ActingForce.y * DeltaTime * OneOverMass);

		//Calculating new position
		Particle::Position.x = Particle::Position.x + (Particle::Velocity.x * DeltaTime);
		Particle::Position.y = Particle::Position.y + (Particle::Velocity.y * DeltaTime);
//	}
}
void Particle::ReverseMove(const double& DeltaTime)
{
//	if (!Particle::Freezed)
//	{
		//Calculating new position
		Particle::Position.x = Particle::Position.x + (Particle::Velocity.x * DeltaTime);
		Particle::Position.y = Particle::Position.y + (Particle::Velocity.y * DeltaTime);

		//Calculating new velocity vector
		Particle::Velocity.x = Particle::Velocity.x + (Particle::ActingForce.x * DeltaTime * OneOverMass);
		Particle::Velocity.y = Particle::Velocity.y + (Particle::ActingForce.y * DeltaTime * OneOverMass);
//	}
}
/*
void Particle::Freeze()
{
	Particle::Freezed = true;
}

void Particle::UnFreeze()
{
	Particle::Freezed = false;
}

bool Particle::isFreezed()
{
	return Particle::Freezed;
}
*/