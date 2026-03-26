#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class RetailItem {
private:
    string itemId;
    string description;
    int unitsOnHand;
    double pricePerItem;

public:
    RetailItem(string id, string desc, int units, double price) {
        itemId = id;
        description = desc;
        unitsOnHand = units;
        pricePerItem = price;
    }

    void setData(string id, string desc, int units, double price) {
        itemId = id;
        description = desc;
        unitsOnHand = units;
        pricePerItem = price;
    }

    string getItemId() const {
        return itemId;
    }

    string getDescription() const {
        return description;
    }

    int getUnitsOnHand() const {
        return unitsOnHand;
    }

    double getPricePerItem() const {
        return pricePerItem;
    }

    void addUnits(int units) {
        unitsOnHand += units;
    }

    void reduceUnits(int units) {
        if (units <= unitsOnHand) {
            unitsOnHand -= units;
        }
    }

    double TotalPrice() const {
        return unitsOnHand * pricePerItem;
    }
};

int main() {
    RetailItem item("A001", "T-Shirt", 50, 19.99);

    cout << fixed << setprecision(2);
    cout << "Initial Item Information:" << endl;
    cout << "Item ID: " << item.getItemId() << endl;
    cout << "Description: " << item.getDescription() << endl;
    cout << "Units on Hand: " << item.getUnitsOnHand() << endl;
    cout << "Price per Item: $" << item.getPricePerItem() << endl;
    cout << "Total Price: $" << item.TotalPrice() << endl;

    item.addUnits(10);
    cout << "\nAfter adding 10 units:" << endl;
    cout << "Units on Hand: " << item.getUnitsOnHand() << endl;
    cout << "Total Price: $" << item.TotalPrice() << endl;

    item.reduceUnits(5);
    cout << "\nAfter reducing 5 units:" << endl;
    cout << "Units on Hand: " << item.getUnitsOnHand() << endl;
    cout << "Total Price: $" << item.TotalPrice() << endl;

    return 0;
}
