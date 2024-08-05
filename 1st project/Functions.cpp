#include "Functions.h"
string getPassword() {
	std::string password;
	char ch;

	while ((ch = _getch()) != '\r') {
		if (ch == 8) {
			if (!password.empty()) {
				password.pop_back();
				std::cout << "\b \b";
			}
		}
		else {
			password.push_back(ch);
			std::cout << '*';
		}
	}
	std::cout << '\n';
	return password;
}


void initialize_books() {
	books.push_back(Book(1, 2, "Isaac Asimov", "Foundation", "Science Fiction", 4.7));
	books.push_back(Book(2, 3, "Arthur Conan Doyle", "Sherlock Holmes: The Complete Collection", "Mystery", 4.9));
	books.push_back(Book(3, 4, "George R.R. Martin", "A Game of Thrones", "Fantasy", 4.8));
	books.push_back(Book(4, 2, "Douglas Adams", "The Hitchhiker's Guide to the Galaxy", "Science Fiction", 4.6));
	books.push_back(Book(5, 5, "Herman Melville", "Moby Dick", "Classic", 4.4));
}


void login_phase()
{
	int n = 0;
	while (n != 1 and n != 2)
	{
		try
		{
			cin >> n;
			if (n == 1)
			{
				librarian = login<Librarian>();
				phase = 1;
				return;
			}

			else if (n == 2)
			{
				customer = login<Customer>();
				phase = 6;
				return;
			}

			else
			{
				throw "Invalid choice";
			}
		}
		catch (const char* s)
		{
			cout << s << ", please enter either 1 or 2\n";
		}
	}
}

void transition()
{
	cout << "\nEnter 1 to go back to the main menu or 2 to exit: ";
	int choice; cin >> choice;
	if (choice == 1)
	{
		if (customer.get_name() == "")
			phase = 1;
		else
			phase = 6;
	}
	else
		phase = -1;
}

void librarian_options()
{
	cout << "\t\t\t\t\t\t\t\tWelcome, " << librarian.get_name() << "\n\n";
	cout << "\nType 1 to add a book , 2 to remove a book , 3 to edit a book and 4 to view all books: ";
	int choice; cin >> choice;
	phase = choice + 1;
}

void add_book()
{
	Book book;
	cout << "\nEnter id: ";
	int id; cin >> id;
	while (ids.find(id) != ids.end())
	{
		cout << "\nAlready taken id , please enter another one: ";
		cin >> id;
	}
	cout << "\nEnter number of copies: ";
	int num; cin >> num;
	cout << "\nEnter author's name: ";
	cin.ignore();
	string name; getline(cin, name);
	cout << "\nEnter title: ";
	cin.ignore();
	string title; getline(cin, title);
	cout << "\nEnter section: ";
	cin.ignore();
	string section; getline(cin, section);
	cout << "\nEnter rating: ";
	float rate; cin >> rate;
	book.set_details(id, num, name, title, section, rate);
	books.push_back(book);
	ids.insert(id);
	cout << "\nSuccessfuly added!\n";
	transition();
}

void remove_book()
{
	cout << "Enter the id of the book: ";
	int id; cin >> id;
	while (ids.find(id) == ids.end())
	{
		cout << "\nNo book with such id , please try again: ";
		cin >> id;
	}

	ids.erase(id);
	char c;
	for (int i = 0; i < books.size(); ++i)
	{
		if (books[i].get_id() == id)
		{
			books[i].book_details();
			cout << "Are you sure that you want to delete this book ? (y/n): ";
			cin >> c;
			if (c == 'y' or c == 'Y')
			{
				books.erase(books.begin() + i);
			}
			break;
		}
	}
	if(c=='y' or c == 'Y')
		cout << "\nBook removed successfuly!\n";
	transition();
}

