#include "Library.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

void Library::displayBooks() const{
    if(books.empty()){
        std:: cout << "Library is empty."<< std::endl;
        return;
    }
    for(const Book& book : books){
        book.display();
    }
}

void Library::addBook(const Book& book){
    books.push_back(book);
}

void Library::searchBook(const std:: string& title) const{
    for( const Book& book : books){
        if(book.get_Title() == title){
            book.display();
            return;
        }
    }
}

void Library::borrowBook(const std::string& title){
    for(Book& book: books){
        if(book.get_Title() == title){
            if(book.isBorrowed()){
                std:: cout << "Book is already borrowed." << std::endl;
            }
            else{
                book.borrowBook();
                std::cout << "Book borrowed."<< std::endl;
            }
            return;
        }
       
    }
    std::cout << "Book not found."<<std::endl;
}

void Library::returnBook(const std::string& title){
    for(Book& book : books){
        if(book.get_Title()== title){
            if(book.isBorrowed()){
                book.returnBook();
                std:: cout << "Book returned."<< std:: endl;
            }
            else{
                std:: cout<<"Book wasn't borrowed." << std:: endl;
            }

            return;
        }
    }
    std:: cout << "Book not found." << std:: endl;
}

void Library::saveBooks(const std::string& filename) const{
    std::ofstream file(filename);

    if(!file){
        std::cout << "Could not open file" << std::endl;
        return;
    }

    for(const Book& book : books){
        file << book.get_Title() << "|"
             << book.get_Author() << "|"
             << book.get_year() << "|"
             << book.isBorrowed()
             << std::endl;
    }
    file.close();
}

void Library::loadBooks(const std::string& filename){
    std::ifstream file(filename);

    if(!file){
        std::cout << "No saved library found." <<std::endl;
        return;
    }
    books.clear();

    std:: string line;

    while( std::getline(file, line)){
        std::stringstream ss(line);

        std::string title;
        std::string author;
        std::string yearString;
        std::string borrowedString;

        std::getline(ss, title, '|');
        std::getline(ss, author, '|');
        std::getline(ss, yearString, '|');
        std::getline(ss, borrowedString);

        int year = std::stoi(yearString);
        bool borrowed = std::stoi(borrowedString);

        books.push_back(Book(title,author,year,borrowed));
    }

    file.close();
}




