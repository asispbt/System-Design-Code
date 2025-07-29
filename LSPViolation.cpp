#include<iostream>
#include<vector>

using namespace std;

//This is problem statement where Client is trying to withdraw money from FD account which is not right 
//We are using exception handling to tackle that, but this is not right practise

//Interface of Account
class Account{
public:
    virtual void deposit(int amount) = 0;
    virtual void withdraw(int amount) = 0;
};

class SavingAccount : public Account{
private:
    int balance;

public:
    SavingAccount(int amount = 0){
        balance = amount;
    }
    void deposit(int amount) override{
        balance += amount;
        cout << "Current Balance = " << balance << endl;
    }

    void withdraw(int amount) override{
        if(amount > balance)
        {
            cout << "Insufficient Balance" << endl;
            cout << "Current Balance = " << balance << endl;
        }else{
            balance -= amount;
            cout << "Current Balance = " << balance << endl;
        }
    }
};

class CurrentAccount : public Account{
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
        cout << "Current Balance = " << balance << endl;
    }

    void withdraw(int amount) override
    {
        if (amount > balance)
        {
            cout << "Insufficient Balance" << endl;
            cout << "Current Balance = " << balance << endl;
        }
        else
        {
            balance -= amount;
            cout << "Current Balance = " << balance << endl;
        }
    }
};

class FixedDepositAccount : public Account{
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
        cout << "Current Balance = " << balance << endl;
    }

    void withdraw(int amount) override
    {
        throw logic_error("Amount cannot be withdrawn from Fixed Deposit Account");
    }
};

class Client{
private:
    vector<Account*> accounts;

public:
    Client(vector<Account*> accounts){
        this->accounts = accounts;
    }

    void processTransaction(){
        for(auto *acc : accounts){
            acc->deposit(1000);

            try{
                acc->withdraw(500);
            }
            catch(const logic_error &e){
                cout << "Exception " << e.what() << endl;
            }
        }
    }
};

int main()
{
    vector<Account *> acc;
    acc.push_back(new SavingAccount());
    acc.push_back(new CurrentAccount());
    acc.push_back(new FixedDepositAccount());

    Client *client = new Client(acc);
    client->processTransaction();
}















































































































