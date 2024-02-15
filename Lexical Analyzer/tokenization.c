#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "Tokenization is important";
    char token[50]; // Assuming maximum token length is 50 characters
    int token_index = 0;
    
    // Iterate through each character in the string
    for (int i = 0; i <= strlen(str); i++) {
        // If the current character is not a space or null terminator
        if (str[i] != ' ' && str[i] != '\0') {
            // Add the character to the token
            token[token_index++] = str[i];
        } else {
            // If the token is not empty, print it
            if (token_index > 0) {
                token[token_index] = '\0'; // Null terminate the token
                printf("%s\n", token);
                token_index = 0; // Reset token index for next token
            }
            
            // If the current character is a space, print it as a token
            if (str[i] == ' ') {
                token[token_index++] = str[i];
            }
        }
    }
    
    return 0;
}
