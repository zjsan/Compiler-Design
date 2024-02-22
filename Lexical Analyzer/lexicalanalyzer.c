#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

bool keyword(const char lexeme[]);
bool operator(char ch);
bool SpecialSymbol(char ch);
bool number(char ch);
void tokenizerFunction(const char input[], FILE * outputFile);


//driver code
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
        tokenizerFunction(input, outputFile);
    }

    printf("Please review the output in output.txt.\n");

	//closing files
    fclose(inputFile);
    fclose(outputFile);

    return 0;
}


// method to tokenize input and write tokens to the output file
void tokenizerFunction(const char input[], FILE * outputFile) {

    const int size = strlen(input);
    char lexeme[100];
    int pointer = 0;

    // Loop through each character in the input line except space
    while (pointer < size) {
        if (isspace(input[pointer])) {
            pointer++;
            continue;
        }

        // Tokenizing numbers
        if (singleDigitChecker(input[pointer]) || (input[pointer] == '.' && singleDigitChecker(input[pointer + 1]))) {
            int index = 0;
            while (singleDigitChecker(input[pointer]) || input[pointer] == '.') {
                lexeme[index++] = input[pointer++];
            }
            lexeme[index] = '\0';
            fprintf(outputFile, "<number> -> %s\n", lexeme);
            continue;
        }
        // Tokenizing identifiers and keywords
        else if (isalpha(input[pointer]) || input[pointer] == '_') {
            int index = 0;
            while (isalnum(input[pointer]) || input[pointer] == '_') {
                lexeme[index++] = input[pointer++];
            }
            lexeme[index] = '\0';

            if (keywordValidator(lexeme)) {
                fprintf(outputFile, "<keyword> -> %s\n", lexeme);
            } else {
                fprintf(outputFile, "<identifier> -> %s\n", lexeme);
            }
            continue;
        }
        // Tokenizing operators
        else if (operatorChecker(input[pointer])) {
            lexeme[0] = input[pointer++];
            lexeme[1] = '\0';
            fprintf(outputFile, "<operator> -> %s\n", lexeme);
            continue;
        }
        // Tokenizing special symbols
        else if (SpecialSymbolChecker(input[pointer])) {
            lexeme[0] = input[pointer++];
            lexeme[1] = '\0';
            fprintf(outputFile, "<special symbol> -> %s\n", lexeme);
            continue;
        }

        // move to the next item or symbol or char
        pointer++;
    }
}


// keywords
bool keyword(const char lexeme[]) {
    // keywords used in switch case
    const char * keywords[] = {
        "if",
		"else",
		"print"
    };

    const int numKeywords = sizeof(keywords) / sizeof(keywords[0]);//length

    // Compare the lexeme with the list of keywords
    for (int buffer = 0; buffer < numKeywords; buffer++) {
        if (strcmp(lexeme, keywords[buffer]) == 0) {
            return true;
        }
    }
    return false;
}



// method to check if a character is an operator
bool operator(char ch) {
    // Check if the character is one of the operators
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' ||
        ch == ':' || ch == '=' || ch == '<' || ch == '>') {
        return true;
    } else {
        return false;
    }
}

// method to check if a character is a single digit
bool number(char ch) {
    return ch >= '0' && ch <= '9';
}


// method to check if a character is a special symbol
bool SpecialSymbol(char ch) {
    // Check if the character is one of the special symbols
    if (ch == '.' || ch == ',' || ch == ';' || ch == '?' ||
        ch == '/' || ch == '|' || ch == '\'' || ch == '-' ||
        ch == '_' || ch == '(' || ch == ')' || ch == '[' ||
        ch == ']' || ch == '{' || ch == '}') {
			
        return true;
    } else {
        return false;
    }
}
