#pragma once
#include <string>
#include <vector>
#include "Book.h" // Include only if necessary

class User {
protected:
    std::string name, email, password;
public:
    User();
    std::string get_name() const;
    std::string get_email() const;
    std::string get_password() const;
    int search_for_book(int book_id) const;
    int search_for_book(const std::string& book_title) const;
    virtual ~User();
};
