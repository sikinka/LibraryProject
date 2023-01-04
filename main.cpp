#include <iostream>
#include <string>
#include "Book.h"
#include "Library.h"

int main() {
    Library library;
    Observer* observer = new SomeObserver();
    library.attach(observer);

    //přidej několik knih
    library.addBook(Book("The Hobbit", "J.R.R. Tolkien", 2));
    library.addBook(Book("The Lord of the Rings", "J.R.R. Tolkien", 3));
    library.addBook(Book("The Silmarillion", "J.R.R. Tolkien", 4));
    library.addBook(Book("Harry Potter and the Philosopher's Stone", "J.K. Rowling", 5));

    std::cout << std::endl;
    // Vypiš obsah knihovny
    std::cout << "Books in library:" << std::endl;
    for (const auto& book : library.getBooks()) {
        std::cout << book << std::endl;
    }
    std::cout << std::endl;

    // Vypiš knihy od J.R.R. Tolkien
    std::cout << "Books by J.R.R. Tolkien:" << std::endl;
    for (const auto& book : library.findByAuthor("J.R.R. Tolkien")) {
        std::cout << book << std::endl;
    }
    std::cout << std::endl;

    //vypiš všechny knihy od J.K. Rowling
    std::cout << "Books by J.K. Rowling:" << std::endl;
    for (const auto& book : library.findByAuthor("J.K. Rowling")) {
        std::cout << book << std::endl;
    }
    std::cout << std::endl;

    // Vypiš knihy s názvem "The Hobbit"
    std::cout << "Books with title \"The Hobbit\":" << std::endl;
    for (const auto& book : library.findByTitle("The Hobbit")) {
        std::cout << book << std::endl;
    }

    //Odstraň všechny knihy s názvem "The lord of the rings"
    library.removeBookCopies("The Lord of the Rings", 3);

    //Odstraň několik kopíí knihy "Silmarillion"
    library.removeBookCopies("The Silmarillion", 3);

    //Nastaví kopie Harryho Pottera na 2
   library.setCopies("Harry Potter and the Philosopher's Stone", 2);

    // Vypiš obsah knihovny po odebrání všech kopii The Lord of the Rings a odebrání 3 kopii The Silmarillion a nastavení kopii Harryho Pottera na 2
    std::cout << std::endl << R"(Books in library after removing all copies of "The Lord of the Rings", 3 out of 4 copies of "Silmarillion"
and setting "Harry Potter and the Philosopher's Stone" copies to 2:)" << std::endl;
    for (const auto& book : library.getBooks()) {
        std::cout << book << std::endl;
    }
    return 0;
}
