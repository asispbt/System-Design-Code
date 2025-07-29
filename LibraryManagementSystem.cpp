#include <iostream>
#include <unordered_map>
#include<string>
using namespace std;

// Assume your class Library is defined above this
class Book{
    public :
        int id;
        string title;
        string author;
        bool isBorrowed;
        string borrower;
        Book();
};

Book :: Book() : id(0), title(""), author(""), isBorrowed(false), borrower(""){}

class Library{
private:
    unordered_map<int, Book> books;

public:
    void addBook(int id, const string& title, const string& author){
        // if bookID already exists
        if(books.find(id)!=books.end()){
            cout<<"Book id : "<<id<<" already exists."<<endl;
            return;
        }

        //add new BookID
        Book newBook;
        newBook.id = id;
        newBook.title = title;
        newBook.author = author;

        books[id] = newBook;
    }

    void borrowBook(int id, const string& user){
        //check if the book id requested is valid or not
        if(books.find(id)==books.end()){
            cout << "Book id : " << id << "doesn't exists" << endl;
            return;
        }

        if (books[id].isBorrowed == true){
            cout << "Invalid : Book id : " << id << "- "<< books[id].title<<" borrowed by " << user <<endl;
            return;
        }

        books[id].isBorrowed = true;
        books[id].borrower = user;
        cout << "Book id: " << id << " " << books[id].title << " is borrowed by " << user << " successfully" << endl;
    }

    void returnBook(int id){
        // check if the book id requested is valid or not
        if (books.find(id) == books.end())
        {
            cout << "Book id : " << id << "doesn't exists" << endl;
            return;
        }

        if (books[id].isBorrowed == false)
        {
            cout << "Book id : " << id << " is not borrowed." << endl;
            return;
        }

        //return book
        if(books[id].isBorrowed == true){
            books[id].isBorrowed = false;
            books[id].borrower = "";
            cout << "Book id " << id << " is returned." << endl;
        }
    }

    void searchByTitle(const string& bookName){
        for(const auto& pair : books){
            if (pair.second.title == bookName)
            {
                cout << "Book : " << bookName << " is availale" << endl;
                return;
            }
        }
        cout << "Book : " << bookName << " is NOT availale in Library" << endl;
    }

    void searchByAuthor(const string& owner){
        for(const auto &pair : books){
            if(pair.second.author == owner){
                cout << "Book : " << pair.second.title << " is availale " <<"written by " <<owner<< endl;
                return;
            }
        }
        cout << "No books availabe with Writter : " <<owner << endl;
    }

    void displayBooks(){
        cout << "Book List in Library\n";
        int count = 0;
        for (const auto &pair: books){
            cout << "Book " << ++count << endl;
            cout << pair.first <<" "<<pair.second.title<<" by "<<pair.second.author<< endl;
        }

        cout << "Total book in Library : " << count << endl;
    }
};

int main()
{
    Library myLibrary;
    Book b;

    // Add books
    myLibrary.addBook(101, "The C++ Programming Language", "Bjarne Stroustrup");
    myLibrary.addBook(102, "Clean Code", "Robert C. Martin");
    myLibrary.addBook(103, "Design Patterns", "Erich Gamma");

    // Borrow books
    myLibrary.borrowBook(101, "Alice");
    myLibrary.borrowBook(102, "Bob");

    // Try borrowing an already borrowed book
    myLibrary.borrowBook(101, "Charlie"); // Should give "already borrowed" message

    // Return a book
    myLibrary.returnBook(101);

    // Try returning an already returned book
    myLibrary.returnBook(101); // Should give error

    // Search by title or author
    myLibrary.searchByTitle("Clean Code");
    myLibrary.searchByAuthor("Erich Gamma");

    // Display current library status
    myLibrary.displayBooks();

    return 0;
}
