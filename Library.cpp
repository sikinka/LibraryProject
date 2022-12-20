//
// Created by Sikinka on 19.12.2022.
//
#include "Library.h"

#include <algorithm>

void Library::addBook(const Book& book) {
    books_.push_back(book);
    notify();
}

void Library::removeBookCopies(const std::string& title, int copies) {
    auto it = std::find_if(books_.begin(), books_.end(),
                           [&title](const Book& book) {
                               return book.getTitle() == title;
                           });
    if (it != books_.end()) {
        it->setCopies(it->getCopies() - copies);
        if (it->getCopies() == 0) {
            books_.erase(it);
        }
        notify();
    }
}

std::vector<Book> Library::getBooks() const { return books_; }

std::vector<Book> Library::findByAuthor(const std::string& author) const {
    std::vector<Book> result;
    std::copy_if(books_.begin(), books_.end(), std::back_inserter(result),
                 [&](const Book& b) { return b.getAuthor() == author; });
    return result;
}

std::vector<Book> Library::findByTitle(const std::string& title) const {
    std::vector<Book> result;
    std::copy_if(books_.begin(), books_.end(), std::back_inserter(result),
                 [&](const Book& b) { return b.getTitle() == title; });
    return result;
}

void Library::attach(Observer* observer) {
    observers_.push_back(observer);
}

void Library::notify() {
    for (Observer* observer : observers_) {
        observer->update();
    }
}