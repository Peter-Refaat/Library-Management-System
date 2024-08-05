#include "User.h"
#include "Globals.h"

User::User() {}

std::string User::get_email() const {
    return email;
}

std::string User::get_name() const {
    return name;
}

std::string User::get_password() const {
    return password;
}

int User::search_for_book(int book_id) const {
    for (int i = 0; i < books.size(); ++i) {
        if (books[i].get_id() == book_id)
            return i;
    }
    return -1;
}

int User::search_for_book(const std::string& book_title) const {
    for (int i = 0; i < books.size() ; ++i) {
        if (books[i].get_title() == book_title)
            return i;
    }
    return -1;
}

User::~User() {}
