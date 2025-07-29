#include <iostream>
#include <vector>
#include <iomanip>

// Violating SRP example
using namespace std;

class Product
{
public:
    string name;
    float price;

    Product(string s = "", float p = 0) : name(s), price(p) {}
};

// ShoppingCart "has a" Product
// Shopping Cart is handling one responsiblities : Following SRP
class ShoppingCart
{
private:
    vector<Product *> products;

public:
    // Adding product to cart
    void addProducts(Product *p)
    {
        products.push_back(p);
    }

    // get product
    vector<Product *> getProduct()
    {
        return products;
    }

    // calculate total price in cart
    float calculatePrice()
    {
        float total;
        for (auto items : products)
        {
            total += items->price;
        }
        return total;
    }
};

class Invoice
{
private:
    ShoppingCart *cart;

public:
    // Print Invoice :
    Invoice(ShoppingCart *c)
    {
        cart = c;
    }
    void printInvoice()
    {
        cout << "Invoice" << endl;
        cout << left << setw(15) << "Item Name" << right << setw(10) << "Price" << endl;
        cout << "-----------------------------" << endl;
        for (auto items : cart->getProduct())
        {
            cout << left << setw(10) << items->name << right << setw(10) << fixed << setprecision(2) << "Rs " << items->price << endl;
        }
        cout << "-----------------------------" << endl;
        cout << left << setw(15) << "Total:" << right << setw(10) << fixed << setprecision(2) << cart->calculatePrice() << endl;
    }
};

// Created Database Interface where save() method is declared but we will 
//extend this feature for calling different ways of adding to DB
class Database
{
    ShoppingCart *cart;

public:
    // Save to Database
    virtual void save() = 0;
};

class SaveSQL : public Database{
public:
    void save() override{
        cout << "Save via SQL" << endl;
    }
};

class SaveMongoDB : public Database
{
public:
    void save() override
    {
        cout << "Save via MongoDB" << endl;
    }
};

class SaveFile : public Database
{
public:
    void save() override
    {
        cout << "Save via File" << endl;
    }
};

int main()
{
    ShoppingCart *cart = new ShoppingCart();
    cart->addProducts(new Product("Shirt", 100.0));
    cart->addProducts(new Product("Cup", 55.50));
    cart->addProducts(new Product("Mouse", 650.0));

    // cart->getProduct();
    // cart->calculatePrice();

    // Invoice *iv = new Invoice(cart);
    // iv->printInvoice();

    Database *db = new SaveSQL();
    db->save();

    Database *dmb = new SaveMongoDB();
    dmb->save();

    Database *dfb = new SaveFile();
    dfb->save();
}
