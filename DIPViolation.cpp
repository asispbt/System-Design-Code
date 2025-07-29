#include<iostream>

using namespace std;

// DIPViolation.cpp
// This code demonstrates a violation of the Dependency Inversion Principle (DIP)
// by directly depending on concrete classes instead of abstractions.
class MySQLDatabase{
public:
    void saveToSQL(string data){
        cout << "Executing SQL query: INSERT INTO users VALUES { " << data << " }" << endl;
    }
};

// MongoDBDatabase is another concrete class that violates DIP
// because it is directly used in UserService without an abstraction.

class MongoDBDatabase{
public:
    void saveToMongoDB(string data){
        cout<< "Executing MongoDB Function: db.users.insert {{name: "<< data<< "}}"<<endl;
    }
};

// UserService is a class that directly depends on MySQLDatabase and MongoDBDatabase,
// which is a violation of the Dependency Inversion Principle (DIP).

class UserService{
private:
    MySQLDatabase sqldb;  //Direct dependency on MySQLDatabase
    MongoDBDatabase mongodb;  //Direct dependency on MongoDBDatabase
public:
    void storeUserToSQL(string user){
        //MySQL- specific code
        sqldb.saveToSQL(user);
    }

    void storeUserToMongoDB(string user)
    {
        //MongoDB-specific Code
        mongodb.saveToMongoDB(user);
    }
};

// This is a violation of Dependency Inversion Principle (DIP)
// because UserService is tightly coupled with MySQLDatabase and MongoDBDatabase.
// To adhere to DIP, we should introduce abstractions (interfaces) for the databases.

int main()
{
    // Example usage of UserService
    // This will demonstrate the violation of DIP as UserService is tightly coupled with concrete database classes
    UserService service;
    service.storeUserToSQL("Ashish");
    service.storeUserToMongoDB("Punit");
}