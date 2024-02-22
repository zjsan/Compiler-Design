#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>


int keyword(const char lexeme[]);
int operator(char ch);
int specialSymbol(char ch);
bool digit(char ch);
void tokenizer(const char input[], FILE * outputFile);

int main() {
    char input[1000];

    // Open input file for reading
    FILE * inputFile = fopen("input.txt", "r");
    if (!inputFile) {
        printf("Can't open the input file.\n");
        return 1;
    }

    // Open output file for writing
    FILE * outputFile = fopen("output.txt", "w");
    if (!outputFile) {
        printf("Can't create the output file.\n");
        fclose(inputFile);
        return 1;
    }

    // Read input file line by line and tokenize
    while (fgets(input, sizeof(input), inputFile)) {
        tokenizer(input, outputFile);
    }

    printf("Done\n");

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}


int keyword(const char lexeme[]) {
    // keywords used in switch case
    const char * keywords[] = {
        "if",
        "else",
        "print",
    };
    const int numKeywords = sizeof(keywords) / sizeof(keywords[0]);

    // Compare the lexeme with the list of keywords
    for (int buffer = 0; buffer < numKeywords; buffer++) {
        if (strcmp(lexeme, keywords[buffer]) == 0) {
            return 1;
        }
    }
    return 0;
}
// method to check if a character is a single digit
bool digit(char ch) {
    return ch >= '0' && ch <= '9';
}
 
// method to check if a character is an operator
int operator(char ch) {
    // Check if the character is one of the operators
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' ||
         ch == '=' || ch == '<' || ch == '>') {
        return 1;
    } else {
        return 0;
    }
}

// method to check if a character is a special symbol
int specialSymbol(char ch) {
    // Check if the character is one of the special symbols
    if (ch == '.' || ch == ',' || ch == ';' || ch == '?' ||
        ch == '/' || ch == '|' || ch == '\'' || ch == '-' ||
        ch == '_' ) {
        return 1;
    } else {
        return 0;
    }
}

int delimiter(char ch) {
    // Check if the character is one of the special symbols
    if (
        ch == ':' || ch == '(' || ch == ')' || ch == '[' ||
        ch == ']' || ch == '{' || ch == '}') {
        return 1;
    } else {
        return 0;
    }
}

// method to tokenize input and write tokens to the output file
void tokenizer(const char input[], FILE * outputFile) {
    const int size = strlen(input);
    char lexeme[100];
    int buffer = 0;

    // Loop through each character in the input line except space
    while (buffer < size) {
        if (isspace(input[buffer])) {
            buffer++;
            continue;
        }

        // Tokenizing numbers
        if (digit(input[buffer]) || (input[buffer] == '.' && digit(input[buffer + 1]))) {
            int index = 0;
            while (digit(input[buffer]) || input[buffer] == '.') {
                lexeme[index++] = input[buffer++];
            }
            lexeme[index] = '\0';
            fprintf(outputFile, "<number> \n", lexeme);
            continue;
        }
        // Tokenizing identifiers and keywords
        if (isalpha(input[buffer]) || input[buffer] == '_') {
            int index = 0;
            while (isalnum(input[buffer]) || input[buffer] == '_') {
                lexeme[index++] = input[buffer++];
            }
            lexeme[index] = '\0';

            if (keyword(lexeme)) {
                fprintf(outputFile, "<keyword> \n", lexeme);
            } else {
                fprintf(outputFile, "<identifier> \n", lexeme);
            }
            continue;
        }

        // Tokenizing operators
        if (operator(input[buffer])) {
            lexeme[0] = input[buffer++];
            lexeme[1] = '\0';
            fprintf(outputFile, "<operator> \n", lexeme);
            continue;
        }

        // Tokenizing special symbols
        if (specialSymbol(input[buffer])) {
            lexeme[0] = input[buffer++];
            lexeme[1] = '\0';
            fprintf(outputFile, "<special symbol> \n", lexeme);
            continue;
        }
        
        // Tokenizing delimiter symbols
        if (delimiter(input[buffer])) {
            lexeme[0] = input[buffer++];
            lexeme[1] = '\0';
            fprintf(outputFile, "%s\n", lexeme);
            continue;
        }

        // move to the next item or symbol or char
        buffer++;
    }
}