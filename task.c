#include <stdio.h>
#include <stdlib.h>

// Function to create and write initial data to a file
void create_file(const char *filename) {
    FILE *file = fopen(filename, "w"); // Open file for writing (creates if not exists)
    if (file == NULL) {
        printf("Error creating the file.\n");
        return;
    }
    fprintf(file, "This is the initial content of the file.\n");
    fclose(file);
}

// Function to read and display content from a file
void read_file(const char *filename) {
    FILE *file = fopen(filename, "r"); // Open file for reading
    if (file == NULL) {
        printf("Error reading the file. File may not exist.\n");
        return;
    }

    char ch;
    printf("File content:\n");
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch); // Print the character to the console
    }
    fclose(file);
}

// Function to write new data to a file (overwrite existing content)
void write_to_file(const char *filename, const char *content) {
    FILE *file = fopen(filename, "w"); // Open file for writing (overwrites existing content)
    if (file == NULL) {
        printf("Error writing to the file.\n");
        return;
    }
    fprintf(file, "%s", content);
    fclose(file);
}

// Function to append data to the end of a file
void append_to_file(const char *filename, const char *content) {
    FILE *file = fopen(filename, "a"); // Open file for appending
    if (file == NULL) {
        printf("Error appending to the file.\n");
        return;
    }
    fprintf(file, "%s", content);
    fclose(file);
}

int main() {
    const char *filename = "example_file.txt";

    // Step 1: Create a file and write initial content
    create_file(filename);

    // Step 2: Read and display the content of the file
    read_file(filename);

    // Step 3: Write new content to the file (overwrites existing content)
    const char *new_content = "This is the new content written to the file.\n";
    write_to_file(filename, new_content);

    // Step 4: Read the file after writing new content
    read_file(filename);

    // Step 5: Append new content to the file
    const char *append_content = "This is appended content.\n";
    append_to_file(filename, append_content);

    // Step 6: Read the file after appending new content
    read_file(filename);

    return 0;
}
