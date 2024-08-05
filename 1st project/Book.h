#pragma once
#include<iostream>
class Book {
private:
	int id, copies;
	std::string author, title, section;
	float rating;
public:
	Book(int id = 0, int copies = 0, std::string author = "", std::string title = "", std::string section = "", float rating = 0);
	void book_details();
	int get_id();
	int get_copies();
	std::string get_author();
	std::string get_title();
	std::string get_section();
	float get_rating();
	void set_id(int id);
	void set_copies(int copies);
	void set_author(std::string author);
	void set_title(std::string title);
	void set_section(std::string section);
	void set_rating(float rate);
	void set_details(int id, int copies, std::string author, std::string title, std::string section, float rating);
	friend class Librarian;
	friend class Customer;
};
