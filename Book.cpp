#include "Book.hpp"
#include <iostream>

Book::Book()
    : title_(""),author_(""), year_(0), borrowed(false) {}

Book::Book(std::string title,std::string author, int year ){
    title_ = title;
    author_ = author;
    year_ = year;
    borrowed = false;
}

std::string Book::get_Author() const{
    return author_;
}

std::string Book::get_Title() const{
    return title_;
}

int Book::get_year() const{
    return year_;
}

bool Book:: isBorrowed() const{
    return borrowed;
}

void Book::borrowBook(){
    borrowed = true;
}

void Book:: returnBook(){
    borrowed = false;
}

void Book:: display() const{
    std:: cout << title_ << " | " << author_ << " | " << year_ << " | ";

    if(borrowed){
        std:: cout << "Borrowed";
    }
    else{
        std:: cout << "Available";
    }
    std:: cout << std:: endl;
}


