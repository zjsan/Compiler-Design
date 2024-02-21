#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void tokenizer(FILE *input_file, FILE *output_file);
bool keyword(char *string);
bool identifier(char *token);
bool operator(char *token);
bool number(char *token);
bool special_character(char token);

int main()
{
    // Open the input file for reading
    FILE *input_file = fopen("input.txt", "r");
    if (input_file == NULL)
    {
        printf("Error opening input file check the file if existing.\n");
        return 1;
    }

    // Open a new file for writing output
    FILE *output_file = fopen("output.txt", "w");
    if (output_file == NULL)
    {
        printf("Error creating output file.\n");
        fclose(input_file);
        return 1;
    }

    // Tokenize the input file and write output to the output file
    tokenizer(input_file, output_file);

    // Close the input and output files
    fclose(input_file);
    fclose(output_file);

    return 0;
}

void tokenizer(FILE *input_file, FILE *output_file)
{
    char token[100];
    int token_index = 0;
    char ch;

    // Iterate through each character in the file
    while ((ch = fgetc(input_file)) != EOF)
    {
        // If the current character is not a space or newline
        if (ch != ' ' && ch != '\n')
        {
            // Add the character to the token
            token[token_index++] = ch;
        }
        else
        {
            // If the token is not empty, process it
            if (token_index > 0)
            {
                token[token_index] = '\0'; // Null terminate the token

                // Check if token is a keyword
                if (keyword(token))
                {
                    fprintf(output_file, "<keyword>: %s\n", token);
                }
                else if (identifier(token))
                {
                    fprintf(output_file, "<identifier>: %s\n", token);
                }
                else if (operator(token))
                {
                    fprintf(output_file, "<operator>: %s\n", token);
                }
                else if (number(token))
                {
                    fprintf(output_file, "<number>: %s\n", token);
                }
                else
                {
                    fprintf(output_file, "<Token>: %s\n", token);
                }

                token_index = 0; // Reset token index for next token
            }

            // If the current character is a newline, treat it as a special character
            if (ch == '\n')
            {
                fprintf(output_file, "<special_character>: newline\n");
            }
        }
    }
}

bool keyword(char *string)
{
    char *keywords[] = {"if", "else","print"};

    for (int i = 0; i < sizeof(keywords) / sizeof(keywords[0]); i++)
    {
        if (strcmp(string, keywords[i]) == 0)
        {
            return true;
        }
    }
    return false;
}

bool identifier(char *token)
{
        // Check if the first character is a letter or underscore
    if ((token[0] == '_' || (token[0] >= 'a' && token[0] <= 'z') || (token[0] >= 'A' && token[0] <= 'Z')))
    {
        return true;
    }

    // Check the remaining characters
    for (int i = 1; i < strlen(token); i++)
    {
        if ((token[i] == '_' || (token[i] >= 'a' && token[i] <= 'z') || (token[i] >= 'A' && token[i] <= 'Z') || (token[i] >= '0' && token[i] <= '9')))
        {
            return true;
        }
    }

    return false;
}

bool operator(char *token)
{
    char *operators[] = {"+", "-", "*", "/", "%", "=", "==", "!=", ">", "<", ">=", "<="};

    for (int i = 0; i < sizeof(operators) / sizeof(operators[0]); i++)
    {
        if (strcmp(token, operators[i]) == 0)
        {
            return true;
        }
    }
    return false;
}

bool number(char *token)
{
    if (*token >= '0' && *token <= '9')
    {
        return true;
    }
    return false;
}

bool special_character(char token)
{
    char special_characters[] = {' ', '(', ')', ';', ':', '\'', '\"', '\\', '\t', '\n'};

    for (int i = 0; i < sizeof(special_characters) / sizeof(special_characters[0]); i++)
    {
        if (token == special_characters[i])
        {
            return true;
        }
    }
    return false;
}
