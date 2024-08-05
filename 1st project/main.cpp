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
/*
phases:
        0.login phase (done)
        1.librarian options (add book , remove book , view books)
        2.add book (done)
        3.remove book (done)
        4.edit book details (done)
        5.view books (done)
        6.customer options (borrow book , return book , rate book , search for book (by id or name) , view books , view borrowed books (done)
        7.search for a book (done)
        8. return book (done)
        9.show borrowed books (done)
        10. borrow book (done)
        11. rate book (borrowed or not)

*/

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
