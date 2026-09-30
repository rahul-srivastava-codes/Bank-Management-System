<<<<<<< HEAD
#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Account
{
private:
    string mobilenumber;
    string dob;
    string name;
    string email;
    string aadharNumber;
    string pan;
    double depositAmount;
    string type;

public:
    // Default Constructor
    Account()
        : mobilenumber(""), dob(""), name(""), email(""), aadharNumber(""), pan(""), depositAmount(0.0)
    {
    }

    // Parameterized Constructor
    Account(string mob, const string &d, const string &n, const string &e, string aadhar, string p, double dep)
        : mobilenumber(mob), dob(d), name(n), email(e), aadharNumber(aadhar), pan(p), depositAmount(dep) {}

    // Virtual Destructor (Crucial for base polymorphic classes)
    virtual ~Account() {}

    // Getters (one-liners)
    string getMobileNumber() const { return mobilenumber; }
    string getDob() const { return dob; }
    string getName() const { return name; }
    string getEmail() const { return email; }
    string getAadharNumber() const { return aadharNumber; }
    string getPan() const { return pan; }
    double getDeposit() const { return depositAmount; }
    string getType() const { return type; }

    // Setters (one-liners)
    void setMobileNumber(string mob) { mobilenumber = mob; }
    void setDob(const string &d) { dob = d; }
    void setName(const string &n) { name = n; }
    void setEmail(const string &e) { email = e; }
    void setAadharNumber(string aadhar) { aadharNumber = aadhar; }
    void setPan(string p) { pan = p; }
    void setDeposit(double dep) { depositAmount = dep; }
    void setType(const string &t) { type = t; }
    // void acceptRecord()

    // Pure Virtual Function makes this class genuinely abstract
    virtual void showAccountDetails() const = 0;

    // Common Interface Virtual Methods
    virtual void createAccount()
    {
        cin.ignore(10000, '\n'); // clear buffer from previous cin >>
        cout << "Enter Full Name: ";
        getline(cin, name);
        cout << "Enter Mobile Number: ";
        cin >> mobilenumber;
        cout << "Enter Date of Birth (DD/MM/YYYY): ";
        cin >> dob;
        cout << "Enter Email: ";
        cin >> email;
        cout << "Enter Aadhar Number: ";
        cin >> aadharNumber;
        cout << "Enter PAN Number: ";
        cin >> pan;
        cout << "Enter Initial Deposit Amount: ";
        cin >> depositAmount;
    }
    virtual void deleteAccount()
    {
        if (this->getDeposit() != 0)
        {
            cout << "cash out all money\n";
        }
        else
        {
        }
    }
    virtual void transaction() {}
    virtual void balanceCheck() const {}
    virtual void lastNTransactions(int n) const {}
    virtual void lastNTransactionsByDateRange(const string &fromDate, const string &toDate) const {}
};
=======
class Account
{
};
>>>>>>> 30abdbe82858dbcd41d2b2b13c0dd307e58c857e
