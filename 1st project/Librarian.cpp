#include "Librarian.h"

Librarian::Librarian(std::string name, std::string email, std::string password) {
    this->name = name;
    this->email = email;
    this->password = password;
}

void Librarian::edit_book_id(Book& book, int i) { book.id = i; }

void Librarian::edit_book_author(Book& book, std::string s) { book.author = s; }

void Librarian::edit_book_title(Book& book, std::string t) { book.title = t; }

int Librarian::generateID = 0;

Librarian::~Librarian() {}
