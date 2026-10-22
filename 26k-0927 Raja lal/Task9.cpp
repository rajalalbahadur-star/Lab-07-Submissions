/*A library shelf holds 5 books. Read each title (with spaces) using the scanset scanf(" %[^\n]",
titles[i]) into char titles[5][50], and read its number of copies into an int. Then:
1. Print the catalog as a neat table.
2. Count the vowels in each title using nested loops.
3. Let the user enter a single letter, then show which titles start with that letter.
4. Print the title with the most copies.*/
#include<stdio.h>
int main(){
	char titles[5][50];
	int copies[5];
	printf("--- ENTER BOOK DETAILS ---\n");
    for (int i = 0; i < 5; i++) {
        printf("\nEnter title for book %d: ", i + 1);
        scanf(" %[^\n]", titles[i]); 
        printf("Enter number of copies for book %d: ", i + 1);
        scanf("%d", &copies[i]);
    }
    printf("          LIBRARY CATALOG TABLE         \n");
    printf("%-5s | %-30s | %-10s\n", "No.", "Book Title", "Copies");
    printf("----------------------------------------\n");  
    for (int i = 0; i < 5; i++) {
        printf("%-5d | %-30s | %-10d\n", i + 1, titles[i], copies[i]);
    }
    printf("========================================\n");
    printf("\n--- VOWEL COUNT PER TITLE ---\n");
    for (int i = 0; i < 5; i++) {
        int vowel_count = 0;
        for (int j = 0; titles[i][j] != '\0'; j++) {
            char ch = titles[i][j];
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
                ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
                vowel_count++;
            }
        }
        printf("'%s' has %d vowels.\n", titles[i], vowel_count);
    }
    char search_letter;
    printf("\nEnter a letter to search for books starting with it: ");
    scanf(" %c", &search_letter);

    printf("\n--- BOOKS STARTING WITH '%c' ---\n", search_letter);
    int found_match = 0;
    for (int i = 0; i < 5; i++) {
        char first_char = titles[i][0];
        if (first_char == search_letter || 
            first_char == search_letter + 32 || 
            first_char == search_letter - 32) {
            printf("- %s\n", titles[i]);
            found_match = 1;
        }
    }

    if (found_match == 0) {
        printf("No books found starting with '%c'.\n", search_letter);
    }

    int max_copies = copies[0];
    int best_book_index = 0;
    for (int i = 1; i < 5; i++) {
        if (copies[i] > max_copies) {
            max_copies = copies[i];
            best_book_index = i;
        }
    }

    printf("\n--- BOOK WITH THE MOST COPIES ---\n");
    printf("Title: %s\n", titles[best_book_index]);
    printf("Copies: %d\n", max_copies);

    return 0;
}
