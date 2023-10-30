#include <iostream>
#include <ctime>
using namespace std;

void loan();
void getLoanType(int &loanopt);
void calculateLoan(int principal, int tenure, double rate);
void goBack();

int main()
{
    loan();
    return 0;
}

void loan()
{
    int loanopt;
    getLoanType(loanopt);

    switch (loanopt)
    {
    case 1:
        cout << "\nYou Choose - Home loan" << endl;
        break;
    case 2:
        cout << "\nYou Choose - Car loan" << endl;
        break;
    case 3:
        cout << "\nYou Choose - Agriculture loan" << endl;
        break;
    default:
        cout << "\nEnter option between 1 to 3" << endl;
        loan();
        return;
    }

    int principal, tenure;
    cout << "\nEnter loan amount: ";
    cin >> principal;
    if (principal > 1000000)
    {
        cout << "\nError! Maximum amount of loan is 1,000,000 rs" << endl;
        loan();
        return;
    }

    cout << "Enter tenure (in years): ";
    cin >> tenure;

    calculateLoan(principal, tenure, (loanopt == 1 ? 12 : (loanopt == 2 ? 10 : 7)));
    goBack();
}

void getLoanType(int &loanopt)
{
   cout << "\n\t----* Loan Options *----" << endl;
    cout << "\t| 1. Home Loan          |" << endl;
    cout << "\t| 2. Car Loan           |" << endl;
    cout << "\t| 3. Agriculture Loan   |" << endl;
    cout << "\t ------------------------" << endl;
    cout << "Enter the loan option you choose: ";
    cin >> loanopt;
}

void calculateLoan(int principal, int tenure, double rate)
{
    double interest, totaldue, emi;

    interest = (principal * rate * tenure) / 100;
    totaldue = principal + interest;
    emi = totaldue / (tenure * 12);

    cout << "\nYour Loan Receipt:" << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "Loan Type: ";
    if (rate == 12)
        cout << "Home Loan";
    else if (rate == 10)
        cout << "Car Loan";
    else
        cout << "Agriculture Loan";
    cout << endl;
    cout << "\n\t------------   Loan Amount:------------   " << principal << " rs" << endl;
    cout << "\t| Interest Rate: " << rate << "%" << endl;
    cout << "\t| Tenure: " << tenure << " years" << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << "\t| Interest: " << interest << " rs" << endl;
    cout << "\t| Total Amount Due: " << totaldue << " rs" << endl;
    cout << "\t| EMI (Equated Monthly Installment): " << emi << " rs" << endl;
    cout << "-----------------------------------------------------------" << endl;
}


void goBack()
{
    char choice;
    cout << "\n\nWant to go back to the main menu [y/n] : ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y')
        loan();
}
