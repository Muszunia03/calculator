#include <iostream>
#include <vector>
#include <algorithm>
#include <complex>
using namespace std;

class Function {
public:
    long double add(long double number1, long double number2) {
        long double result = number1 + number2;
        cout << number1 << " + " << number2 << " = " << result << endl;
        return result;
    }

    long double subtract(long double number1, long double number2) {
        long double result = number1 - number2;
        cout << number1 << " - " << number2 << " = " << result << endl;
        return result;
    }

    long double multiply(long double number1, long double number2) {
        long double result = number1 * number2;
        cout << number1 << " * " << number2 << " = " << result << endl;
        return result;
    }

    long double divide(long double number1, long double number2) {
        if (number2 == 0) {
            cout << "Division by zero is not allowed." << endl;
            return 0;
        }
        else {
            long double result = number1 / number2;
            cout << number1 << " / " << number2 << " = " << result << endl;
            return result;
        }
    }

    long double power(long double base, int exponent) {
        long double result = 1;
        if (exponent == 0) {
            result = 1;
        }
        else {
            while (exponent != 0) {
                result *= base;
                --exponent;
            }
        }
        cout << base << " raised to the power " << exponent << " = " << result << endl;
        return result;
    }

    long double sqrt(long double x) {
        if (x < 0) {
            cout << "Square root of a negative number is not defined in real numbers." << endl;
            return -1;
        }

        const long double tolerance = 1e-14;
        long double result = x / 2.0;
        while (abs(result * result - x) > tolerance) {
            result = (result + x / result) / 2.0;
        }

        cout << "Square root of " << x << " = " << result << endl;
        return result;
    }

    long double log_newton(long double x) {
        if (x <= 0) {
            cout << "Logarithm of non-positive number is not defined." << endl;
            return -1;
        }

        const long double tolerance = 1e-14;
        long double result = x;
        while (true) {
            long double new_result = result - (exp(result) - x) / exp(result);
            if (abs(new_result - result) < tolerance) {
                break;
            }
            result = new_result;
        }

        cout << "Logarithm of " << x << " = " << result << endl;
        return result;
    }

    long double absolutValue(long double x) {
        long double result = x < 0 ? -x : x;
        cout << "Absolute value of " << x << " = " << result << endl;
        return result;
    }

    long double mean(vector<long double>& numbers) {
        if (numbers.empty()) {
            cout << "No numbers provided for mean calculation." << endl;
            return 0;
        }

        long double sum = 0;
        for (long double number : numbers) {
            sum += number;
        }
        long double result = sum / numbers.size();
        cout << "Mean of the provided numbers = " << result << endl;
        return result;
    }

    long double median(vector<long double>& numbers) {
        if (numbers.empty()) {
            cout << "No numbers provided for median calculation." << endl;
            return 0;
        }

        sort(numbers.begin(), numbers.end());
        long double result;
        if (numbers.size() % 2 == 0) {
            result = (numbers[numbers.size() / 2 - 1] + numbers[numbers.size() / 2]) / 2;
        }
        else {
            result = numbers[numbers.size() / 2];
        }
        cout << "Median of the provided numbers = " << result << endl;
        return result;
    }
    
    long double factorial(long double x) {

        int result = 1;
        for (int i = x; i > 0; i--) {
            result *= x;
            x--;
        }
        cout << "Factorial of provided number = " << result << endl;
        return result;
    }

    long double exponential(long double x) {
        const int max_iterations = 100;
        const long double tolerance = 1e-14;
        long double term = 1;
        long double sum = 1;

        for (int i = 1; i < max_iterations; ++i) {
            term *= x / i;
            sum += term;
            if (abs(term) < tolerance) {
                break;
            }
        }
        cout << "Exponential of " << x << " = " << sum << endl;
        return sum;
    }

    long double log10(long double x) {
        const long double ln_10 = 2.30258509299404568402;
        long double ln_x = log_newton(x);
        long double result = ln_x / ln_10;
        cout << "Base-10 logarithm of " << x << " = " << result << endl;
        return result;
    }

    complex<long double> add_complex(complex<long double> number1, complex<long double> number2) {
        complex<long double> result = number1 + number2;
        cout << "(" << number1.real() << " + " << number1.imag() << "i) + ("
            << number2.real() << " + " << number2.imag() << "i) = "
            << result.real() << " + " << result.imag() << "i" << endl;
        return result;
    }

