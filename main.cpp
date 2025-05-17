#include <iostream>
#include <iomanip>

using namespace std;

class TempConverter {
    double inputValue;
public:
    // Constructor takes the value to be converted
    TempConverter(double v) : inputValue{v} {}

    double celsiusToFahrenheit() const {
        return inputValue * 9.0 / 5.0 + 32.0;
    }
    double celsiusToKelvin() const {
        return inputValue + 273.15;
    }
    double fahrenheitToCelsius() const {
        return (inputValue - 32.0) * 5.0 / 9.0;
    }
    double fahrenheitToKelvin() const {
        return (inputValue - 32.0) * 5.0 / 9.0 + 273.15;
    }
    double kelvinToCelsius() const {
        return inputValue - 273.15;
    }
    double kelvinToFahrenheit() const {
        return (inputValue - 273.15) * 9.0 / 5.0 + 32.0;
    }
};

int main() {
    cout << fixed << setprecision(2);

    cout << "============================================\n"
         << "What temperature are you converting from? \n"
         << " 1 - Celsius to Fahrenheit\n"
         << " 2 - Celsius to Kelvin\n"
         << " 3 - Fahrenheit to Celsius\n"
         << " 4 - Fahrenheit to Kelvin\n"
         << " 5 - Kelvin to Celsius\n"
         << " 6 - Kelvin to Fahrenheit\n"
         << "============================================\n"
         << "Enter choice [1-6]: ";

    int choice;
    cin >> choice;
    if (!(choice) || choice < 1 || choice > 6) {
        cerr << "Invalid menu choice.\n";
        return 1;
    }

    cout << "Please enter temperature value: ";
    double temp;
    cin >> temp;
    if (!(temp)) {
        cerr << "Invalid temperature value.\n";
        return 1;
    }

    TempConverter converter{temp};
    double result{};

    switch (choice) {
        case 1:
            result = converter.celsiusToFahrenheit();
            cout << temp << " °C = " << result << " °F\n";
            break;
        case 2:
            result = converter.celsiusToKelvin();
            cout << temp << " °C = " << result << " K\n";
            break;
        case 3:
            result = converter.fahrenheitToCelsius();
            cout << temp << " °F = " << result << " °C\n";
            break;
        case 4:
            result = converter.fahrenheitToKelvin();
            cout << temp << " °F = " << result << " K\n";
            break;
        case 5:
            result = converter.kelvinToCelsius();
            cout << temp << " K = " << result << " °C\n";
            break;
        case 6:
            result = converter.kelvinToFahrenheit();
            cout << temp << " K = " << result << " °F\n";
            break;
    }

    return 0;
}