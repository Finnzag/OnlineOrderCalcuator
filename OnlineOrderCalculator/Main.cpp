#include <iostream>
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
	Cost computeCost(const Cost& cost_);
};

vector<Cost> costVec;
int totalCount;

int main() {

	int amountToPurchase = 0;

	cout << "Please enter the amount of items that you would like to purchase : ";
	cin >> amountToPurchase;

	for (int i = 0; i < amountToPurchase; i++)
	{
		Cost itemCost;
		itemCost.readCost();
	}

	cout << "Total Number of Items ordered: " << costVec[0].showCount() << endl;
	

	return 0;
}

void Cost::readCost()
{
	cout << "\nEnter Dollars : ";
	cin >> dollar_;
	cout << "Enter Cents : ";
	cin >> cents_;

	count_ = 1;
}

int Cost::showCount()
{
	for (size_t i = 0; i < costVec.size(); i++)
	{
		totalCount += costVec[i].count_;
	}

	return totalCount;
}

Cost Cost::computeCost(const Cost& cost_)
{
	Cost totalCost;

	return totalCost;
	
}
