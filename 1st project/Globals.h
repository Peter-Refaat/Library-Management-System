#pragma once
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include "Book.h"
#include "Librarian.h"
#include "Customer.h"
extern std::vector<Book> books;
extern std::map<int, float> bookAvgRating;
extern std::set<int>ids;
extern Librarian librarian;
extern Customer customer;
extern int phase;
