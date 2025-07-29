#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class Cinema
{
private:
    int row;
    int column;
    vector<vector<bool>> seats; // true = booked, false = available

public:
    Cinema(int x, int y) : row(x), column(y)
    {
        seats = vector<vector<bool>>(row, vector<bool>(column, false));
    }

    bool bookSeat(int r, int c)
    {
        if (r < 1 || r > row || c < 1 || c > column)
        {
            cout << "Invalid seat position.\n";
            return false;
        }
        if (seats[r - 1][c - 1])
        {
            cout << "Seat already booked.\n";
            return false;
        }
        seats[r - 1][c - 1] = true;
        cout << "Seat booked successfully.\n";
        return true;
    }

    bool unbookSeat(int r, int c)
    {
        if (r < 1 || r > row || c < 1 || c > column)
        {
            cout << "Invalid seat position.\n";
            return false;
        }
        if (!seats[r - 1][c - 1])
        {
            cout << "Seat is already available.\n";
            return false;
        }
        seats[r - 1][c - 1] = false;
        cout << "Seat unbooked successfully.\n";
        return true;
    }

    bool bookGroup(int r, int count)
    {
        if (r < 1 || r > row || count > column)
        {
            cout << "Invalid input.\n";
            return false;
        }

        for (int i = 0; i <= column - count; ++i)
        {
            bool canBook = true;
            for (int j = 0; j < count; ++j)
            {
                if (seats[r - 1][i + j])
                {
                    canBook = false;
                    break;
                }
            }
            if (canBook)
            {
                for (int j = 0; j < count; ++j)
                {
                    seats[r - 1][i + j] = true;
                }
                cout << "Group seats booked from seat " << i + 1 << " to " << i + count << ".\n";
                return true;
            }
        }

        cout << "No sufficient consecutive seats available in the row.\n";
        return false;
    }

    void display()
    {
        cout << "\nSeating Layout (O = available, X = booked):\n";
        cout << "    ";
        for (int c = 1; c <= column; ++c)
            cout << setw(2) << c;
        cout << "\n";
        for (int r = 0; r < row; ++r)
        {
            cout << "Row " << setw(2) << r + 1 << ": ";
            for (int c = 0; c < column; ++c)
            {
                cout << (seats[r][c] ? " X" : " O");
            }
            cout << "\n";
        }
    }
};

int main()
{
    Cinema cinema(10, 10);
    int choice;

    while (true)
    {
        cout << "\n--- Cinema Hall Seat Reservation System ---\n";
        cout << "1. Book a seat\n";
        cout << "2. Unbook a seat\n";
        cout << "3. Book a group of seats\n";
        cout << "4. Show seating layout\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            int row, seat;
            cout << "Enter row and seat number to book: ";
            cin >> row >> seat;
            cinema.bookSeat(row, seat);
        }
        else if (choice == 2)
        {
            int row, seat;
            cout << "Enter row and seat number to unbook: ";
            cin >> row >> seat;
            cinema.unbookSeat(row, seat);
        }
        else if (choice == 3)
        {
            int row, count;
            cout << "Enter row and number of consecutive seats to book: ";
            cin >> row >> count;
            cinema.bookGroup(row, count);
        }
        else if (choice == 4)
        {
            cinema.display();
        }
        else if (choice == 5)
        {
            cout << "Exiting...\n";
            break;
        }
        else
        {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
