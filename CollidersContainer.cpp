#include "CollidersContainer.h"

CollidersContainer::CollidersContainer()
{
	WindowHeight = 600;
	WindowWidth = 800;
	CollisionPrecision = 0.001;
	SearchPrecision = 11.5;
}
CollidersContainer::~CollidersContainer()
{
}

void CollidersContainer::CreateParticle(Particle& NewParticle)
{
	ParticlesContainer.push_back(NewParticle);
	ParticlesByX.push_back(std::make_pair(NewParticle.GetPostitonX(), ParticlesContainer.size() - 1));
}
void CollidersContainer::DeleteParticle(const unsigned int& ParticleNumber)
{
	if (ParticleNumber < ParticlesContainer.size())
	{
		ParticlesContainer.erase(ParticlesContainer.begin() + ParticleNumber);
	}
}
unsigned int CollidersContainer::ParticlesQuantity()
{
	return ParticlesContainer.size();
}

void CollidersContainer::SetParticle(const Particle& NewParticle, const unsigned int& ParticleNumber)
{
	if (ParticleNumber < ParticlesContainer.size())
	{
		ParticlesContainer[ParticleNumber] = NewParticle;
	}
}
Particle CollidersContainer::GetParticle(const unsigned int& ParticleNumber)
{
	if (ParticleNumber < ParticlesContainer.size())
	{
		return ParticlesContainer[ParticleNumber];
	}

}

void CollidersContainer::SetParticleMass(const double& NewMass, const unsigned int& ParticleNumber)
{
	if (ParticleNumber < ParticlesContainer.size())
	{
		ParticlesContainer[ParticleNumber].SetMass(NewMass);
	}
}
double CollidersContainer::GetParticleMass(const unsigned int& ParticleNumber)
{
	if (ParticleNumber < ParticlesContainer.size())
	{
		return ParticlesContainer[ParticleNumber].GetMass();
	}
	else
	{
		return 0;
	}
}

void CollidersContainer::SetParticleRadius(const double& NewRadius, const unsigned int& ParticleNumber)
{
	if (ParticleNumber < ParticlesContainer.size())
	{
		ParticlesContainer[ParticleNumber].SetRadius(NewRadius);
	}
}
double CollidersContainer::GetParticleRadius(const unsigned int& ParticleNumber)
{
	if (ParticleNumber < ParticlesContainer.size())
	{
		return ParticlesContainer[ParticleNumber].GetRadius();
	}
	else
	{
		return 0;
	}
}

void CollidersContainer::SetParticlePosition(const double& NewPositionX, const double& NewPositionY, const unsigned int& ParticleNumber)
{
	if (ParticleNumber < ParticlesContainer.size())
	{
		ParticlesContainer[ParticleNumber].SetPosition(NewPositionX, NewPositionY);
	}
}
double CollidersContainer::GetParticlePositionX(const unsigned int& ParticleNumber)
{
	if (ParticleNumber < ParticlesContainer.size())
	{
		return ParticlesContainer[ParticleNumber].GetPostitonX();
	}
	else
	{
		return 0;
	}
}
double CollidersContainer::GetParticlePositionY(const unsigned int& ParticleNumber)
{
	if (ParticleNumber < ParticlesContainer.size())
	{
		return ParticlesContainer[ParticleNumber].GetPostitonY();
	}
	else
	{
		return 0;
	}
}

void CollidersContainer::SetParticleVelocity(const double& NewVelocityX, const double& NewVelocityY, const unsigned int& ParticleNumber)
{
	if (ParticleNumber < ParticlesContainer.size())
	{
		ParticlesContainer[ParticleNumber].SetVelocity(NewVelocityX, NewVelocityY);
	}
}
double CollidersContainer::GetParticleVelocity(const unsigned int& ParticleNumber)
{
	if (ParticleNumber < ParticlesContainer.size())
	{
		return ParticlesContainer[ParticleNumber].GetVelocity();
	}
	else
	{
		return 0;
	}
}
double CollidersContainer::GetParticleVelocityX(const unsigned int& ParticleNumber)
{
	if (ParticleNumber < ParticlesContainer.size())
	{
		return ParticlesContainer[ParticleNumber].GetVelocityX();
	}
	else
	{
		return 0;
	}
}
double CollidersContainer::GetParticleVelocityY(const unsigned int& ParticleNumber)
{
	if (ParticleNumber < ParticlesContainer.size())
	{
		return ParticlesContainer[ParticleNumber].GetVelocityY();
	}
	else
	{
		return 0;
	}
}

