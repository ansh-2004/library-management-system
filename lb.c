#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

typedef struct {
    char title[50];
    char author[50];
    int year;
} Book;

Book books[MAX_BOOKS];
int num_books = 0;

void print_menu() {
    printf("\n1. Add a book\n");
    printf("2. Display all books\n");
    printf("3. Search for a book\n");
    printf("4. Remove a book\n");
    printf("5. Exit\n");
}

void add_book() {
    if (num_books == MAX_BOOKS) {
        printf("Error: maximum number of books reached.\n");
        return;
    }
    
    Book new_book;
    printf("Enter the title of the book: ");
    scanf("%s", new_book.title);
    printf("Enter the author of the book: ");
    scanf("%s", new_book.author);
    printf("Enter the year of publication of the book: ");
    scanf("%d", &new_book.year);
    
    books[num_books] = new_book;
    num_books++;
    
    printf("Book added successfully.\n");
}



