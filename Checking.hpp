#pragma once
#include <iostream>
#include <string>
#include "Account.hpp"

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
    Checking(string mob, const string &d, const string &n, const string &e, string aadhar, string p, double dep, const string &gstNumber)
        : Account(mob, d, n, e, aadhar, p, dep), gst(gstNumber) {}

    // Getter and Setter
    string getGst() const { return gst; }
    void setGst(const string &gstNumber) { gst = gstNumber; }

    // Overriding pure virtual function
    void createAccount() override
    {
        Account::createAccount();

        cout << "Enter the gst number: ";
        cin >> this->gst;
    }
    void showAccountDetails() const override
    {
        cout << "[Checking Account] Name: " << getName() << " | Balance: " << getDeposit() << " | GST: " << gst << "\n";
    }
};