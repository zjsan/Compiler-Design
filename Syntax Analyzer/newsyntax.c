#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LENGTH 1000

// Function prototypes
bool match(char *expected_token);
void expression();
void term();
void factor();
void assignment_statement();
void print_statement();
void if_else_statement();
void block();
void statements();
void statement();

// Global variables
char code[MAX_LENGTH];
int current_index = 0;
int indentation_level = 0;

// Match function
bool match(const char *expected_token) {
    int expected_length = strlen(expected_token);
    if (strncmp(&code[current_index], expected_token, expected_length) == 0) {
        current_index += expected_length;
        return true;
    }
    return false;
}


// Expression function
void expression() {
    term();
    if (match("<") || match(">") || match("<=") || match(">=") || match("==") || match("!=")) {
        term();
    }
}

// Term function
void term() {
    factor();
    while (match("+") || match("-")) {
        factor();
    }
}

// Factor function
void factor() {
    if (match("(")) {
        expression();
        if (!match(")")) {
            printf("Error: Expected ')'\n");
            exit(1);
        }
    } else if (match("NUM") || match("ID")) {
        // Assuming 'NUM' and 'ID' represent number and identifier respectively
    } else {
        printf("Error: Expected a number or identifier\n");
        exit(1);
    }
}

// Assignment statement function
void assignment_statement() {
    // Assuming 'ID' represents an identifier
    if (match("ID")) {
        if (match("=")) {
            expression();
        } else {
            printf("Error: Expected '=' after identifier\n");
            exit(1);
        }
    } else {
        printf("Error: Expected an identifier\n");
        exit(1);
    }
}


// Print statement function
void print_statement() {
    if (match("print")) {
        if (match("(")) {
            expression();
            if (!match(")")) {
                printf("Error: Expected ')'\n");
                exit(1);
            }
        } else {
            printf("Error: Expected '(' after 'print'\n");
            exit(1);
        }
    } else {
        printf("Error: Expected 'print' keyword\n");
        exit(1);
    }
}

// If-else statement function
void if_else_statement() {
    if (match("if")) {
        expression();
        if (match(":")) {
            block();
            if (match("else")) {
                if (match(":")) {
                    block();
                } else {
                    printf("Error: Expected ':' after 'else'\n");
                    exit(1);
                }
            }
        } else {
            printf("Error: Expected ':' after 'if' condition\n");
            exit(1);
        }
    } else {
        printf("Error: Expected 'if' keyword\n");
        exit(1);
    }
}

// Block function
void block() {
    if (match("INDENT")) {
        indentation_level++;
        statements();
        if (!match("DEDENT")) {
            printf("Error: Expected 'DEDENT' at the end of block\n");
            exit(1);
        }
        indentation_level--;
    } else {
        statement();
    }
}

// Statements function
void statements() {
    statement();
    while (true) {
        if (match("INDENT")) {
            indentation_level++;
            statements();
            if (!match("DEDENT")) {
                printf("Error: Expected 'DEDENT' at the end of block\n");
                exit(1);
            }
            indentation_level--;
        } else {
            return;
        }
    }
}

// Statement function
void statement() {
    assignment_statement();
    print_statement();
    if_else_statement();
}

int main() {
    // Input Python code
    strcpy(code, "x = 6\ny = 5\nif x>y:\n    print(x)\nelse:\n    print(y)\n");

    // Process the code
    statement();//function call to the parser
    
    printf("Syntax analysis successful!\n");

    return 0;
}