void CollidersContainer::SetParticleActingForce(const double& NewActingForceX, const double& NewActingForceY, const unsigned int& ParticleNumber)
{
	if (ParticleNumber < ParticlesContainer.size())
	{
		ParticlesContainer[ParticleNumber].SetActingForce(NewActingForceX, NewActingForceY);
	}
}
double CollidersContainer::GetParticleActingForce(const unsigned int& ParticleNumber)
{
	if (ParticleNumber < ParticlesContainer.size())
	{
		return ParticlesContainer[ParticleNumber].GetActingForce();
	}
	else
	{
		return 0;
	}
}
double CollidersContainer::GetParticleActingForceX(const unsigned int& ParticleNumber)
{
	if (ParticleNumber < ParticlesContainer.size())
	{
		return ParticlesContainer[ParticleNumber].GetActingForceX();
	}
	else
	{
		return 0;
	}
}
double CollidersContainer::GetParticleActingForceY(const unsigned int& ParticleNumber)
{
	if (ParticleNumber < ParticlesContainer.size())
	{
		return ParticlesContainer[ParticleNumber].GetActingForceY();
	}
}

void CollidersContainer::SetCollisionPrecision(const double& NewPrecision)
{
	CollisionPrecision = NewPrecision;
}
double CollidersContainer::GetCollisionPrecision()
{
	return CollisionPrecision;
}

void CollidersContainer::SetSearchPrecision(const double& NewPrecision)
{
	SearchPrecision = NewPrecision;
}
double CollidersContainer::GetSearchPrecision()
{
	return SearchPrecision;
}

void CollidersContainer::MoveParticles(const double& DeltaTime)
{
	for (unsigned int i = 0; i < ParticlesByX.size(); i++)
	{
		ParticlesContainer[ParticlesByX[i].second].Move(DeltaTime);
		ParticlesByX[i].first = ParticlesContainer[ParticlesByX[i].second].GetPostitonX();
	}
}
void CollidersContainer::SimulateCollisions()
{
	//Sorting vector containing Position X values
	SortParticlesByX();

	//Clearing Particles sets
	for (unsigned int i = 0; i < ParticlesContainer.size(); i++)
	{
		ParticlesContainer[i].ClearCollisons();
	}

	//Searching for potential collisions
	for (unsigned int i = 0; i < ParticlesContainer.size(); i++)
	{
		std::vector <std::pair<double, unsigned int> >::iterator IteratorBegin = LowerBound(ParticlesByX.begin(), ParticlesByX.end(), (ParticlesContainer[i].GetPostitonX() - SearchPrecision));
		std::vector <std::pair<double, unsigned int> >::iterator IteratorEnd = UpperBound(ParticlesByX.begin(), ParticlesByX.end(), (ParticlesContainer[i].GetPostitonX() + SearchPrecision));
		for (auto j = IteratorBegin; j != IteratorEnd; j++)
		{
			//i - Particle Position in Vector ParticlesContainer, CheckedPair.second - Potential Collided Particle Position in Vector ParticlesContainer
			auto CheckedPair = *j;
			if (CheckedPair.second != i)
			{
				if (ParticlesContainer[i].AddNewCollision(CheckedPair.second))
				{
					ParticlesContainer[CheckedPair.second].AddNewCollision(i);
					CalculateCollisions(i, CheckedPair.second);
				}
			}
		}
	}
}

