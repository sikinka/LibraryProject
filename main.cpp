#include <iostream>
#include <string>
#include "Book.h"
#include "Library.h"

int main() {
    Library library;
    Observer* observer = new SomeObserver();
    library.attach(observer);

    // Přidej několik knih
    library.addBook(Book("Pride and Prejudice", "Jane Austen", 2));
    library.addBook(Book("To Kill a Mockingbird", "Harper Lee", 3));
    library.addBook(Book("The Great Gatsby", "F. Scott Fitzgerald", 4));

    // Vypiš obsah knihovny
    std::cout << "Books in library:" << std::endl;
    for (const auto& book : library.getBooks()) {
        std::cout << book << std::endl;
    }
    //vypiš oddělení
    std::cout << std::endl;

    // Vypiš knihy od Jane Austen
    std::cout << "Books by Jane Austen:" << std::endl;
    for (const auto& book : library.findByAuthor("Jane Austen")) {
        std::cout << book << std::endl;
    }
    std::cout << std::endl;


    // Vypiš knihy s názvem "The Great Gatsby"
    std::cout << "Books with title \"The Great Gatsby\":" << std::endl;
    for (const auto& book : library.findByTitle("The Great Gatsby")) {
        std::cout << book << std::endl;
    }
    std::cout << std::endl;

    //remove all book copies of Mockingbird
    library.removeBookCopies("To Kill a Mockingbird", 3);

    //remove some book copies of great gatsby
    library.removeBookCopies("The Great Gatsby", 3);

    // Vypiš obsah knihovny po odebrání všech kopii Mockingbird a odebrání 3 kopii Gatsby
    std::cout << std::endl << "Books in library after removing all copies of'To Kill a Mockingbird': and 3 out of 4 copies of The Great Gatsby" << std::endl;
    for (const auto& book : library.getBooks()) {
        std::cout << book << std::endl;
    }
    return 0;
}
