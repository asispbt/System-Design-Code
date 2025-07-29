#include <iostream>

using namespace std;

//Abstraction for Database
// This is a pure virtual class that defines the interface for database operations.
class Database{
public:
    virtual void save(string data) = 0; // Pure virtual function
};

// MySQLDatabase and MongoDBDatabase now inherit from the Database abstraction
// This allows UserService to depend on the abstraction instead of concrete implementations.
class MySQLDatabase : public Database
{
public:
    void save(string data) override
    {
        cout << "Executing SQL query: INSERT INTO users VALUES { " << data << " }" << endl;
    }
};

// MongoDBDatabase is another concrete class that implements the Database interface.
// This allows UserService to use MongoDBDatabase without being tightly coupled to it.
class MongoDBDatabase : public Database
{
public:
    void save(string data) override
    {
        cout << "Executing MongoDB Function: db.users.insert {{name: " << data << "}}" << endl;
    }
};


// UserService now depends on the Database abstraction instead of concrete classes.
// This adheres to the Dependency Inversion Principle (DIP) by depending on abstractions
// rather than concrete implementations.

class UserService
{
private:
    Database* db; // Pointer to the abstract Database class
public:
    UserService(Database* database) : db(database) {}

    void storeUser(string user)
    {
        db->save(user);
    }
};

int main()
{
    // Example usage of UserService with MySQLDatabase
    // and MongoDBDatabase, demonstrating adherence to the Dependency Inversion Principle (DIP).
    // UserService can now work with any class that implements the Database interface.
    // This allows for flexibility and easier testing, as we can swap out database implementations without changing UserService.
    MySQLDatabase mysql;
    UserService userService(&mysql);
    userService.storeUser("Ashish");

    MongoDBDatabase mongodb;
    UserService userService2(&mongodb);
    userService2.storeUser("Punit");

    return 0;
}