void CollidersContainer::CalculateCollisions(const unsigned int& ParticleNumberA, const unsigned int& ParticleNumberB)
{
	if (ParticleNumberA == ParticleNumberB)
	{
		return;
	}
	else
	{
		Particle A = ParticlesContainer[ParticleNumberA];
		Particle B = ParticlesContainer[ParticleNumberB];
		if (A.GetMass() != 0 || B.GetMass() != 0)
		{
			//Calculating Distance between particle i and j
			double DistanceBetweenParticles = sqrt((A.GetPostitonX() - B.GetPostitonX()) * (A.GetPostitonX() - B.GetPostitonX())
				+ (A.GetPostitonY() - B.GetPostitonY()) * (A.GetPostitonY() - B.GetPostitonY()));

			if (DistanceBetweenParticles - (A.GetRadius() + B.GetRadius()) > CollisionPrecision){ return; }
			else if (DistanceBetweenParticles - (A.GetRadius() + B.GetRadius()) >= 0)
			{
				double ThetaOne = 0; //Arc Between X Axis and Vector VA
				double ThetaTwo = 0; //Arc Between X Axis and Vector VB
				double Phi = 0; //Arc Between X Axis and DistanceBetweenParticles Vector
				if (A.GetVelocityY() != 0 || A.GetVelocityX() != 0)
				{
					ThetaOne = atan2(A.GetVelocityY(), A.GetVelocityX());
				}
				if (B.GetVelocityY() != 0 || B.GetVelocityX() != 0)
				{
					ThetaTwo = atan2(B.GetVelocityY(), B.GetVelocityX());
				}
				if ((A.GetVelocityY() - B.GetVelocityY()) != 0 || (A.GetVelocityX() - B.GetVelocityX()) != 0)
				{
					Phi = atan2((A.GetVelocityY() - B.GetVelocityY()), (A.GetVelocityX() - B.GetVelocityX()));
				}

				//Velocities after Collision
				double A_NewVelocityX;
				double A_NewVelocityY;
				double B_NewVelocityX;
				double B_NewVelocityY;

				A_NewVelocityX = (A.GetVelocity() * cos(ThetaOne - Phi) * (A.GetMass() - B.GetMass()) + 2 * B.GetMass() * B.GetVelocity() * cos(ThetaTwo - Phi))
					/ (A.GetMass() + B.GetMass()) * cos(Phi) + A.GetVelocity() * sin(ThetaOne - Phi) * cos(Phi + PI * 0.5);
				A_NewVelocityY = (A.GetVelocity() * cos(ThetaOne - Phi) * (A.GetMass() - B.GetMass()) + 2 * B.GetMass() * B.GetVelocity() * cos(ThetaTwo - Phi))
					/ (A.GetMass() + B.GetMass()) * sin(Phi) + A.GetVelocity() * sin(ThetaOne - Phi) * sin(Phi + PI * 0.5);

				B_NewVelocityX = (B.GetVelocity() * cos(ThetaTwo - Phi) * (B.GetMass() - A.GetMass()) + 2 * A.GetMass() * A.GetVelocity() * cos(ThetaOne - Phi))
					/ (B.GetMass() + A.GetMass()) * cos(Phi) + B.GetVelocity() * sin(ThetaTwo - Phi) * cos(Phi + PI * 0.5);
				B_NewVelocityY = (B.GetVelocity() * cos(ThetaTwo - Phi) * (B.GetMass() - A.GetMass()) + 2 * A.GetMass() * A.GetVelocity() * cos(ThetaOne - Phi))
					/ (B.GetMass() + A.GetMass()) * sin(Phi) + B.GetVelocity() * sin(ThetaTwo - Phi) * sin(Phi + PI * 0.5);

				ParticlesContainer[ParticleNumberA].SetVelocity(A_NewVelocityX, A_NewVelocityY);
				ParticlesContainer[ParticleNumberB].SetVelocity(B_NewVelocityX, B_NewVelocityY);
			}
			else
			{
				double ReversedTime = 0;
				while (DistanceBetweenParticles - (A.GetRadius() + B.GetRadius()) < CollisionPrecision)
				{
					A.ReverseMove(-0.0002);
					B.ReverseMove(-0.0002);
					ReversedTime += 0.0001;
					DistanceBetweenParticles = sqrt((A.GetPostitonX() - B.GetPostitonX()) * (A.GetPostitonX() - B.GetPostitonX())
						+ (A.GetPostitonY() - B.GetPostitonY()) * (A.GetPostitonY() - B.GetPostitonY()));
				}

				double ThetaOne = 0; //Arc Between X Axis and Vector VA
				double ThetaTwo = 0; //Arc Between X Axis and Vector VB
				double Phi = 0; //Arc Between X Axis and DistanceBetweenParticles Vector
				if (A.GetVelocityY() != 0 || A.GetVelocityX() != 0)
				{
					ThetaOne = atan2(A.GetVelocityY(), A.GetVelocityX());
				}
				if (B.GetVelocityY() != 0 || B.GetVelocityX() != 0)
				{
					ThetaTwo = atan2(B.GetVelocityY(), B.GetVelocityX());
				}
				if ((A.GetVelocityY() - B.GetVelocityY()) != 0 || (A.GetVelocityX() - B.GetVelocityX()) != 0)
				{
					Phi = atan2((A.GetVelocityY() - B.GetVelocityY()), (A.GetVelocityX() - B.GetVelocityX()));
				}

				//Velocities after Collision
				double A_NewVelocityX;
				double A_NewVelocityY;
				double B_NewVelocityX;
				double B_NewVelocityY;

				A_NewVelocityX = (A.GetVelocity() * cos(ThetaOne - Phi) * (A.GetMass() - B.GetMass()) + 2 * B.GetMass() * B.GetVelocity() * cos(ThetaTwo - Phi))
					/ (A.GetMass() + B.GetMass()) * cos(Phi) + A.GetVelocity() * sin(ThetaOne - Phi) * cos(Phi + PI * 0.5);
				A_NewVelocityY = (A.GetVelocity() * cos(ThetaOne - Phi) * (A.GetMass() - B.GetMass()) + 2 * B.GetMass() * B.GetVelocity() * cos(ThetaTwo - Phi))
					/ (A.GetMass() + B.GetMass()) * sin(Phi) + A.GetVelocity() * sin(ThetaOne - Phi) * sin(Phi + PI * 0.5);

				B_NewVelocityX = (B.GetVelocity() * cos(ThetaTwo - Phi) * (B.GetMass() - A.GetMass()) + 2 * A.GetMass() * A.GetVelocity() * cos(ThetaOne - Phi))
					/ (B.GetMass() + A.GetMass()) * cos(Phi) + B.GetVelocity() * sin(ThetaTwo - Phi) * cos(Phi + PI * 0.5);
				B_NewVelocityY = (B.GetVelocity() * cos(ThetaTwo - Phi) * (B.GetMass() - A.GetMass()) + 2 * A.GetMass() * A.GetVelocity() * cos(ThetaOne - Phi))
					/ (B.GetMass() + A.GetMass()) * sin(Phi) + B.GetVelocity() * sin(ThetaTwo - Phi) * sin(Phi + PI * 0.5);

				ParticlesContainer[ParticleNumberA].SetVelocity(A_NewVelocityX, A_NewVelocityY);
				ParticlesContainer[ParticleNumberB].SetVelocity(B_NewVelocityX, B_NewVelocityY);

				DistanceBetweenParticles = sqrt((A.GetPostitonX() - B.GetPostitonX()) * (A.GetPostitonX() - B.GetPostitonX())
					+ (A.GetPostitonY() - B.GetPostitonY()) * (A.GetPostitonY() - B.GetPostitonY()));

				//ParticlesContainer[ParticleNumberA].Move(ReversedTime);
				//ParticlesContainer[ParticleNumberB].Move(ReversedTime);
			}
		}
	}
}

