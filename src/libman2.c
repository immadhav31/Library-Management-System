#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct reader {
    int id;
    char name[50];
    char due;
    int bid;
};

struct book {
    int id;
    char name[50];
    char author[20];
    char avbl[10];
    int rdid;
};

int main() {
    struct reader rdr[10] = {0};
    struct book bok[20] = {0};

    int choice, searchid, searchid1, n, m, password, ch, newBookId, serch;
    char str2[6];
    char searchname[50];

    // Adding some sample books
    bok[0].id = 1;
    strcpy(bok[0].name, "TheIndiaWay");
    strcpy(bok[0].author, "ljtl");
    strcpy(bok[0].avbl, "Yes");
    bok[0].rdid = 0;

    bok[1].id = 2;
    strcpy(bok[1].name, "Book2Title");
    strcpy(bok[1].author, "Author2");
    strcpy(bok[1].avbl, "Yes");
    bok[1].rdid = 0;

    bok[2].id = 3;
    strcpy(bok[2].name, "Book3Title");
    strcpy(bok[2].author, "Author3");
    strcpy(bok[2].avbl, "Yes");
    bok[2].rdid = 0;

    bok[3].id = 4;
    strcpy(bok[3].name, "Book4Title");
    strcpy(bok[3].author, "Author4");
    strcpy(bok[3].avbl, "Yes");
    bok[3].rdid = 0;

    printf("\n\t\tWELCOME!\n\n");

    printf("How do you want to Enter: Press\n1) Admin\n2) User:\n\n");
    scanf("%d", &ch);

    if (ch == 1) {
        printf("You have requested to enter the page as Admin.\t");
        printf("Please Enter the Password to continue: ");
        scanf("%d", &password);

        if (password == 3112) {
            printf("\nWelcome Admin!\n");

            do {
                printf("\n\tLibrary Management System for Admins\n\t----------------------------------\n1. Add new book\t\t2. Search book\n3. Add new reader\t4. Search reader\n5. Issue book\t\t6. Submit book\n7. Delete book\t\t8. Delete reader\n9. List of books\t10. Exit\n\nEnter your choice: ");
                scanf("%d", &choice);

                switch (choice) {
                    case 1:
                        printf("Enter the Book ID(Only Numerical): ");
                        scanf("%d", &newBookId);

                        for (int i = 4; i < 20; i++) {
                            if (bok[i].id == newBookId || newBookId == 1 || newBookId == 2 || newBookId == 3 || newBookId == 4) {
                                printf("Book ID already exists. Please enter a different ID.\n\n");
                                break;
                            }

                            if (bok[i].id == 0) {
                                printf("Enter the name of the book(Space Not accepted): ");
                                scanf("%s", bok[i].name);
                                printf("Enter the name of the author(Space Not accepted): ");
                                scanf("%s", bok[i].author);
                                bok[i].id = newBookId;
                                strcpy(bok[i].avbl, "Yes");
                                bok[i].rdid = 0;
                                printf("Book added successfully.\n\n");
                                break;
                            }
                        }
                        break;

                    case 2:
                        // Search book
                        printf("\nEnter\n1)Search via Book ID \n2)search via Book Name \n3)Search via Author name: ");
                        scanf("%d", &serch);

                        switch (serch) {
                            case 1:
                                printf("Enter book ID(Only Numerical): ");
                                scanf("%d", &searchid);
                                n = 0;

                                for (int i = 0; i < 20; i++) {
                                    if (searchid == bok[i].id) {
                                        printf("\n\tBook Information\nBook ID: %d\tBook Name: %s\nAuthor Name: %s\nAvailable: %s\tDue by Reader ID: %d\n",
                                            bok[i].id, bok[i].name, bok[i].author, bok[i].avbl, bok[i].rdid);
                                        n++;
                                    }
                                    else{
                                        printf("Book Id not matching.\n");
                                    }
                                }
                                break;

                            case 2:
                                printf("Enter the book name(Space not Accepted): ");
                                scanf("%s", &searchname);

                                for (int i = 0; i < 20; i++) {
                                    if (strcmp(bok[i].name, searchname) == 0) {
                                        printf("\n\tBook Information\nBook ID: %d\tBook Name: %s\nAuthor Name: %s\nAvailable: %s\tDue by Reader ID: %d\n",
                                            bok[i].id, bok[i].name, bok[i].author, bok[i].avbl, bok[i].rdid);
                                        n++;
                                    }
                                    else{
                                        printf("Book name not matching.\n");
                                        break;
                                    }
                                    
                                }
                                break;

                            case 3:
                                printf("Enter the author name(Space not Accepted): ");
                                scanf("%s", &searchname);

                                for (int i = 0; i < 20; i++) {
                                    if (strcmp(bok[i].author, searchname) == 0) {
                                        printf("\n\tBook Information\nBook ID: %d\tBook Name: %s\nAuthor Name: %s\nAvailable: %s\tDue by Reader ID: %d\n",
                                            bok[i].id, bok[i].name, bok[i].author, bok[i].avbl, bok[i].rdid);
                                        n++;
                                    }
                                    else{
                                        printf("Author name not matching.\n"); 
                                        break;
                                    }
                                    
                                }
                                break;

                            default:
                                printf("Invalid choice.\n\n");
                                break;
                        }

                        if (n == 0) {
                            printf("Book not found");
                        }
                        break;

                    case 3:
                        // Add new reader
                        for (int i = 0; i < 10; i++) {
                            if (rdr[i].id == 0) {
                                printf("Enter Reader's name(Space not accepted): ");
                                scanf("%s", rdr[i].name);
                                printf("Enter Reader id(Only numerical): ");
                                scanf("%d", &rdr[i].id);
                                rdr[i].due = 'n';
                                rdr[i].bid = 0;
                                i = 10;
                                printf("Reader added successfully.\n\n");
                            }
                        }
                        break;

                    case 4:
                        // Search reader
                        printf("Enter Reader ID(Only Numerical): ");
                        scanf("%d", &searchid);
                        n = 0;

                        for (int i = 0; i < 10; i++) {
                            if (searchid == rdr[i].id) {
                                printf("\n\tReader Information\nReader ID: %d\tReader Name: %s\nDue: %c\t\tDue book ID: %d\n",
                                    rdr[i].id, rdr[i].name, rdr[i].due, rdr[i].bid);
                                n++;
                            }
                        }

                        if (n == 0) {
                            printf("Reader not found.\n\n");
                        }
                        break;

                    case 5:
                        // Issue book
                        printf("Enter book ID: ");
                        scanf("%d", &searchid);
                        printf("Enter reader ID: ");
                        scanf("%d", &searchid1);
                        n = 0;
                        m = 0;

                        for (int i = 0; i < 20; i++) {
                            if (searchid == bok[i].id && strcmp(bok[i].avbl, "Yes") == 0) {
                                strcpy(bok[i].avbl, "No");
                                bok[i].rdid = searchid1;
                                n++;
                                break;
                            }
                        }

                        for (int i = 0; i < 10; i++) {
                            if (searchid1 == rdr[i].id && rdr[i].due == 'n') {
                                rdr[i].due = 'y';
                                rdr[i].bid = searchid;
                                m++;
                                break;
                            }
                        }

                        if (n == 1 && m == 1) {
                            printf("Book issued successfully.\n\n");
                        } else if (n == 1 && m == 0) {
                            for (int i = 0; i < 20; i++) {
                                if (searchid == bok[i].id) {
                                    strcpy(bok[i].avbl, "Yes");
                                    bok[i].rdid = 0;
                                    break;
                                }
                            }
                            printf("Book not issued.\nReader has a due book.\n\n");
                        } else {
                            printf("Book or Reader not found.\n\n");
                        }
                        break;

                    case 6:
                        // Submit book
                        printf("Enter book ID: ");
                        scanf("%d", &searchid);

                        for (int i = 0; i < 20; i++) {
                            if (searchid == bok[i].id) {
                                strcpy(bok[i].avbl, "Yes");
                                searchid1 = bok[i].rdid;
                                bok[i].rdid = 0;
                                break;
                            }
                        }

                        for (int i = 0; i < 10; i++) {
                            if (searchid1 == rdr[i].id) {
                                rdr[i].due = 'n';
                                rdr[i].bid = 0;
                                break;
                            }
                        }

                        printf("Book submitted successfully.\n\n");
                        break;

                    case 7:
                        // Delete book
                        printf("Enter book ID: ");
                        scanf("%d", &searchid);
                        n = 0;

                        for (int i = 0; i < 20; i++) {
                            if (searchid == bok[i].id) {
                                bok[i].id = 0;
                                strcpy(bok[i].name, "");
                                strcpy(bok[i].author, "");
                                strcpy(bok[i].avbl, "");
                                bok[i].rdid = 0;
                                n++;
                                printf("Book deleted successfully.\n\n");
                                break;
                            }
                        }

                        if (n == 0) {
                            printf("Book not found.\n\n");
                        }
                        break;

                    case 8:
                        // Delete reader
                        printf("Enter Reader ID: ");
                        scanf("%d", &searchid);
                        n = 0;

                        for (int i = 0; i < 10; i++) {
                            if (searchid == rdr[i].id) {
                                rdr[i].id = 0;
                                strcpy(rdr[i].name, "");
                                rdr[i].due = 'n';
                                rdr[i].bid = 0;
                                n++;
                                printf("Reader deleted successfully.\n\n");
                                break;
                            }
                        }

                        if (n == 0) {
                            printf("Reader not found.\n\n");
                        }
                        break;

                    case 9:
                        // List of books
                        printf("\n\t\tList of Books\n\n");
                        printf("%-5s %-30s %-20s %-10s %-15s\n", "ID", "Book Name", "Author Name", "Available", "Reader ID");
                        printf("-------------------------------------------------------------------------------------------\n");

                        for (int i = 0; i < 20; i++) {
                            if (bok[i].id != 0) {
                                printf("%-5d %-30s %-20s %-10s %-15d\n", bok[i].id, bok[i].name, bok[i].author, bok[i].avbl, bok[i].rdid);
                            }
                        }

                        printf("\n");
                        break;

                    case 10:
                        printf("\n\t\tGoodbye!\n");
                        exit(0);

                    default:
                        printf("Invalid choice.\n\n");
                        break;
                }
            } while (choice != 10);
        } else {
            printf("Your Password is Incorrect! Please try again..\n");
        }
    } else if (ch == 2) {
        printf("Welcome to the Library! You have entered the library as a user.\n");
        printf("Please add yourself as a reader before continuing...\n");

        do {
            printf("\n\tLibrary Management System for Users\n\t-------------------------------------\n1. Search book\n2. Add new reader\n3. Submit the book\n4. List of books\n5. Exit\n\nEnter your choice: ");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                        // Search book
                        printf("\nEnter\n1)Search via Book ID \n2)search via Book Name \n3)Search via Author name: ");
                        scanf("%d", &serch);

                        switch (serch) {
                            case 1:
                                printf("Enter book ID(Only Numerical): ");
                                scanf("%d", &searchid);
                                n = 0;

                                for (int i = 0; i < 20; i++) {
                                    if (searchid == bok[i].id) {
                                        printf("\n\tBook Information\nBook ID: %d\tBook Name: %s\nAuthor Name: %s\nAvailable: %s\tDue by Reader ID: %d\n",
                                            bok[i].id, bok[i].name, bok[i].author, bok[i].avbl, bok[i].rdid);
                                        n++;
                                    }
                                }
                                break;

                            case 2:
                                printf("Enter the book name(Space not Accepted): ");
                                scanf("%s", &searchname);

                                for (int i = 0; i < 20; i++) {
                                    if (strcmp(bok[i].name, searchname) == 0) {
                                        printf("\n\tBook Information\nBook ID: %d\tBook Name: %s\nAuthor Name: %s\nAvailable: %s\tDue by Reader ID: %d\n",
                                            bok[i].id, bok[i].name, bok[i].author, bok[i].avbl, bok[i].rdid);
                                        n++;
                                    }
                                    else{
                                        printf("Book name not matching.\n");
                                        break;
                                    }
                                    
                                }
                                break;

                            case 3:
                                printf("Enter the author name(Space not Accepted): ");
                                scanf("%s", &searchname);

                                for (int i = 0; i < 20; i++) {
                                    if (strcmp(bok[i].author, searchname) == 0) {
                                        printf("\n\tBook Information\nBook ID: %d\tBook Name: %s\nAuthor Name: %s\nAvailable: %s\tDue by Reader ID: %d\n",
                                            bok[i].id, bok[i].name, bok[i].author, bok[i].avbl, bok[i].rdid);
                                        n++;
                                    }
                                    else{
                                        printf("Author name not matching.\n"); 
                                        break;
                                    }
                                    
                                }
                                break;

                            default:
                                printf("Invalid choice.\n\n");
                                break;
                        }

                        if (n == 0) {
                            printf("Book not found.\n");
                        }
                        break;


                case 2:
                    // Add new reader
                    for (int i = 0; i < 10; i++) {
                        if (rdr[i].id == 0) {
                            printf("Enter Reader's name: ");
                            scanf("%s", rdr[i].name);
                            printf("Enter Reader id: ");
                            scanf("%d", &rdr[i].id);
                            rdr[i].due = 'n';
                            rdr[i].bid = 0;
                            i = 10;
                            printf("Reader added successfully.\n\n");
                        }
                    }
                    break;

                case 3:
                    // Submit book
                    printf("Enter book ID: ");
                    scanf("%d", &searchid);

                    for (int i = 0; i < 20; i++) {
                        if (searchid == bok[i].id) {
                            strcpy(bok[i].avbl, "Yes");
                            searchid1 = bok[i].rdid;
                            bok[i].rdid = 0;
                            break;
                        }
                    }

                    for (int i = 0; i < 10; i++) {
                        if (searchid1 == rdr[i].id) {
                            rdr[i].due = 'n';
                            rdr[i].bid = 0;
                            break;
                        }
                    }

                    printf("Book submitted successfully.\n\n");
                    break;

                case 4:
                    // List of books
                    printf("\n\t\tList of Books\n\n");
                    printf("%-5s %-30s %-20s %-10s %-15s\n", "ID", "Book Name", "Author Name", "Available", "Reader ID");
                    printf("-------------------------------------------------------------------------------------------\n");

                    for (int i = 0; i < 20; i++) {
                        if (bok[i].id != 0) {
                            printf("%-5d %-30s %-20s %-10s %-15d\n", bok[i].id, bok[i].name, bok[i].author, bok[i].avbl, bok[i].rdid);
                        }
                    }

                    printf("\n");
                    break;

                case 5:
                    printf("\n\t\tGoodbye!\n");
                    exit(0);

                default:
                    printf("Invalid choice.\n\n");
                    break;
            }
        } while (choice != 5);
    } else {
        printf("You have pressed a different number. Press between 1 and 2.\n");
    }

    return 0;
}
