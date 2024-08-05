#pragma once
#include "User.h"
#include "Book.h"

class Customer : public User {
private:
    std::vector<Book>borrowedBooks;
public:
    Customer(std::string name, std::string email, std::string password);
    void rate_book(Book& book, float rate);
    void show_borrowed_books();
    std::vector<Book> get_borrowed_books();
    void return_a_book(int id);
    void borrow_a_book(Book book);
    ~Customer();
};
