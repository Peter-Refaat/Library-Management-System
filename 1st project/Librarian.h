#pragma once
#include "User.h"
#include "Book.h"

class Librarian : public User {
private:
    static int generateID;
public:
    Librarian(std::string name, std::string email, std::string password);
    void edit_book_id(Book& book, int i);
    void edit_book_author(Book& book, std::string s);
    void edit_book_title(Book& book, std::string t);
    ~Librarian();
};
