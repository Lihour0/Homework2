#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>

void InputOnlyNum()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

template <typename T> T tax(T income, T percentageTax)
{
    return income * (percentageTax / 100.);
}

int main()
{
    std::string userName;
    double Income = 0;
    double federalTax = 15;
    double stateTax = 3.5;
    double SSTax = 5.75;
    double medicareTax = 2.75;
    double pensionPlan = 5;
    double health_Insurance = 75;
    double netIncome = 0;
    double federal_Tax, state_Tax, SS_Tax, medicare_Tax, pension_Plan;
    const int LEFT_FILL = 27;
    const int RIGHT_FILL = 0;

    std::fstream Outfile;
    std::string fileName = "taxCalculate.txt";

    std::cout << "Enter your name: ";
    getline(std::cin, userName);

    std::cout << "Gross Income: ";
    while (!(std::cin >> Income))
    {
        InputOnlyNum();
        std::cout << "Total Loan: ";
    }
    federal_Tax = tax(Income, federalTax);
    state_Tax = tax(Income, stateTax);
    SS_Tax = tax(Income, SSTax);
    medicare_Tax = tax(Income, medicareTax);
    pension_Plan = tax(Income, pensionPlan);
    netIncome = Income - (federal_Tax + state_Tax + SS_Tax + medicare_Tax + pension_Plan + health_Insurance);

    std::cout << std::fixed << std::showpoint << std::setprecision(2);

    std::cout << userName << "\n";

    std::cout << std::setfill('.') << std::left << std::setw(LEFT_FILL) << "Gross Amount: ";
    std::cout << std::setfill(' ') << std::right << std::setw(RIGHT_FILL) << "$" << Income << "\n";

    std::cout << std::setfill('.') << std::left << std::setw(LEFT_FILL) << "Federal Tax: ";
    std::cout << std::setfill(' ') << std::right << std::setw(RIGHT_FILL) << "$" << federal_Tax << "\n";

    std::cout << std::setfill('.') << std::left << std::setw(LEFT_FILL) << "State Tax:";
    std::cout << std::setfill(' ') << std::right << std::setw(RIGHT_FILL) << "$" << state_Tax << "\n";

    std::cout << std::setfill('.') << std::left << std::setw(LEFT_FILL) << "Social Security Tax: ";
    std::cout << std::setfill(' ') << std::left << std::setw(RIGHT_FILL) << "$" << SS_Tax << "\n";

    std::cout << std::setfill('.') << std::left << std::setw(LEFT_FILL) << "Medicare/Medicaid Tax: ";
    std::cout << std::setfill(' ') << std::left << std::setw(RIGHT_FILL) << "$" << medicare_Tax << "\n";

    std::cout << std::setfill('.') << std::left << std::setw(LEFT_FILL) << "Pension Plan: ";
    std::cout << std::setfill(' ') << std::left << std::setw(RIGHT_FILL) << "$" << pension_Plan << "\n";

    std::cout << std::setfill('.') << std::left << std::setw(LEFT_FILL) << "Health Insurance: ";
    std::cout << std::setfill(' ') << std::left << std::setw(RIGHT_FILL) << "$" << health_Insurance << "\n";

    std::cout << std::setfill('.') << std::left << std::setw(LEFT_FILL) << "Net Pay: ";
    std::cout << std::setfill(' ') << std::left << std::setw(RIGHT_FILL) << "$" << netIncome << "\n";

    Outfile.open(fileName, std::fstream::app);

    if (Outfile.is_open())
    {
        Outfile << userName << "\n";

        Outfile << std::setfill('.') << std::left << std::setw(LEFT_FILL) << "Gross Amount: ";
        Outfile << std::setfill(' ') << std::right << std::setw(RIGHT_FILL) << "$" << Income << "\n";

        Outfile << std::setfill('.') << std::left << std::setw(LEFT_FILL) << "Federal Tax: ";
        Outfile << std::setfill(' ') << std::right << std::setw(RIGHT_FILL) << "$" << federal_Tax << "\n";

        Outfile << std::setfill('.') << std::left << std::setw(LEFT_FILL) << "State Tax:";
        Outfile << std::setfill(' ') << std::right << std::setw(RIGHT_FILL) << "$" << state_Tax << "\n";

        Outfile << std::setfill('.') << std::left << std::setw(LEFT_FILL) << "Social Security Tax: ";
        Outfile << std::setfill(' ') << std::left << std::setw(RIGHT_FILL) << "$" << SS_Tax << "\n";

        Outfile << std::setfill('.') << std::left << std::setw(LEFT_FILL) << "Medicare/Medicaid Tax: ";
        Outfile << std::setfill(' ') << std::left << std::setw(RIGHT_FILL) << "$" << medicare_Tax << "\n";

        Outfile << std::setfill('.') << std::left << std::setw(LEFT_FILL) << "Pension Plan: ";
        Outfile << std::setfill(' ') << std::left << std::setw(RIGHT_FILL) << "$" << pension_Plan << "\n";

        Outfile << std::setfill('.') << std::left << std::setw(LEFT_FILL) << "Health Insurance: ";
        Outfile << std::setfill(' ') << std::left << std::setw(RIGHT_FILL) << "$" << health_Insurance << "\n";

        Outfile << std::setfill('.') << std::left << std::setw(LEFT_FILL) << "Net Pay: ";
        Outfile << std::setfill(' ') << std::left << std::setw(RIGHT_FILL) << "$" << netIncome << "\n";

        Outfile.close();
    }
}
