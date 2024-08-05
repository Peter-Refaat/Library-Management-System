#include "Customer.h"
#include "Globals.h"

Customer::Customer(std::string name, std::string email, std::string password) {
    this->name = name;
    this->email = email;
    this->password = password;
    this->borrowedBooks = {
        Book(7, 1, "George Orwell", "1984", "Dystopian", 4.8),
        Book(10, 1, "J.K. Rowling", "Harry Potter and the Philosopher's Stone", "Fantasy", 4.9),
        Book(21, 1, "J.R.R. Tolkien", "The Hobbit", "Fantasy", 4.7),
        Book(11, 1, "Harper Lee", "To Kill a Mockingbird", "Fiction", 4.6),
        Book(15, 1, "F. Scott Fitzgerald", "The Great Gatsby", "Classic", 4.5)
    };
}

void Customer::rate_book(Book& book, float rate) {
    bookAvgRating[book.get_id()] = (bookAvgRating[book.get_id()] + rate) / 2.0;
}

void Customer::show_borrowed_books()
{
    for (auto& book : borrowedBooks)
    {
        std::cout << "Book Title : " << book.title << '\n' << "Book Author : " << book.author << '\n'
            << "Book ID : " << book.id << '\n' << "Book Section : " << book.section << "\n\n";
    }
}

std::vector<Book> Customer::get_borrowed_books()
{
    return borrowedBooks;
}

void Customer::return_a_book(int index)
{
    borrowedBooks.erase(borrowedBooks.begin() + index);
}

void Customer::borrow_a_book(Book book)
{
    borrowedBooks.push_back(book);
}

Customer::~Customer() {}
