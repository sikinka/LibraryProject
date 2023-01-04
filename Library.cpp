//
// Created by Sikinka on 19.12.2022.
//
#include "Library.h"
#include <algorithm>

// Přidává knihu do knihovny
void Library::addBook(const Book& book) {
    books_.push_back(book);
    notify();
}

// Odebírá určitý počet kopií knihy s daným názvem z knihovny
// Pokud po odebrání zbude 0 kopií knihy, kniha je úplně odstraněna z knihovny
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

// Vrací seznam všech knih v knihovně
std::vector<Book> Library::getBooks() const { return books_; }

// Vrací seznam knih od daného autora
std::vector<Book> Library::findByAuthor(const std::string& author) const {
    std::vector<Book> result;
    std::copy_if(books_.begin(), books_.end(), std::back_inserter(result),
                 [&](const Book& b) { return b.getAuthor() == author; });
    return result;
}

// Vrací seznam knih s daným názvem
std::vector<Book> Library::findByTitle(const std::string& title) const {
    std::vector<Book> result;
    std::copy_if(books_.begin(), books_.end(), std::back_inserter(result),
                 [&](const Book& b) { return b.getTitle() == title; });
    return result;
}
//setCopies
void Library::setCopies(const char *string, int copies) {
    auto it = std::find_if(books_.begin(), books_.end(),
                           [&string](const Book& book) {
                               return book.getTitle() == string;
                           });
    if (it != books_.end()) {
        it->setCopies(copies);
    }
}


// Přidá sledující objekt do seznamu sledujících objektů
void Library::attach(Observer* observer) { observers_.push_back(observer); }

// Oznámí všem sledujícím objektům, že došlo ke změně v knihovně
void Library::notify() {
    for (auto observer : observers_) {
        observer->update();
    }
}
