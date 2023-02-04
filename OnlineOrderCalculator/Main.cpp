#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Cost
{
public:
	Cost() { dollar_ = 0; cents_ = 0;}
	
private:
	int dollar_, cents_;
	// Static integer for count so each Cost object shares the same count variable.
	static int count_;

public:
	void readCost();
	std::string showCost();
	int showCount();
	// using the const keyword so that the sata in the Vector cannot be changed via the refernce
	// This function takes in a Cost vector and outputs a cost object. 
	Cost computeCost(const vector<Cost> &cosVec);
};

vector<Cost> costVec;

int Cost::count_ = 0;

int main() {

	int amountToPurchase = 0;

	cout << "Please enter the amount of items that you would like to purchase : ";
	cin >> amountToPurchase;

	for (int i = 0; i < amountToPurchase; i++)
	{
		Cost itemCost;
		itemCost.readCost();
		costVec.push_back(itemCost);
	}

	cout << "\n\nTotal Number of Items ordered: " << costVec.back().showCount() << endl;
	cout << "\nTotal Cost: " << costVec.back().computeCost(costVec).showCost() << endl;
	

	return 0;
}

void Cost::readCost()
{
	cout << "\nEnter Dollars : ";
	cin >> dollar_;
	cout << "Enter Cents : ";
	cin >> cents_;

	count_++;
}

std::string Cost::showCost()
{
	
	stringstream oss;
	oss << "$" << dollar_ << "." << cents_;

	return oss.str();
}

int Cost::showCount()
{
	return count_;
}

Cost Cost::computeCost(const vector<Cost> &cosVec)
{
	Cost totalCost;

	for (size_t i = 0; i < cosVec.size(); i++)
	{
		totalCost.dollar_ += cosVec[i].dollar_;
		totalCost.cents_ += cosVec[i].cents_;
	}

	if (totalCost.cents_ >= 100)
	{
		int result = (totalCost.cents_ / 100);
		totalCost.dollar_ += result;
		totalCost.cents_ -= (result*100);
	}

	return totalCost;
}
