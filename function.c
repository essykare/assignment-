#include <stdio.h>   // Standard input/output operations
#include <stdlib.h>  // Standard library functions
#include <fcntl.h>   // File control options
#include <unistd.h>  // POSIX API

int main() {
    int fd;  // File descriptor

    // Open a file called "example.txt" in write mode with read/write permissions
    // If the file doesn't exist, it will be created. If it exists, it will be truncated.
    fd = open("example.txt", O_RDWR | O_CREAT | O_TRUNC, S_IRWXU);
    if (fd == -1) {  // Check if file open operation failed
        perror("open");  // Print error message
        exit(EXIT_FAILURE);  // Exit the program with failure status
    }

    // Write "Hello World" to the file
    if (write(fd, "Hello World", 11) == -1) {  // Check if write operation failed
        perror("write");  // Print error message
        exit(EXIT_FAILURE);  // Exit the program with failure status
    }

    // Close the file
    if (close(fd) == -1) {  // Check if close operation failed
        perror("close");  // Print error message
        exit(EXIT_FAILURE);  // Exit the program with failure status
    }

    // Re-open the file in read mode
    fd = open("example.txt", O_RDONLY);
    if (fd == -1) {  // Check if file open operation failed
        perror("open");  // Print error message
        exit(EXIT_FAILURE);  // Exit the program with failure status
    }

    char buffer[12];  // Buffer to store read content (+1 for null terminator)

    // Read content from the file into the buffer
    if (read(fd, buffer, 11) == -1) {  // Check if read operation failed
        perror("read");  // Print error message
        exit(EXIT_FAILURE);  // Exit the program with failure status
    }

    buffer[11] = '\0';  // Null terminate the string

    // Print the read content
    printf("Content read from file: %s\n", buffer);

    // Close the file
    if (close(fd) == -1) {  // Check if close operation failed
        perror("close");  // Print error message
        exit(EXIT_FAILURE);  // Exit the program with failure status
    }

    return 0;  // Exit the program successfully
}
