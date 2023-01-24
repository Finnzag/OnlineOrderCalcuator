#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Cost
{
public:
	Cost(){dollar_ = 0; cents_ = 0; count_ = 0;}
private:
	int dollar_, cents_, count_;
public:
	void readCost();
	std::string showCost();
	int showCount();
	Cost computeCost(const vector<Cost> &cosVec);

	void setCount(int count);
};

vector<Cost> costVec;

int main() {

	int amountToPurchase = 0;
	int purchaseCount = 0;

	cout << "Please enter the amount of items that you would like to purchase : ";
	cin >> amountToPurchase;

	for (int i = 0; i < amountToPurchase; i++)
	{
		Cost itemCost;
		itemCost.readCost();
		purchaseCount++;
		itemCost.setCount(purchaseCount);
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

	count_ += 1;
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

void Cost::setCount(int count)
{
	count_ = count;
}
