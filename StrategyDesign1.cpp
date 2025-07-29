#include <iostream>

using namespace std;

class PaymentStrategy {
    public:
        virtual void pay(int amount) = 0; // Pure virtual function
        ~PaymentStrategy() {} // Virtual destructor for proper cleanup
};

class CreditCardPayment : public PaymentStrategy{
    public:
        void pay(int amount) override{
            cout << "Paid " << amount << " using Credit Card."<<endl;
        }
};

class UpiPayment : public PaymentStrategy{
    public:
        void pay(int amount) override{
            cout << "Paid " << amount << " using UPI."<<endl;
        }
};

class PaymentContext{
    private:
        PaymentStrategy *strategy;
    public:
        PaymentContext(PaymentStrategy *s) : strategy(s){}

        void setStrategy(PaymentStrategy *s)
        {
            strategy = s;
        }

        void payAmount(int amount)
        {
            strategy->pay(amount);
        }
};

int main()
{
    // Example usage of PaymentContext with different payment strategies
    PaymentStrategy *creditCard = new CreditCardPayment();
    PaymentContext context(creditCard);
    context.payAmount(1000); // Using Credit Card

    // Changing strategy to UPI
    PaymentStrategy *upi = new UpiPayment();
    context.setStrategy(upi);
    context.payAmount(2000); // Using UPI

    // Clean up
    delete creditCard;
    delete upi;

    return 0;   
}