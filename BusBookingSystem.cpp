#include<iostream>

using namespace std;

class seatAllocate{
private:
    int seat;
    int *p;

public:
    seatAllocate(int x) : seat(x){
        p = new int[x]();
    }

    void allocate(int y){
        if(y > 100 || y==0){
            cout << "Invalid seat number : " <<y<< endl;
        }
        else if(p[y-1] == 1){
            cout << "error : Select another seat. Seat " <<y<< " is already occupied" << endl;
        }else{
            p[y - 1] = 1;
            cout << "Seat " << y << " Allocated" << endl;
        }
    }

    void free(int z){
        if(z > 100 || z == 0){
            cout << "Invalid seat number : " <<z<< endl;
            return;
        }
        
        if(p[z-1] == 1){
            p[z - 1] = 0;
            cout << "Seat " << z << " is freed." << endl;
        }else if(p[z-1] == 0){
            cout << "Error : Seat is already free" << endl;
        }
    }

    void print(){
        for (int i = 0; i < seat; i++){
            if(p[i] == 1){
                int j = i;
                while(p[i+1] == 1){
                    i++;
                }
                if(j!=i)
                    cout << j+1 << "-" << i+1 << ", ";
                else
                    cout << i+1 << ", ";
            }
        }
    }

    void status()
    {
        int allocated = 0;
        for (int i = 0; i < seat; ++i)
            if (p[i] == 1)
                allocated++;
        cout << "\nTotal Allocated: " << allocated << "/" << seat << endl;
    }

    ~seatAllocate()
    {
        delete[] p;
    }
};

int main()
{
    seatAllocate s(100); // 100 seats allocated
    s.allocate(3);       // seat 3 allocated.
    s.allocate(4);       // seat 4 allocated
    s.allocate(3);       // error : Seat 3 occupied
    s.allocate(2);       // seat 2 allocated
    s.allocate(5);   // seat 5 allocated
    s.allocate(35);      // seat 35 allocated
    s.allocate(100);     // seat 100 allocated
    s.allocate(0);       // Invalid seat number
    s.allocate(101);     // invalid seat number
    s.allocate(36);

    s.free(100);     // seat 100 is freed.
    s.allocate(100); // seat 100 is alloacted.

    s.print(); // 2-5, 35, 100

    s.status();

    return 0;
}