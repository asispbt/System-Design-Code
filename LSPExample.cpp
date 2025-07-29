#include <iostream>
#include <vector>

using namespace std;

// This is the solution where we will create two Interface one withdrawableAccout and other nonWithdrawableAccount

// Interface of NonWithdrawableAccount
class NonWithdrawableAccount
{
public:
    virtual void deposit(int amount) = 0;
};

// Interface of WithdrawableAccount which is inheriting deposit() method of NonWithdrawableAccount Interface
class WithdrawableAccount : public NonWithdrawableAccount
{
public:
    virtual void withdraw(int amount) = 0;
};

class SavingAccount : public WithdrawableAccount
{
private:
    int balance;

public:
    SavingAccount(int amount = 0)
    {
        balance = amount;
    }
    void deposit(int amount) override
    {
        balance += amount;
        cout << "Current Balance in Saving Account = " << balance << endl;
    }

    void withdraw(int amount) override
    {
        if (amount > balance)
        {
            cout << "Insufficient Balance in Saving Account " << endl;
            cout << "Current Balance in Saving Account = " << balance << endl;
        }
        else
        {
            balance -= amount;
            cout << "Withdrawn Amount from Saving Account: " << amount << endl;
            cout << "Current Balance in Saving Account= " << balance << endl;
        }
    }
};

class CurrentAccount : public WithdrawableAccount
{
private:
    int balance;

public:
    CurrentAccount(int amount = 0)
    {
        balance = amount;
    }
    void deposit(int amount) override
    {
        balance += amount;
        cout << "Current Balance in Current Account = " << balance << endl;
    }

    void withdraw(int amount) override
    {
        if (amount > balance)
        {
            cout << "Insufficient Balance in Current Account " << endl;
            cout << "Current Balance in Current Account= " << balance << endl;
        }
        else
        {
            balance -= amount;
            cout << "Withdrawn Amount from Current Account : " << amount << endl;
            cout << "Current Balance in Current Account = " << balance << endl;
        }
    }
};

class FixedDepositAccount : public NonWithdrawableAccount
{
private:
    int balance;

public:
    FixedDepositAccount(int amount = 0)
    {
        balance = amount;
    }
    void deposit(int amount) override
    {
        balance += amount;
        cout << "Current Balance in Fixed Deposit= " << balance << endl;
    }
};

//Here client has two option either to choose withdrawAccount or NonWithdrawAccounts, this satifies Liskov Substitution Principle
class Client
{
private:
    vector<WithdrawableAccount *> withdrawAccounts;
    vector<NonWithdrawableAccount *> NonWithdrawableAccounts;

public:
    Client(vector<WithdrawableAccount *> withdrawAcc, vector<NonWithdrawableAccount *> NonWithdrawAcc)
    {
        withdrawAccounts = withdrawAcc;
        NonWithdrawableAccounts = NonWithdrawAcc;
    }

    void processTransaction()
    {
        for(auto *acc : withdrawAccounts){
            acc->deposit(1000);
            acc->withdraw(600);
        }

        for(auto *acc : NonWithdrawableAccounts){
            acc->deposit(2000);
        }
    }
};

int main()
{
    vector<WithdrawableAccount *> acc;
    acc.push_back(new SavingAccount());
    acc.push_back(new CurrentAccount());

    vector<NonWithdrawableAccount *> fd;
    fd.push_back(new FixedDepositAccount());

    Client *client = new Client(acc, fd);
    client->processTransaction();
}
