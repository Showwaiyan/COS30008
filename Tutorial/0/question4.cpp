#include <iostream>

float askDailySales();
float computeCommission(float aSales);
void displaySalesAndCommission(float aSales, float aCommission);

int main() {
  float sales = askDailySales();
  float commission = computeCommission(sales);
  displaySalesAndCommission(sales, commission);
  return 0;
}

float askDailySales() {
  float sales_in_dollor = 0;
  std::cout << "Enter you daily total sales: ";
  std::cin >> sales_in_dollor;

  return sales_in_dollor;
}

float computeCommission(float aSales) {
  float commission = 0;

  if (aSales < 1000) commission = aSales * 0.03;
  else if (aSales < 3000) commission = aSales * 0.035;
  else commission = aSales * 0.045;

  return commission;
}


void displaySalesAndCommission(float aSales, float aCommission) {
  std::cout << "Total Sales: " << aSales << std::endl;
  std::cout << "Total Commission: " << aCommission << std::endl;
  std::cout << "Total: " << aSales+aCommission << std::endl;
}
