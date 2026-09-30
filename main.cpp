#include <iostream>
#include <string>
#include <fstream>
#include "Account.hpp"
#include "Checking.hpp"
#include "Saving.hpp"
using namespace std;

// Base Abstract Class

void deleteAccount()
{
    string accountNumber;
    fstream account("accountBook.txt", ios::out);
    fstream transaction("transactionBook.txt", ios::out);
    cout << "Enter the account number which you want to delete: ";
    cin >> accountNumber;
}

int main()
{
    fstream account("accountBook.txt", ios::out | ios::app);
    fstream transaction("transactionBook.txt", ios::out | ios::app);

    int choice = 0;
    Account *acc = nullptr;

    cout << "------------------------------------------\n";
    cout << "------------ Welcome to Bank -------------\n";
    cout << "------------------------------------------\n";

    do
    {
        cout << "\n================ Main Menu ================\n";
        cout << "1) Add account (Savings / Checking)\n";
        cout << "2) Delete account\n";
        cout << "3) Make transaction (Cash / Cheque)\n";
        cout << "4) Query balance of an account\n";
        cout << "5) List transactions of an account (Date range / Last 'n')\n";
        cout << "6) Save & restore\n";
        cout << "7) Exit\n";
        cout << "===========================================\n";
        cout << "Enter your choice (1-7): ";

        if (!(cin >> choice))
        {
            cout << "Invalid input! Please enter a number.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        switch (choice)
        {
        case 1:
            cout << "\nAdd account selected.\n";
            int option;
            cout << "Type of account you want to create: \n";
            cout << "1.Saving account\n2.Checking Account\n";
            cin >> option;
            acc = nullptr;
            switch (option)
            {
            case 1:
            {
                acc = new Saving();
                break;
            }
            case 2:
            {
                acc = new Checking();
                break;
            }
            default:
                cout << "Invalid type";
                break;
            }
            if (acc != nullptr)
            {
                acc->createAccount();
                cout << "\nAccount created successfully!\n";

                // Write all common fields separated by commas
                account << acc->getType() << ","
                        << acc->getName() << ","
                        << acc->getMobileNumber() << ","
                        << acc->getDob() << ","
                        << acc->getEmail() << ","
                        << acc->getAadharNumber() << ","
                        << acc->getPan() << ","
                        << acc->getDeposit();

                // Write specific fields based on derived account type
                if (Saving *s = dynamic_cast<Saving *>(acc))
                {
                    account << "," << s->getTransactionLimit()
                            << "," << s->getInterestRate() << "\n";
                }
                else if (Checking *c = dynamic_cast<Checking *>(acc))
                {
                    account << "," << c->getGst() << "\n";
                }

                account.flush(); // Ensure data is immediately written to disk
                acc->showAccountDetails();
            }
            // TODO: Call your addAccount() function here
            break;

        case 2:
            cout << "\nDelete account selected.\n";
            deleteAccount();

            // TODO: Call your deleteAccount() function here
            break;

        case 3:
            cout << "\nMake transaction selected.\n";
            // TODO: Call your makeTransaction() function here
            break;

        case 4:
            cout << "\nQuery balance selected.\n";
            // TODO: Call your queryBalance() function here
            break;

        case 5:
            int n;
            cout << "Enter the last n transaction you want: ";
            cin >> n;
            cout << "\nList transactions selected.\n";
            // TODO: Call your listTransactions() function here
            break;

        case 6:
            cout << "\nSave & Restore selected.\n";
            // TODO: Call your saveAndRestore() function here
            break;

        case 7:
            cout << "\nExiting... Thank you for using Bank System!\n";
            exit(0);
            break;

        default:
            cout << "\nInvalid choice! Please select an option between 1 and 7.\n";
            break;
        }

    } while (choice != 7);
    return 0;
}
