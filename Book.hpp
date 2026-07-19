#ifndef BOOK_HPP
#define BOOK_HPP

#include <string>

class Book {
    private:
    std::string author_;
    std::string title_;
    int year_;
    bool borrowed_;

    public:
    Book();
    Book(std::string title, std::string author, int year);
    Book(std::string title, std::string author, int year, bool borrowed);

    std::string get_Author() const;
    std::string get_Title() const;
    int get_year() const;
    
    bool isBorrowed() const;

    void borrowBook();
    void returnBook();

    void display() const;
};















#endif