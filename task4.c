#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Define a list of keywords
const char* keywords[] = {"int", "float", "if", "else", "while", "return"};
const int num_keywords = 6;

// Function to check if a word is a keyword
int is_keyword(const char* word) {
    for (int i = 0; i < num_keywords; i++) {
        if (strcmp(word, keywords[i]) == 0) {
            return 1; // It's a keyword
        }
    }
    return 0; // Not a keyword
}

// Function to check if a character is an operator
int is_operator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '=' ||
            c == '<' || c == '>' || c == '!' || c == '&' || c == '|');
}

// Function to check if a character is part of an identifier (letters, digits, and underscore)
int is_identifier_part(char c) {
    return isalnum(c) || c == '_';
}

// Function to identify tokens (keywords, operators, identifiers)
void analyze_token(FILE* file) {
    char c;
    char word[100]; // Buffer to store identifiers or keywords
    int index = 0;

    while ((c = fgetc(file)) != EOF) {
        // Skip whitespace characters
        if (isspace(c)) {
            continue;
        }

        // Check for operators
        if (is_operator(c)) {
            printf("Operator: %c\n", c);
            continue;
        }

        // If it's part of an identifier (starts with letter or underscore)
        if (isalpha(c) || c == '_') {
            word[index++] = c;

            // Now read the rest of the identifier (letters, digits, underscores)
            while (is_identifier_part((c = fgetc(file)))) {
                word[index++] = c;
            }

            // Null-terminate the string
            word[index] = '\0';

            // Check if the word is a keyword
            if (is_keyword(word)) {
                printf("Keyword: %s\n", word);
            } else {
                printf("Identifier: %s\n", word);
            }

            // If the character is not an identifier part, move back to process the next character
            if (c != EOF) {
                ungetc(c, file);
            }
            index = 0; // Reset the buffer
            continue;
        }

        // Handle other cases (e.g., literals, punctuation)
        // For simplicity, we just skip unrecognized characters here.
    }
}

int main() {
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    analyze_token(file);

    fclose(file);
    return 0;
}