    complex<long double> subtract_complex(complex<long double> number1, complex<long double> number2) {
        complex<long double> result = number1 - number2;
        cout << "(" << number1.real() << " + " << number1.imag() << "i) - ("
            << number2.real() << " + " << number2.imag() << "i) = "
            << result.real() << " + " << result.imag() << "i" << endl;
        return result;
    }

    complex<long double> parse_complex(const string& input) {
        long double real = 0, imag = 0;
        char sign, i;
        stringstream ss(input);
        ss >> real >> sign >> imag >> i;
        if (sign == '-') imag = -imag;
        return complex<long double>(real, imag);
    }
    
};

int main() {
    Function Calc;

    cout << "Which operation do you want to perform? " << endl;
    cout << "1. Add\n2. Subtract\n3. Multiply\n4. Divide\n5. Power\n6. Sqrt\n7. Log\n8. Absolute value\n9. Mean\n10. Median \n11. Factorial\n12. Exponential\n13. Logarithm10\n14. Add (Complex)\n15. Subtract (Complex)" << endl;
    int response;
    cin >> response;

    switch (response) {
    case 1: {
        long double number1, number2;
        cout << "Enter the first number: ";
        cin >> number1;
        cout << "Enter the second number: ";
        cin >> number2;
        Calc.add(number1, number2);
        break;
    }
    case 2: {
        long double number1, number2;
        cout << "Enter the first number: ";
        cin >> number1;
        cout << "Enter the second number: ";
        cin >> number2;
        Calc.subtract(number1, number2);
        break;
    }
    case 3: {
        long double number1, number2;
        cout << "Enter the first number: ";
        cin >> number1;
        cout << "Enter the second number: ";
        cin >> number2;
        Calc.multiply(number1, number2);
        break;
    }
    case 4: {
        long double number1, number2;
        cout << "Enter the first number: ";
        cin >> number1;
        cout << "Enter the second number: ";
        cin >> number2;
        Calc.divide(number1, number2);
        break;
    }
    case 5: {
        long double base;
        int exponent;
        cout << "Enter the base number: ";
        cin >> base;
        cout << "Enter the exponent: ";
        cin >> exponent;
        Calc.power(base, exponent);
        break;
    }
    case 6: {
        long double number;
        cout << "Enter the number to find the square root: ";
        cin >> number;
        Calc.sqrt(number);
        break;
    }
    case 7: {
        long double log_number;
        cout << "Enter the number to find the logarithm: ";
        cin >> log_number;
        Calc.log_newton(log_number);
        break;
    }
    case 8: {
        long double abs_number;
        cout << "Enter the number to find the absolute value: ";
        cin >> abs_number;
        Calc.absolutValue(abs_number);
        break;
    }
    case 9: {
        vector<long double> numbers;
        long double number;
        cout << "Enter numbers to calculate the mean (enter 'q' to stop): ";
        while (cin >> number) {
            numbers.push_back(number);
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        Calc.mean(numbers);
        break;
    }
    case 10: {
        vector<long double> numbers;
        long double number;
        cout << "Enter numbers to calculate the median (enter 'q' to stop): ";
        while (cin >> number) {
            numbers.push_back(number);
        }
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        Calc.median(numbers);
        break;
    }
    case 11: {
        long double fact_number;
        cout << "Enter the number to find the factorial value: ";
        cin >> fact_number;
        Calc.factorial(fact_number);
        break;
    }
    case 12: {
        long double exp_number;
        cout << "Enter the number to find the exponential value: ";
        cin >> exp_number;
        Calc.exponential(exp_number);
        break;
    }
    case 13: {
        long double log10_number;
        cout << "Enter the number to find the log10 value: ";
        cin >> log10_number;
        Calc.exponential(log10_number);
        break;
    }
    case 14: {
        string input1, input2;
        cout << "Enter the first complex number (a+bi): ";
        getline(cin, input1);
        cout << "Enter the second complex number (a+bi): ";
        getline(cin, input2);
        complex<long double> number1 = Calc.parse_complex(input1);
        complex<long double> number2 = Calc.parse_complex(input2);
        Calc.add_complex(number1, number2);
        break;
    }
    case 15: {
        string input1, input2;
        cout << "Enter the first complex number (a+bi): ";
        getline(cin, input1);
        cout << "Enter the second complex number (a+bi): ";
        getline(cin, input2);
        complex<long double> number1 = Calc.parse_complex(input1);
        complex<long double> number2 = Calc.parse_complex(input2);
        Calc.subtract_complex(number1, number2);
        break;
    }
    default:
        cout << "Invalid choice." << endl;
        break;
    }

    return 0;
}
