#include <iostream>
#include <vector>
#include <map>
#include <conio.h>
#include "Book.h"
#include "User.h"
#include "Librarian.h"
#include "Customer.h"
#include "Globals.h"
#include "Functions.h"
using namespace std;
int main() 
{
    initialize_books();
    cout << "\t\t\t\t\t\t\tWelcome To Library Management System!\n";
    cout << "Type 1 if you are a Librarian or 2 if you are a customer: ";

    while (~phase)
    {
        while (!phase)
            login_phase();
        while (phase == 1)
            librarian_options();
        while (phase == 2)
            add_book();
        while (phase == 3)
            remove_book();
        while (phase == 4)
            edit_book();
        while (phase == 5)
            show_books();
        while (phase == 6)
            customer_options();
        while (phase == 7)
            search();
        while (phase == 8)
            return_book();
        while (phase == 9)
            show_borrowed();
    }
}
