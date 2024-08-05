#include "Book.h"
using namespace std;
Book::Book(int id, int copies, string author, string title, string section, float rating) :
	id(id), copies(copies), author(author), title(title), section(section), rating(rating) {}

void Book::book_details()
{
	cout << "Book Title : " << title << '\n' << "Book Author : " << author << '\n'
		<< "Book ID : " << id << '\n' << "Book Section : " << section << '\n'
		<< "Book Available Copies : " << copies << '\n';
}

int Book::get_id()
{
	return id;
}

int Book::get_copies()
{
	return copies;
}

string Book::get_author()
{
	return author;
}

string Book::get_title()
{
	return title;
}

string Book::get_section()
{
	return section;
}

float Book::get_rating()
{
	return rating;
}

void Book::set_id(int id) { this->id = id; }
void Book::set_copies(int copies) { this->copies = copies; }
void Book::set_author(string author) { this->author = author; }
void Book::set_title(string title) { this->title = title; }
void Book::set_section(string section) { this->section = section; }
void Book::set_rating(float rate) { this->rating = rate; }
void Book::set_details(int id, int copies, string author, string title, string section, float rating)
{
	this->id = id;
	this->copies = copies;
	this->author = author;
	this->title = title;
	this->section = section;
	this->rating = rating;
}