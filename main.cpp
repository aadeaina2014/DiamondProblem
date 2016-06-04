/********************************************************************
   Multiple Inheritance Problem (Diamond Problem) C++
   Illustration with Animal and Prey Class
   (c) June 2016 Ayokunle Ade-Aina
*********************************************************************/
#include <iostream>
#include <string>

using namespace std;

class Prey
{
public:
	Prey():lifeLine(100){}

	void setLifeLine(int l)
	{
		lifeLine = l;
	}

	int getLifeLine()
	{
		return lifeLine;
	}
	void reduceLifeLine(int measure)
	{
		lifeLine -= measure;
	}
	~Prey() {}
private:
	int lifeLine;
};

class Animal
{
public:
	virtual void attack(Prey preyObject) = 0;
	

};



class Reptile :  public Animal
{

public:
	Reptile():repStrength(15){}
	void attack(Prey preyObject)
	{
		preyObject.reduceLifeLine(repStrength);
	}
	void showRepStrength()
	{
		cout << "Reptile strength:-" << repStrength << "%" << endl;
	}
	int getRepStrength() { return repStrength; }
	~Reptile(){}
private:
	int repStrength;
};


class Amphibian :  public Animal  // resolving diamond problem
{
public:
	Amphibian() : ampStrength(35){}

	void attack(Prey preyObject)
	{
		preyObject.reduceLifeLine(ampStrength);
	}
	void showAmpStrength()
	{
	cout << "Amphibian strength:-" << ampStrength << "%" << endl;
	}


	int getAmpStrength() { return ampStrength; }
	~Amphibian()
	{}
private:
	int ampStrength;
};

class Enemy : virtual public Reptile, virtual public Amphibian
{
public:
	Enemy() : strength(getRepStrength()+ getAmpStrength()) {}

	void attack(Prey* preyObject)
	{
		(*preyObject).reduceLifeLine(strength);
	}
	void showEnemyStrength()
	{
		cout << "Enemy strength:-" << strength << "%" << endl;
	}
	
	~Enemy(){}
private:
	int strength;
};

int main()
{
	Enemy firstEnemy;
	Prey butterfly;
	
	firstEnemy.showAmpStrength();
	firstEnemy.showRepStrength();
	firstEnemy.showEnemyStrength();
	cout << "butterfly lineline  before attack: " << butterfly.getLifeLine() << "%" << endl;
	firstEnemy.attack(&butterfly);
	cout << "butterfly lineline  After attack: " << butterfly.getLifeLine() << "%" << endl;
	
	system("pause");
	return EXIT_SUCCESS;
}