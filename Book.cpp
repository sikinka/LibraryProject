//
// Created by Sikinka on 19.12.2022.
//
#include "Book.h"

Book::Book(const std::string& title, const std::string& author, int copies)
        : title_(title), author_(author), copies_(copies) {}

const std::string& Book::getTitle() const { return title_; }

const std::string& Book::getAuthor() const { return author_; }

int Book::getCopies() const { return copies_; }

void Book::setCopies(int copies) { copies_ = copies; }

std::ostream& operator<<(std::ostream& out, const Book& book) {
    out << book.title_ << " by " << book.author_ << " (" << book.copies_
        << " copies)";
    return out;
}

bool operator==(const Book& lhs, const Book& rhs) {
    return lhs.title_ == rhs.title_ && lhs.author_ == rhs.author_ &&
           lhs.copies_ == rhs.copies_;
}
