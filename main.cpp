#include <iostream>
#include <string>
using namespace std;

// Base Abstract Class
class Account
{
private:
    long mobilenumber;
    string dob;
    string name;
    string email;
    int aadharNumber;
    long pan;
    double depositAmount;
    string type;

public:
    // Default Constructor
    Account()
        : mobilenumber(0), dob(""), name(""), email(""), aadharNumber(0), pan(0), depositAmount(0.0), type(type) {}

    // Parameterized Constructor
    Account(long mob, const string &d, const string &n, const string &e, int aadhar, long p, double dep, const string &t)
        : mobilenumber(mob), dob(d), name(n), email(e), aadharNumber(aadhar), pan(p), depositAmount(dep), type(t) {}

    // Virtual Destructor (Crucial for base polymorphic classes)
    virtual ~Account() {}

    // Getters (one-liners)
    long getMobileNumber() const { return mobilenumber; }
    string getDob() const { return dob; }
    string getName() const { return name; }
    string getEmail() const { return email; }
    int getAadharNumber() const { return aadharNumber; }
    long getPan() const { return pan; }
    double getDeposit() const { return depositAmount; }
    string getType() const { return type; }

    // Setters (one-liners)
    void setMobileNumber(long mob) { mobilenumber = mob; }
    void setDob(const string &d) { dob = d; }
    void setName(const string &n) { name = n; }
    void setEmail(const string &e) { email = e; }
    void setAadharNumber(int aadhar) { aadharNumber = aadhar; }
    void setPan(long p) { pan = p; }
    void setDeposit(double dep) { depositAmount = dep; }
    void setType(const string &t) { type = t; }

    // Pure Virtual Function makes this class genuinely abstract
    virtual void showAccountDetails() const = 0;

    // Common Interface Virtual Methods
    virtual void createAccount(string type) {}
    virtual void deleteAccount() {}
    virtual void transaction() {}
    virtual void balanceCheck() const {}
    virtual void lastNTransactions(int n) const {}
    virtual void lastNTransactionsByDateRange(const string &fromDate, const string &toDate) const {}
};

// Derived Class: Saving
class Saving : public Account
{
private:
    int transactionLimit;
    const float interestRate = 4.0f; // 4.0%

public:
    // Default Constructor
    Saving() : Account(), transactionLimit(5)
    {
        setType("Savings");
    }

    // Parameterized Constructor with Base Chaining
    Saving(long mob, const string &d, const string &n, const string &e, int aadhar, long p, double dep, int limit = 5)
        : Account(mob, d, n, e, aadhar, p, dep, "Savings"), transactionLimit(limit) {}

    // Getter and Setter
    int getTransactionLimit() const { return transactionLimit; }
    float getInterestRate() const { return interestRate; }
    void setTransactionLimit(int limit) { transactionLimit = limit; }

    // Overriding pure virtual function
    void showAccountDetails() const override
    {
        cout << "[Savings Account] Name: " << getName()
             << " | Balance: " << getDeposit()
             << " | Limit: " << transactionLimit
             << " | Rate: " << interestRate << "%\n";
    }
};

// Derived Class: Checking
class Checking : public Account
{
private:
    string gst;

public:
    // Default Constructor
    Checking() : Account(), gst("")
    {
        setType("Checking");
    }

    // Parameterized Constructor with Base Chaining
    Checking(long mob, const string &d, const string &n, const string &e, int aadhar, long p, double dep, const string &gstNumber)
        : Account(mob, d, n, e, aadhar, p, dep, "Checking"), gst(gstNumber) {}

    // Getter and Setter
    string getGst() const { return gst; }
    void setGst(const string &gstNumber) { gst = gstNumber; }

    // Overriding pure virtual function
    void showAccountDetails() const override
    {
        cout << "[Checking Account] Name: " << getName() << " | Balance: " << getDeposit() << " | GST: " << gst << "\n";
    }
};
void accountType()
{
}

int main()
{
    int choice = 0;
    Account *acc;

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
            cout << "\n[Action] Add account selected.\n";
            int option;
            cout << "Type of account you want to create: ";
            cin >> option;
            cout << "1.Saving account\n2.Checking Account\n";
            switch (option)
            {
            case 1:
                acc = new Saving();
                break;
            case 2:
                acc = new Checking();
                break;
            default:
                cout << "Invalid type";
                break;
            }

            // TODO: Call your addAccount() function here
            break;

        case 2:
            cout << "\n[Action] Delete account selected.\n";
            // TODO: Call your deleteAccount() function here
            break;

        case 3:
            cout << "\n[Action] Make transaction selected.\n";
            // TODO: Call your makeTransaction() function here
            break;

        case 4:
            cout << "\n[Action] Query balance selected.\n";
            // TODO: Call your queryBalance() function here
            break;

        case 5:
            cout << "\n[Action] List transactions selected.\n";
            // TODO: Call your listTransactions() function here
            break;

        case 6:
            cout << "\n[Action] Save & Restore selected.\n";
            // TODO: Call your saveAndRestore() function here
            break;

        case 7:
            cout << "\nExiting... Thank you for using Bank System!\n";
            exit();
            break;

        default:
            cout << "\nInvalid choice! Please select an option between 1 and 7.\n";
            break;
        }

    } while (choice != 7);

    return 0;
}
