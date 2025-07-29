#include <iostream>
#include <cstdint>

using namespace std;

class seatAllocate
{
private:
    int seat;
    uint64_t *p;

public:
    seatAllocate(int x) : seat(x)
    {
        int y = (x + 64) / 64; // total array index required.
        p = new uint64_t[y](); // () this will initialize the array with value 0
    }

    //allocate seat
    void allocate(int y)
    {
        int index = (y - 1) / 64;
        int set = (y - 1) % 64;

        if (y > seat || y == 0)
        {
            cout << "Invalid seat number : " << y << endl;
            
        }
        else if (p[index] & (1ULL << set))
        {
            cout << "error : Select another seat. Seat " << y << " is already occupied" << endl;
        }
        else
        {
            p[index] = p[index] | (1ULL << set);
            cout << "Seat " << y << " Allocated" << endl;
        }
    }

    void free(int z)
    {
        int index = (z - 1) / 64;
        int set = (z - 1) % 64;

        if (z > 100 || z == 0)
        {
            cout << "Invalid seat number : " << z << endl;
            return;
        }

        //if set i.e. allocated
        if (p[index] & (1ULL << set))
        {
            //free it
            p[index] = p[index] ^ (1ULL << set);
            cout << "Seat " << z << " is freed." << endl;
        }
        else if (!(p[index] & (1ULL << set)))
        {
            cout << "Error : Seat is already free" << endl;
        }
    }

    void print()
    {
        static int count;
        for (int i = 0; i < seat; i++)
        {
            int index = i / 64;
            int set = i % 64;
            if (p[index] & (1 << set))
            {
                cout << i + 1 << " ";
                count++;
            }
        }

        cout << "\nTotal " << count << " seats occupied.";
    }

    ~seatAllocate()
    {
        delete[] p;
    }
};

int main()
{
    seatAllocate s(100); // 100 seats allocated
    s.allocate(0);
    s.allocate(3);
    s.allocate(3);   // seat 3 allocated.
    s.allocate(4);   // seat 4 allocated
    s.allocate(3);   // error : Seat 3 occupied
    s.allocate(2);   // seat 2 allocated
    s.allocate(5);   // seat 5 allocated
    s.allocate(35);  // seat 35 allocated
    s.allocate(100); // seat 100 allocated
    s.allocate(0);   // Invalid seat number
    s.allocate(101); // invalid seat number
    s.allocate(36);

    s.free(100);     // seat 100 is freed.
    s.allocate(100); // seat 100 is alloacted.

    s.print(); // 2-5, 35, 100

    // s.status();

    return 0;
}