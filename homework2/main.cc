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

template <typename T> double gross(T ticketprice, uint totalticket)
{
    return ticketprice * totalticket;
}

template <typename T> double totalTicket(T A_ticket, T B_ticket)
{
    return A_ticket + B_ticket;
}

template <typename T> double amountDonate(T grossAmount, uint percentDonated)
{
    return grossAmount * percentDonated / 100;
}

template <typename T> double net_Sale(T grossAmount, T amountDonated)
{
    return grossAmount - amountDonated;
}
int main()
{
    std::string movieName;
    double adultTicketPrice = 0;
    double childTicketPrice = 0;
    double amountDonated = 0;
    double netSale = 0;
    double grossAmount = 0;
    uint donatedPercentage = 0;
    uint totalAdultTicketSold = 0;
    uint totalKidTicketSold = 0;
    uint totalTicketSold = 0;
    const int LEFT_FILL = 35;
    const int RIGHT_FILL = 7;

    std::ofstream Outfile;
    std::string fileName = "Outfile.txt";

    std::cout << "Movie Name: ";
    getline(std::cin, movieName);

    std::cout << "Adult ticket price: ";
    while (!(std::cin >> adultTicketPrice))
    {
        InputOnlyNum();
        std::cout << "Adult ticket price: ";
    }

    std::cout << "Child ticket price: ";
    while (!(std::cin >> childTicketPrice))
    {
        InputOnlyNum();
        std::cout << "Child ticket price: ";
    }

    std::cout << "Number of adult tickets sold: ";
    while (!(std::cin >> totalAdultTicketSold))
    {
        InputOnlyNum();
        std::cout << "Number of adult tickets sold: ";
    }

    std::cout << "Number of child tickets sold: ";
    while (!(std::cin >> totalKidTicketSold))
    {
        InputOnlyNum();
        std::cout << "Number of child tickets sold: ";
    }

    std::cout << "Percentage of gross amount to be donated: ";
    while (!(std::cin >> donatedPercentage))
    {
        std::cout << "Percentage of gross amount to be donated: ";
        InputOnlyNum();
    }

    totalTicketSold = totalTicket(totalKidTicketSold, totalAdultTicketSold);
    grossAmount = gross(adultTicketPrice, totalAdultTicketSold) + gross(childTicketPrice, totalKidTicketSold);
    amountDonated = amountDonate(grossAmount, donatedPercentage);
    netSale = net_Sale(grossAmount, amountDonated);

    std::cout << std::fixed << std::showpoint << std::setprecision(2);

    std::cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"
              << "\n";

    std::cout << std::setfill('.') << std::left << std::setw(LEFT_FILL) << "Movie Name: ";
    std::cout << std::setfill(' ') << std::right << std::setw(RIGHT_FILL) << movieName << "\n";

    std::cout << std::setfill('.') << std::left << std::setw(LEFT_FILL) << "Number of Tickets Sold: ";
    std::cout << std::setfill(' ') << std::right << std::setw(RIGHT_FILL) << "" << totalTicketSold << "\n";

    std::cout << std::setfill('.') << std::left << std::setw(LEFT_FILL) << "Gross Amount: ";
    std::cout << std::setfill(' ') << std::right << std::setw(RIGHT_FILL) << "$" << grossAmount << "\n";

    std::cout << std::setfill('.') << std::left << std::setw(LEFT_FILL) << "Percentage of Gross Amount Donated: ";
    std::cout << std::setfill(' ') << std::right << std::setw(RIGHT_FILL) << donatedPercentage << "%\n";

    std::cout << std::setfill('.') << std::left << std::setw(LEFT_FILL) << "Amount Donated: ";
    std::cout << std::setfill(' ') << std::right << std::setw(RIGHT_FILL) << "$" << amountDonated << "\n";

    std::cout << std::setfill('.') << std::left << std::setw(LEFT_FILL) << "Net Sale: ";
    std::cout << std::setfill(' ') << std::right << std::setw(RIGHT_FILL) << "$" << netSale << "\n";

    // Writing to file
    Outfile.open(fileName, std::fstream::app);

    if (Outfile.is_open())
    {
        Outfile << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"
                << "\n";

        Outfile << std::setfill('.') << std::left << std::setw(LEFT_FILL) << "Movie Name: ";
        Outfile << std::setfill(' ') << std::right << std::setw(RIGHT_FILL) << movieName << "\n";

        Outfile << std::setfill('.') << std::left << std::setw(LEFT_FILL) << "Number of Tickets Sold: ";
        Outfile << std::setfill(' ') << std::right << std::setw(RIGHT_FILL) << "" << totalTicketSold << "\n";

        Outfile << std::setfill('.') << std::left << std::setw(LEFT_FILL) << "Gross Amount: ";
        Outfile << std::setfill(' ') << std::right << std::setw(RIGHT_FILL) << "$" << grossAmount << "\n";

        Outfile << std::setfill('.') << std::left << std::setw(LEFT_FILL) << "Percentage of Gross Amount Donated: ";
        Outfile << std::setfill(' ') << std::right << std::setw(RIGHT_FILL) << donatedPercentage << "%\n";

        Outfile << std::setfill('.') << std::left << std::setw(LEFT_FILL) << "Amount Donated: ";
        Outfile << std::setfill(' ') << std::right << std::setw(RIGHT_FILL) << "$" << amountDonated << "\n";

        Outfile << std::setfill('.') << std::left << std::setw(LEFT_FILL) << "Net Sale: ";
        Outfile << std::setfill(' ') << std::right << std::setw(RIGHT_FILL) << "$" << netSale << "\n";

        Outfile.close();
    }
}