void CollidersContainer::DeflectParticlesOutOfBorder()
{
	for (unsigned int i = 0; i < ParticlesContainer.size(); i++)
	{
		Particle A = ParticlesContainer[i];
		if (A.GetPostitonX() < 0)
		{
			double A_newVelocityX = -(A.GetVelocityX());
			double A_newVelocityY = A.GetVelocityY();
			ParticlesContainer[i].SetVelocity(A_newVelocityX, A_newVelocityY);
		}
		else if (A.GetPostitonX() > WindowWidth)
		{
			double A_newVelocityX = -(A.GetVelocityX());
			double A_newVelocityY = A.GetVelocityY();
			ParticlesContainer[i].SetVelocity(A_newVelocityX, A_newVelocityY);
		}

		if (A.GetPostitonY() < 0)
		{
			double A_newVelocityX = A.GetVelocityX();
			double A_newVelocityY = -(A.GetVelocityY());
			ParticlesContainer[i].SetVelocity(A_newVelocityX, A_newVelocityY);
		}
		else if (A.GetPostitonY() > WindowHeight)
		{
			double A_newVelocityX = A.GetVelocityX();
			double A_newVelocityY = -(A.GetVelocityY());
			ParticlesContainer[i].SetVelocity(A_newVelocityX, A_newVelocityY);
		}
	}

}

void CollidersContainer::SortParticlesByX()
{
	std::sort(ParticlesByX.begin(), ParticlesByX.end(), [](const std::pair<double, unsigned int> &i, const std::pair<double, unsigned int> &j) -> bool { return i.first < j.first; });
}

std::vector <std::pair<double, unsigned int> >::iterator CollidersContainer::LowerBound(std::vector <std::pair<double, unsigned int> >::iterator First,
	std::vector <std::pair<double, unsigned int> >::iterator Last, const double& Value)
{
	std::vector <std::pair<double, unsigned int> >::iterator  It;
	std::iterator_traits<std::vector <std::pair<double, unsigned int> >::iterator>::difference_type count, step;
	count = std::distance(First, Last);
	while (count > 0)
	{
		It = First; 
		step = count / 2;
		std::advance(It, step);
		auto Ret = *It;
		if (Ret.first < Value)
		{                
			First = ++It;
			count -= step + 1;
		}
		else count = step;
	}
	return First;
}

std::vector <std::pair<double, unsigned int> >::iterator CollidersContainer::UpperBound(std::vector <std::pair<double, unsigned int> >::iterator First,
	std::vector <std::pair<double, unsigned int> >::iterator Last, const double& Value)
{
	std::vector <std::pair<double, unsigned int> >::iterator  It;
	std::iterator_traits<std::vector <std::pair<double, unsigned int> >::iterator>::difference_type count, step;
	count = std::distance(First, Last);
	while (count > 0)
	{
		It = First;
		step = count / 2;
		std::advance(It, step);
		auto Ret = *It;
		if (!(Value < Ret.first))
		{
			First = ++It;
			count -= step + 1;
		}
		else count = step;
	}
	return First;
}