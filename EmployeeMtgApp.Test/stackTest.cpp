#include "pch.h";
using namespace std;
#include <vector>;

class Stack {
	vector<int> vstack{};
public:
	void push(int value) 
	{
		vstack.push_back(value);
	}
	int pop()
	{
		if (vstack.size() > 0)
		{
			int value = vstack.back();
			vstack.pop_back();
			return value;
		}
		else
		{
			return -1;
		}
	}

	int size() { return vstack.size(); }
};

struct stackTest: public testing::Test{
	
	Stack s1;
	void SetUp() {
		cout << ">>Setting up fixture" << endl;
			int initValues[] = { 1,2,3,4,5,6,7,8,9 };
			for (auto& val : initValues) 
			{
				s1.push(val);
			}
	}

	void TearDown() {
		cout << ">>Tearing down fixute" << endl;
	}

};

TEST_F(stackTest, popTest) 
{
	int lastPopped = 9;

	while (lastPopped != 1) {
		ASSERT_EQ(s1.pop(), lastPopped--);
	}

}