void edit_book()
{
	cout << "Enter the id of the book you want to edit: ";
	int n; cin >> n;
	while (ids.find(n) == ids.end())
	{
		cout << "Couldn't find a book with such id , please try again: ";
		cin >> n;
	}
	int choice;
	for (auto& book : books)
	{
		if (book.get_id() == n)
		{
			cout << "1.Edit id\n2.Edit name\n3.Edit author's name\n4.Edit Section\n";
			cin >> choice;
			while (choice < 1 or choice > 4)
			{
				cout << "\nInvalid choice , please choose a number between 1 and 5: ";
				cin >> choice;

				if (choice == 1)
				{
					cout << "Enter the new id: ";
					int id; cin >> id;
					while (ids.find(id) != ids.end())
					{
						cout << "\nThis id is already assigned to another book , please choose another id: ";
						cin >> id;
					}
					book.set_id(id);
				}
				else if (choice == 2)
				{
					cout << "\nEnter the new name: ";
					cin.ignore();
					string name; getline(cin, name);
					book.set_title(name);
				}
				else if (choice == 3)
				{

					cout << "\nEnter author's name: ";
					cin.ignore();
					string name; getline(cin, name);
					book.set_author(name);
				}
				else if (choice == 4)
				{
					cout << "Enter book's section: ";
					cin.ignore();
					string section; cin >> section;
					book.set_section(section);
				}
			}
			break;
		}
	}
	transition();
}

void show_books()
{
	for (int i = 0; i < books.size(); ++i)
	{
		books[i].book_details();
		cout << '\n';
	}
	transition();
}

void customer_options()
{
	cout << "\t\t\t\t\t\t\t\tWelcome, " << customer.get_name() << "\n\n";
	cout << "\nType 1 to search for a book , 2 to return a book , 3 to view borrowed books and 4 to view available books: ";
	int choice; cin >> choice;
	if (choice == 4)
		phase = 5;
	else 
		phase = choice + 6;
}

void search()
{
	cout << "Type 1 if you want to search by id or 2 if you want to search by title: ";
	int choice; cin >> choice;
	if (choice == 1)
	{
		cout << "\nEnter id: ";
		int id; cin >> id;
		int index = customer.search_for_book(id);
		while (index == -1)
		{
			cout << "\nCouldn't find such book , please enter another id: ";
			cin >> id;
			index = customer.search_for_book(id);
		}
		books[index].book_details();
		char c;
		cout << "\nDo you want to borrow this book? (y/n): ";
		cin >> c;
		if (c == 'y' or c == 'Y')
		{
			if (books[index].get_copies())
			{
				cout << "\nSuccessfuly borrowed!\n";
				books[index].set_copies(books[index].get_copies() - 1);
				customer.borrow_a_book(books[index]);
			}
			else
			{
				cout << "\nSorry , there is no enough copies\n";
			}
		}
	}
	else
	{
		cout << "\nEnter title: ";
		cin.ignore();
		string title; getline(cin, title);
		int index = -1;
		while (true)
		{
			for (int i = 0; i < books.size(); ++i)
			{
				if (books[i].get_title() == title)
				{
					index = i;
					break;
				}
			}
			if (~index)
				break;
			cout << "Couldn't find a book with such title , please try again: ";
			cin.ignore();
			getline(cin, title);
		}
		cout << '\n';
		books[index].book_details();
		char c;
		cout << "\nDo you want to borrow this book? (y/n): ";
		cin >> c;
		if (c == 'y' or c == 'Y')
		{
			if (books[index].get_copies())
			{
				cout << "\nSuccessfuly borrowed!\n";
				books[index].set_copies(books[index].get_copies() - 1);
				customer.borrow_a_book(books[index]);
			}
			else
			{
				cout << "\nSorry , there is no enough copies\n";
			}
		}
	}
	transition();
}

void show_borrowed()
{
	customer.show_borrowed_books();
	transition();
}

void return_book()
{
	customer.show_borrowed_books();
	cout << "Enter the id of the book you want to return: ";
	int id; cin >> id;
	vector<Book>search = customer.get_borrowed_books();
	int index = -1;
	while (index == -1) {
		try {
			for (int i = 0; i < search.size(); ++i)
			{
				if (search[i].get_id() == id)
				{
					
					index = i;
					break;
				}
			}
			if (index == -1)
				throw "\nNo such borrowed book with this id , please try again: ";
		}
		catch (const char* s)
		{
			cout << s;
			cin >> id;
		}
	}
	bool found = false;
	for (int i = 0; i < books.size(); ++i)
	{
		if (books[i].get_id() == id)
		{
			books[i].set_copies(books[i].get_copies() + 1);
			found = true;
		}
	}
	if (!found)
		books.push_back(search[index]) , ids.insert(id);
	customer.return_a_book(index);
	cout << "\nBook Returned Successfuly!\n";
	transition();
}