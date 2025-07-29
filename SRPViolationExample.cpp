#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class Product
{
public:
    string name;
    float price;

    Product(string s = "", float p = 0) : name(s), price(p) {}
};

// ShoppingCart "has a" Product
// Shopping Cart is handling multiple responsiblities
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

    // Print Invoice  : Violating SRP
    void printInvoice()
    {
        cout << "Invoice" << endl;
        cout << left << setw(15) << "Item Name" << right << setw(10) << "Price" << endl;
        cout << "-----------------------------" << endl;
        for (auto items : products)
        {
            cout << left << setw(10) << items->name << right << setw(10) << fixed << setprecision(2) << "Rs " << items->price << endl;
        }
        cout << "-----------------------------" << endl;
        cout << left << setw(15) << "Total:" << right << setw(10) << fixed << setprecision(2) << calculatePrice() << endl;
    }

    // Save to Database : Violating SRP
    void saveToDB()
    {
        cout << "Shopping Cart saved to DB" << endl;
        for (auto items : products)
        {
            cout << left << setw(10) << items->name << right << setw(10) << fixed << setprecision(2) << "Rs " << items->price << endl;
        }
    }
};

int main()
{
    ShoppingCart *cart = new ShoppingCart();
    cart->addProducts(new Product("Shirt", 100.0));
    cart->addProducts(new Product("Cup", 55.50));
    cart->addProducts(new Product("Mouse", 650.0));

    cart->getProduct();
    cart->calculatePrice();
    cart->printInvoice();
    cart->saveToDB();
}