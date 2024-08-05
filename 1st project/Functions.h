#pragma once
#include <iostream>
#include <string>
#include <conio.h>
#include "Book.h"
#include "Globals.h"
#include "Customer.h"
#include "Librarian.h"
using namespace std;
std::string getPassword();

template<class T>
T login() //sign-in & sign-up
{
    std::string name, email, password;
    std::cout << "Name: ";
    std::cin >> name;
    std::cout << "E-Mail: ";
    std::cin >> email;
    std::cout << "Password: ";
    password = getPassword();
    if constexpr (std::is_same_v<T, Librarian>) 
    {
        return T(name, email, password);
    }
    else if constexpr (std::is_same_v<T, Customer>) 
    {
        return T(name, email, password);
    }
}

void initialize_books();

void login_phase();


void transition();

void librarian_options();


void add_book();

void remove_book();

void edit_book();

void show_books();

void customer_options();

void show_borrowed();

void search();

void return_book();