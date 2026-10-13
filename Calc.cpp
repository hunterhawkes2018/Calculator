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
        cout << "9. Ohm's Law\n";
        cout << "10.DC Circuit Analyzer\n";
            cout << "11.Exit\n";
        cout << "Choose an option: ";

        if (!(cin >> choice))
        {
            cout << "Invalid input! Enter a menu number.\n";
            cin.clear();
            cin.ignore(
                numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (choice == 11)
        {
            break;
        }

        if (choice < 1 || choice > 11)
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
            if (choice != 9 && choice != 10)
            {
                num1 = getNumber("Enter first number: ");
                num2 = getNumber("Enter second number: ");
            }
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

            case 9:
            {
                int electricalChoice;

                cout << "\nOhm's Law Calculator:\n";
                cout << "1. Calculate Voltage\n";
                cout << "2. Calculate Current\n";
                cout << "3. Calculate Resistance\n";
                cout << "4. Calculate Power\n";
                cout << "Choose an option: ";
                if (!(cin >> electricalChoice))
                {
                    cout << "Invalid input!\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }
                switch (electricalChoice)
                {
                case 1:
                {
                    double current = getNumber(
                        "Enter current in Amps: ");

                    double resistance = getNumber(
                        "Enter resistance in Ohms: ");

                    result = current * resistance;

                    cout << "Voltage: "
                        << formatNumber(result)
                        << " Volts\n";

                    history.push_back(
                        "Voltage = "
                        + formatNumber(current) + " A * "
                        + formatNumber(resistance) + " ohms = "
                        + formatNumber(result) + " V");
                    break;
                }
                case 2:
                {
                    double voltage = getNumber(
                        "Enter Voltage in Volts: ");

                    double resistance = getNumber(
                        "Enter resistance in Ohms: ");
                    if (resistance == 0)
                    {
                        cout << "Error: Resistance cannot be zero";
                        break;
                    }
                    result = voltage / resistance;

                    cout << "Current: "
                        << formatNumber(result)
                        << " A\n";
                    history.push_back(
                        "Current = "
                        + formatNumber(voltage) + " V / "
                        + formatNumber(resistance) + " ohms = "
                        + formatNumber(result) + " A");
                    break;
                }
                case 3:
                {
                    double voltage =
                        getNumber("Enter voltage (volts): ");
                    double current =
                        getNumber("Enter current (amps): ");

                    if (current == 0)
                    {
                        cout << "Error: Current cannot be zero.\n";
                        break;
                    }

                    result = voltage / current;

                    cout << "Resistance: "
                        << formatNumber(result) << " ohms\n";
                    history.push_back(
                        "Resistance = "
                        + formatNumber(voltage) + " V / "
                        + formatNumber(current) + " A = "
                        + formatNumber(result) + " ohms");
                    break;
                }

                case 4:
                {
                    double voltage =
                        getNumber("Enter voltage (volts): ");
                    double current =
                        getNumber("Enter current (amps): ");

                    result = voltage * current;

                    cout << "Power: "
                        << formatNumber(result) << " watts\n";
                    history.push_back(
                        "Power = "
                        + formatNumber(voltage) + " V * "
                        + formatNumber(current) + " A = "
                        + formatNumber(result) + " W");
                    break;
                }

                default:
                    cout << "Invalid electrical menu choice.\n";
                    break;
                }
                break;
            }
           case 10:
           {
               double supplyVoltage;

               cout << "\nDC Circuit Analyzer\n";

               supplyVoltage = getNumber("Enter supply voltage (V): ");

               int resistorCount = static_cast<int>(
                   getNumber("How many resistors are in series? "));

               if (resistorCount <= 0 || resistorCount > 100)
               {
                   cout << "Enter a resistor count from 1 to 100.\n";
                   break;
               }

               vector<double> resistors;
               double totalResistance = 0;

               for (int i = 0; i < resistorCount; i++)
               {
                   double resistance;

                   do
                   {
                       resistance = getNumber(
                           "Enter resistance for R" +
                           to_string(i + 1) + " (ohms): ");

                       if (resistance <= 0)
                       {
                           cout << "Resistance must be greater than zero.\n";
                       }

                   } while (resistance <= 0);

                   resistors.push_back(resistance);
                   totalResistance += resistance;
               }

               if (totalResistance <= 0)
               {
                   cout << "Error: Resistance must be greater than zero.\n";
                   break;
               }
               double circuitCurrent = supplyVoltage / totalResistance;
               double totalPower = supplyVoltage * circuitCurrent;

               cout << "\n--- Circuit Results ---\n";
               cout << "Total resistance: "
                   << formatNumber(totalResistance) << " ohms\n";

               cout << "Circuit current: "
                   << formatNumber(circuitCurrent) << " A\n";

               for (int i = 0; i < resistorCount; i++)
               {
                   double voltageDrop = circuitCurrent * resistors[i];

                   cout << "Voltage drop across R" << i + 1 << ": "
                       << formatNumber(voltageDrop) << " V\n";
               }

               cout << "Total power: "
                   << formatNumber(totalPower) << " W\n";

               history.push_back(
                   "DC series circuit: " +
                   formatNumber(supplyVoltage) + " V, " +
                   to_string(resistorCount) + " resistors, total resistance = " +
                   formatNumber(totalResistance) + " ohms, current = " +
                   formatNumber(circuitCurrent) + " A");
          

               break;
                }

              

            
            }
            while (true)
            {
                cout << "\nReturn to menu (Y/N): ";
                cin >> again;

                if (again == 'y' || again == 'Y' || again == 'n' || again == 'N')
                {
                    break;
                }

                cout << "Invalid input! Please enter Y or N.\n";

            }
        }

        cout << "Calculator closed.\n";
    }
    return 0;
}