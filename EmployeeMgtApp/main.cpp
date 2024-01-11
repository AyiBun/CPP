#include "pch.h";
#include <iostream>
using namespace std;

using namespace winrt;
using namespace Windows::Foundation;

class IEmployee {
	virtual void AskForPromotion()=0;
};

class Employee : IEmployee {
private:
	int Age;
protected:
	string Name;
public:
	Employee(string name, string jobTitle, string company, string interest, int age)
	{
		Name = name;
		Age = age;
		JobTitle = jobTitle;
		Company = company;
		Interest = interest;
	}
	Employee()
	{
		Name = "";
		Age = 0;
		JobTitle = "";
		Company = "";
		Interest = "";
	}
	void setName(string name)
	{
		Name = name;
	}
	string getName()
	{
		return Name;
	}
	void SetAge(int age)
	{
		Age = age;
	}
	string JobTitle;
	string Company;
	string Interest;
	void IntroduceSelf()
	{
		cout << "Hello, my name is " << Name << endl;
		cout << "I am a " << JobTitle << " at " << Company << endl;
		cout << "I am interested in " << Interest << ". It's nice to meet you!" << endl;
	}
	void AskForPromotion()
	{
		if (Age >= 30)
		{
			cout << Name << " got promoted!" << endl;
		}
		else
		{
			cout << "Sorry " << Name << ", NO PROMOTION for you" << endl;
		}
	}
	virtual void Work() {
		cout << Name << " is performing tasks" << endl;
	}

};

class Developer : public Employee
{
public:
	Developer(string name, string jobTitle, string company, string interest, int age, string fav) :Employee(name, jobTitle, company, interest, age)
	{
		FavLanguage = fav;
	};
	string FavLanguage;
	void FixBug()
	{
		cout << Name << " is fixing a bug in " << FavLanguage << endl;
	}
	void Work()
	{
		cout << Name << " is reviewing a PR" << endl;
	}
};

int main()
{
    init_apartment();
	Developer dev = Developer("Sly", "Devops Engineer", "CCDC", "Microservices", 25, "C++");
	Employee* e = &dev;
	dev.FixBug();
	dev.AskForPromotion();
	dev.Work();
	e->Work();
	
}
