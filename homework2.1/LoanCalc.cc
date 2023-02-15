#include <iomanip>
#include <iostream>
#include <limits>

void InputOnlyNum()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

template <typename T> bool NotNegative(T input)
{
    if (!(input >= 0))
    {
        std::cout << "This input can't be negative\n";
        return true;
    }
    return false;
}

template <typename T> T monthlyPay(T totalpay, int year)
{
    return totalpay / (year * 12);
}

template <typename T> T totalAmount(T yearlyInterestRate, T loan, int year)
{
    return (loan) + ((loan * year * yearlyInterestRate) / 100);
}

template <typename T> T totalInterestPay(T totalAmount, T loanAmount)
{
    return totalAmount - loanAmount;
}

int main()
{
    double loan = 0;
    double yearlyInterestRate = 0;
    double monthlyPayment = 0;
    double totalPayment = 0;
    double totalInterestPayment = 0;
    int year = 0;
    const int LEFT_FILL = 24;
    const int RIGHT_FILL = 0;

    std::cout << "Total Loan: ";
    while (!(std::cin >> loan) || NotNegative(loan))
    {
        InputOnlyNum();
        std::cout << "Total Loan: ";
    }
    std::cout << "Yearly Interest Rate: ";
    while (!(std::cin >> yearlyInterestRate) || NotNegative(yearlyInterestRate))
    {
        InputOnlyNum();
        std::cout << "Yearly Interest Rate: ";
    }
    std::cout << "Number of Year: ";
    while (!(std::cin >> year) || NotNegative(year))
    {
        InputOnlyNum();
        std::cout << "Number of Year : ";
    }

    totalPayment = totalAmount(yearlyInterestRate, loan, year);
    monthlyPayment = monthlyPay(totalPayment, year);
    totalInterestPayment = totalInterestPay(totalPayment, loan);

    std::cout << std::fixed << std::showpoint << std::setprecision(2);

    std::cout << "_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_"
              << "\n";

    std::cout << std::setfill('.') << std::left << std::setw(LEFT_FILL) << "Loan Amount ";
    std::cout << std::setfill(' ') << std::right << std::setw(RIGHT_FILL) << ": $" << loan << "\n";

    std::cout << std::setfill('.') << std::left << std::setw(LEFT_FILL) << "Monthly Payment ";
    std::cout << std::setfill(' ') << std::right << std::setw(RIGHT_FILL) << ": $" << monthlyPayment << "\n";

    std::cout << std::setfill('.') << std::left << std::setw(LEFT_FILL) << "Total Payment";
    std::cout << std::setfill(' ') << std::right << std::setw(RIGHT_FILL) << ": $" << totalPayment << "\n";

    std::cout << std::setfill('.') << std::left << std::setw(LEFT_FILL) << "Total Interest Payment";
    std::cout << std::setfill(' ') << std::left << std::setw(RIGHT_FILL) << ": $" << totalInterestPayment << "\n";
}