#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <sstream>
#include <iomanip>
#include <limits>
using namespace std;

string formatNumber(double num)
{
    ostringstream output;
    output << setprecision(10) << defaultfloat << num;
    return output.str();
}


double getNumber(string message)
{
    double num;

    while (true)
    {
        cout << message;

        if (cin >> num)
        {
            return num;
        }

        cout << "Invalid input! Please enter a number.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}
int main()
{
    double num1 = 0;
    double num2 = 0;
    double result = 0;
    char again = 'y';
    int choice;
    vector<string> history;

    while (again == 'y' || again == 'Y')
    {
        cout << "\n===== CALCULATOR =====\n";
        cout << "1. Addition (+)\n";
        cout << "2. Subtraction (-)\n";
        cout << "3. Multiplication (*)\n";
        cout << "4. Division (/)\n";
        cout << "5. View Calculator History\n";
        cout << "6. Percentage (%)\n";
        cout << "7. Power(^)\n";
        cout << "8. Square Root\n";
        cout << "9. Exit\n";
        cout << "Choose an option: ";

        if (!(cin >> choice))
        {
            cout << "Invalid input! Enter a menu number.\n";
            cin.clear();
            cin.ignore(
                numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (choice == 9)
        {
            break;
        }

        if (choice < 1 || choice > 9)
        {
            cout << "Invalid menu choice.\n";
            continue;
        }


        if (choice == 5)
        {
            cout << "\n===== CALCULATION HISTORY =====\n";

            if (history.empty())
            {
                cout << "No calculations yet.\n";
            }
            else
            {
                for (int i = 0; i < history.size(); i++)
                {
                    cout << i + 1 << ". "
                        << history[i] << '\n';
                }
            }

            continue;
        }


        if (choice == 8)
        {
            num1 = getNumber("Enter a number: ");

            if (num1 >= 0)
            {
                result = sqrt(num1);

                cout << "Result: " << formatNumber(result)
                    << '\n';

                history.push_back(
                    "sqrt(" + formatNumber(num1) + ") = "
                    + formatNumber(result));
            }
            else
            {
                cout << "Error: Cannot calculate the square "
                    "root of a negative number.\n";
            }
        }
        else
        {
            num1 = getNumber("Enter first number: ");
            num2 = getNumber("Enter second number: ");

            switch (choice)
            {
            case 1:
                result = num1 + num2;
                cout << "Result: " << formatNumber(result)
                    << '\n';

                history.push_back(
                    formatNumber(num1) + " + "
                    + formatNumber(num2) + " = "
                    + formatNumber(result));
                break;

            case 2:
                result = num1 - num2;
                cout << "Result: " << formatNumber(result)
                    << '\n';

                history.push_back(
                    formatNumber(num1) + " - "
                    + formatNumber(num2) + " = "
                    + formatNumber(result));
                break;

            case 3:
                result = num1 * num2;
                cout << "Result: " << formatNumber(result)
                    << '\n';

                history.push_back(
                    formatNumber(num1) + " * "
                    + formatNumber(num2) + " = "
                    + formatNumber(result));
                break;

            case 4:
                if (num2 != 0)
                {
                    result = num1 / num2;
                    cout << "Result: "
                        << formatNumber(result) << '\n';

                    history.push_back(
                        formatNumber(num1) + " / "
                        + formatNumber(num2) + " = "
                        + formatNumber(result));
                }
                else
                {
                    cout << "Error: Cannot divide by zero.\n";
                }
                break;

            case 6:

                result = num1 * num2 / 100.0;

                cout << formatNumber(num2)
                    << "% of " << formatNumber(num1)
                    << " = " << formatNumber(result) << '\n';

                history.push_back(
                    formatNumber(num2) + "% of "
                    + formatNumber(num1) + " = "
                    + formatNumber(result));
                break;

            case 7:
                result = pow(num1, num2);

                if (isnan(result))
                {
                    cout << "Error: Invalid power operation.\n";
                }
                else if (isinf(result))
                {
                    cout << "Error: Result is too large.\n";
                }
                else
                {
                    cout << "Result: " << formatNumber(result)
                        << '\n';

                    history.push_back(
                        formatNumber(num1) + " ^ "
                        + formatNumber(num2) + " = "
                        + formatNumber(result));
                }
                break;
            }
        }

        cout << "\nReturn to menu (Y/N): ";
        cin >> again;
    }

    cout << "Calculator closed.\n";

    return 0;
}