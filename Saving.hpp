#pragma once
#include <iostream>
#include <string>
#include "Account.hpp"
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
    Saving(string mob, const string &d, const string &n, const string &e, string aadhar, string p, double dep, int limit = 5)
        : Account(mob, d, n, e, aadhar, p, dep), transactionLimit(limit) {}

    // Getter and Setter
    int getTransactionLimit() const { return transactionLimit; }
    float getInterestRate() const { return interestRate; }

    // Overriding pure virtual function
    void createAccount() override
    {
        Account::createAccount();
    }
    void showAccountDetails() const override
    {
        cout << "[Savings Account] Name: " << getName()
             << " | Balance: " << getDeposit()
             << " | Limit: " << transactionLimit
             << " | Rate: " << interestRate << "%\n";
    }
};
