#include<iostream>

using namespace std;

class RouteStrategy{
public:
    virtual void decideRoute(string source, string destination) = 0; // Pure virtual function
    virtual ~RouteStrategy() {} // Virtual destructor for proper cleanup
};

class BikeRoute : public RouteStrategy{
    public:
     void decideRoute(string source, string destination) override {
        cout << "Deciding route for Bike from " << source << " to " << destination << "." << endl;
     }
};

class CarRoute : public RouteStrategy{
    public:
    void decideRoute(string source, string destination) override {
        cout << "Deciding route for Car from " << source << " to " << destination << "." << endl;
    }
};

class BusRoute : public RouteStrategy{
    public:
    void decideRoute(string source, string destination) override {
        cout << "Deciding route for Bus from " << source << " to " << destination << "." << endl;
    }
};

class RouteContext{
private:
    RouteStrategy *strategy;
public:
    RouteContext(RouteStrategy *s) : strategy(s) {}

    void setStrategy(RouteStrategy *s)
    {
        strategy = s;
    }

    void decideRoute(string source, string destination)
    {
        strategy->decideRoute(source, destination);
    }
};

int main()
{
    // Example usage of RouteContext with different route strategies
    RouteStrategy *bikeRoute = new BikeRoute();
    RouteContext context(bikeRoute);
    context.decideRoute("Delhi", "Noida"); // Using Bike Route

    // Changing strategy to Car
    RouteStrategy *carRoute = new CarRoute();
    context.setStrategy(carRoute);
    context.decideRoute("Delhi", "Gurgaon"); // Using Car Route

    // Changing strategy to Bus
    RouteStrategy *busRoute = new BusRoute();   
    context.setStrategy(busRoute);
    context.decideRoute("Delhi", "Faridabad"); // Using Bus Route

    // Clean up
    delete bikeRoute;   
    delete carRoute;
    delete busRoute;

    return 0;
}