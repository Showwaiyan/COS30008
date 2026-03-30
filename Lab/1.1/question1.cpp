#include <iostream>
using namespace std;

class Temperature {
private:
    double kelvin;

public:
    void setTempKelvin(double k) {
        kelvin = k;
    }

    void setTempFahrenheit(double f) {
        kelvin = (f - 32) * 5 / 9 + 273.15;
    }

    void setTempCelsius(double c) {
        kelvin = c + 273.15;
    }

    double getTempKelvin() {
        return kelvin;
    }

    double getTempFahrenheit() {
        return (kelvin - 273.15) * 9 / 5 + 32;
    }

    double getTempCelsius() {
        return kelvin - 273.15;
    }
};

int main() {
    Temperature t;
    
    t.setTempCelsius(100);
    cout << "Celsius: 100" << endl;
    cout << "Kelvin: " << t.getTempKelvin() << endl;
    cout << "Fahrenheit: " << t.getTempFahrenheit() << endl;
    cout << endl;
    
    t.setTempFahrenheit(32);
    cout << "Fahrenheit: 32" << endl;
    cout << "Kelvin: " << t.getTempKelvin() << endl;
    cout << "Celsius: " << t.getTempCelsius() << endl;
    cout << endl;
    
    t.setTempKelvin(300);
    cout << "Kelvin: 300" << endl;
    cout << "Celsius: " << t.getTempCelsius() << endl;
    cout << "Fahrenheit: " << t.getTempFahrenheit() << endl;
    
    return 0;
}
