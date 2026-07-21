#include "Library.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cctype>

/*
toLower function:
-Loop through every char in a str (char& is used instead of char) because this allows you to change the actual character inside the string
-std::tolower simply changes a char to lower case. static_cast<unsigned char>(c) is for safety.
*/

std::string toLower(std::string str){
    for(char& c : str){
        c = std::tolower(static_cast<unsigned char>(c));
    }
    return str;
}

void Library::displayBooks() const{
    if(books.empty()){
        std:: cout << "Library is empty."<< std::endl;
        return;
    }
    for(const Book& book : books){
        book.display();
    }
}

bool Library::addBook(const Book& book){
    for(const Book& b : books){
        if(toLower(b.get_Title())== toLower(book.get_Title())){
            std::cout << "Book already exists." << std::endl;
            return false;
        }
    }
    books.push_back(book);

    sortBooks();

    return true;
}

void Library::searchBook(const std:: string& title) const{
    for( const Book& book : books){
        if(toLower(book.get_Title())== toLower(title)){
            book.display();
            return;
        }
    }
}

void Library::borrowBook(const std::string& title){
    for(Book& book: books){
        if(toLower(book.get_Title())== toLower(title)){
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
        if(toLower(book.get_Title())== toLower(title)){
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

        if(line.empty()){
            continue;
        }

        std::string title;
        std::string author;
        std::string yearString;
        std::string borrowedString;

        std::getline(ss, title, '|');
        std::getline(ss, author, '|');
        std::getline(ss, yearString, '|');
        std::getline(ss, borrowedString);

        if(title.empty() || author.empty()){
            std::cout << "Skipping invalid line: " << line <<std:: endl;
            continue;
        }

        int year = std::stoi(yearString);
        bool borrowed = std::stoi(borrowedString);

        books.push_back(Book(title,author,year,borrowed));
    }

    file.close();
}

void Library::removeBook(const std::string& title){
    for(auto it = books.begin(); it != books.end(); it++){
        if(toLower(it->get_Title())== toLower(title)){
            books.erase(it);
            std::cout << "Book removed." << std::endl;
            return;
        }
    }
    std::cout << "Book not found." << std::endl;
}

void Library::sortBooks(){
    std::sort(books.begin(),books.end(),

    [](const Book& a, const Book& b){
        return a.get_Title() < b.get_Title();
    }
    );
}




