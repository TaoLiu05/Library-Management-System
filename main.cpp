#include "Library.hpp"
#include <iostream>
#include <limits>

const std::string file_name = "books.txt";

int main(){
    Library lib;

    lib.loadBooks(file_name);

    int choice;

    do
    {
        std::cout << std::endl<< "======= Library Management System ======="<<std::endl;
        std::cout <<"1. Display Books"<< std::endl;
        std::cout <<"2. Add Book"<< std::endl;
        std::cout <<"3. Search Book"<< std::endl;
        std::cout <<"4. Borrow Book"<< std::endl;
        std::cout <<"5. Return Book"<< std::endl;
        std::cout <<"6. Save and Exit"<< std::endl;

        std::cout << std::endl << "Enter your choice: ";
        std::cin >> choice;

        std:: cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch(choice){

            case 1:{
                lib.displayBooks();
                break;
            }

            case 2:{
                std::string title;
                std::string author;
                int year;

                std::cout << "Title: ";
                std::getline(std::cin, title);

                std::cout << "Author: ";
                std::getline( std::cin, author);

                std::cout << "Year: ";
                std::cin >> year;

                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                lib.addBook(Book(title, author, year));
                lib.saveBooks(file_name);

                std::cout <<"Book added!" << std::endl;
                break;
            }

            case 3:{
                std::string title;

                std::cout <<"Enter title: ";
                std::getline(std::cin, title);

                lib.searchBook(title);

                break;
            }

            case 4:{
                std::string title;

                std::cout <<"Enter title: ";
                std::getline(std::cin, title);

                lib.borrowBook(title);
                lib.saveBooks(file_name);

                break;
            }

            case 5:{
                std::string title;

                std::cout << "Enter title: ";
                std::getline(std::cin, title);

                lib.returnBook(title);
                lib.saveBooks(file_name);

                break;
            }

            case 6:{
                lib.saveBooks(file_name);
                std::cout <<"Library saved."<< std::endl;
                break;
            }

            default:{
                std::cout <<"Invalid choice."<<std::endl;;
            }
        }

    } while(choice != 6);

    return 0;
}
