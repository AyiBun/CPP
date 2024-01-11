#include "pch.h";
using namespace std;

class Employee {
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
	string AskForPromotion()
	{
		if (Age >= 30)
		{
			return  Name +  " got promoted!";
		}
		else
		{
			return "Sorry " + Name + ", NO PROMOTION for you";
		}
	}
	virtual void Work() {
		cout << Name << " is performing tasks" << endl;
	}

};
//fixtures allows us to write common code in a test and share it. e.g setting up a class for a test
//the below code defines a fixure
struct EmployeeTest : public testing::Test {
	//create a pointer to the object
	Employee* emp;
	void SetUp() 
	{
		cout << ">> setting up fixture" << endl; 
		emp = new Employee("Sly", "Devops Engineer", "CCDC", "Microservices", 25); 
	}
	void TearDown() {
		cout << ">> tearing down fixture" << endl;
		delete emp;
	}
};

TEST_F(EmployeeTest, PromotionNotGranted) {

	cout << ">> beggining test" << endl;
string promoStat = emp->AskForPromotion();

EXPECT_STREQ(promoStat.c_str(), "Sorry Sly, NO PROMOTION for you");

}
//
//TEST(Promotion, GRANTED) {
//	Employee emp = Employee("Ayisha", "Software Engineer", "CCDC", "Microservices", 30);
//
//	string promoStat = emp.AskForPromotion();
//
//	EXPECT_STREQ(promoStat.c_str(), "Ayisha got promoted!");
//
//}