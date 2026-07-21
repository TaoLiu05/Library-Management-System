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
        std::cout <<"3. Remove Book" <<std::endl;
        std::cout <<"4. Search Book"<< std::endl;
        std::cout <<"5. Borrow Book"<< std::endl;
        std::cout <<"6. Return Book"<< std::endl;
        std::cout <<"7. Save and Exit"<< std::endl;

        while(true){
            std::cout << std::endl << "Enter your choice: ";

            if(!(std::cin >> choice)){
                std::cout << "Please enter a number.";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                continue;
            }
            if(choice < 1 || choice > 7){
                std::cout << "Choose a number between 1 and 7.";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                continue;
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            break;
        }

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
                while(true){
                    if(!(std::cin >> year)){
                        std::cout << "Please enter a valid year: ";
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                        continue;
                    }
                    if(year < 1400 || year > 2100){
                        std::cout <<"Year must be between 1400 and 2100: ";
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                        continue;
                    }

                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                    break;
                }

                if(lib.addBook(Book(title, author, year))){
                    lib.saveBooks(file_name);
                    std::cout <<"Book added!" << std::endl;
                }
                break;
            }

            case 3:{
                std:: string title;

                std:: cout << "Enter title: ";
                std::getline(std::cin, title);

                lib.removeBook(title);
                lib.saveBooks(file_name);

                break;
            }

            case 4:{
                std::string title;

                std::cout <<"Enter title: ";
                std::getline(std::cin, title);

                lib.searchBook(title);

                break;
            }

            case 5:{
                std::string title;

                std::cout <<"Enter title: ";
                std::getline(std::cin, title);

                lib.borrowBook(title);
                lib.saveBooks(file_name);

                break;
            }

            case 6:{
                std::string title;

                std::cout << "Enter title: ";
                std::getline(std::cin, title);

                lib.returnBook(title);
                lib.saveBooks(file_name);

                break;
            }

            case 7:{
                lib.saveBooks(file_name);
                std::cout <<"Library saved."<< std::endl;
                break;
            }

            default:{
                std::cout <<"Invalid choice."<<std::endl;;
            }
        }

    } while(choice != 7);

    return 0;
}
