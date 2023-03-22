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

void display_books() {
    if (num_books == 0) {
        printf("No books found.\n");
        return;
    }
    
    printf("Title\tAuthor\tYear\n");
    for (int i = 0; i < num_books; i++) {
        printf("%s\t%s\t%d\n", books[i].title, books[i].author, books[i].year);
    }
}

void search_book() {
    char search_term[50];
    printf("Enter the title or author of the book: ");
    scanf("%s", search_term);
    
    int found = 0;
    for (int i = 0; i < num_books; i++) {
        if (strcmp(search_term, books[i].title) == 0 || strcmp(search_term, books[i].author) == 0) {
            printf("%s\t%s\t%d\n", books[i].title, books[i].author, books[i].year);
            found = 1;
        }
    }
    
    if (!found) {
        printf("Book not found.\n");
    }
}

void remove_book() {
    char remove_title[50];
    printf("Enter the title of the book to remove: ");
    scanf("%s", remove_title);
    
    int found = 0;
    for (int i = 0; i < num_books; i++) {
        if (strcmp(remove_title, books[i].title) == 0) {
            for (int j = i; j < num_books - 1; j++) {
                books[j] = books[j + 1];
            }
            num_books--;
            found = 1;
            printf("Book removed successfully.\n");
            break;
        }
    }
    
    if (!found) {
        printf("Book not found.\n");
    }
}

int main() {
    int choice;
    do {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_book();
                break;
            case 2:
                display_books();
                break;
            case 3:
                search_book();
                break;
            case 4:
                remove_book();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 5);
    
    return 0;
}
