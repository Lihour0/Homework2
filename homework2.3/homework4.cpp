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

template <typename T> T averageDaily(T netBalance, T d1, T payment, T d2)
{
    return (netBalance * d1 - payment * d2) / d1;
}

template <typename T> T interest(T averageDailyBalance, T monthlyIntrestRate)
{
    return averageDailyBalance * monthlyIntrestRate;
}

int main()
{
    double netBalance = 0;
    double d1 = 0;
    double d2 = 0;
    double payment = 0;
    double monthlyInterestRate = 0;
    double averageDailyBalance = 0;
    double interestMonthly = 0;

    std::cout << "Net Balance: ";
    while (!(std::cin >> netBalance) || NotNegative(netBalance))
    {
        InputOnlyNum();
        std::cout << "Net Balance: ";
    }
    std::cout << "Payment Made: ";
    while (!(std::cin >> payment) || NotNegative(payment))
    {
        InputOnlyNum();
        std::cout << "Payment Made: ";
    }
    std::cout << "Number of day in the billing cycle: ";
    while (!(std::cin >> d1) || NotNegative(d1))
    {
        InputOnlyNum();
        std::cout << "Number of day in the billing cycle: ";
    }
    std::cout << "Number of days payment is made before billing cycle: ";
    while (!(std::cin >> d2) || NotNegative(d2))
    {
        InputOnlyNum();
        std::cout << "Number of days payment is made before billing cycle: ";
    }
    std::cout << "Monthly Interest: ";
    while (!(std::cin >> monthlyInterestRate) || NotNegative(monthlyInterestRate))
    {
        InputOnlyNum();
        std::cout << "Monthly Interest: ";
    }

    averageDailyBalance = averageDaily(netBalance, d1, payment, d2);
    interestMonthly = interest(averageDailyBalance, monthlyInterestRate);

    std::cout << std::setprecision(2) << std::fixed << std::showpoint;

    std::cout << "Average Daily Balance is: ";
    std::cout << "$" << averageDailyBalance << "\n";
    std::cout << "Interest is: ";
    std::cout << "$" << interestMonthly;
}