#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void tokenizer(char *string);
bool keyword(char *string);
bool identifier(char *token);
bool operator(char *token);
bool number(char *token);
bool special_character(char token);

int main()
{
    // Original string
    char str[] = "if x > 55:";
    tokenizer(str);
    return 0;
}

void tokenizer(char *str)
{
    char token[100];
    int token_index = 0;

    // Iterate through each character in the string
    for (int i = 0; i <= strlen(str); i++)
    {

        
        // If the current character is not a space or null terminator
        if (str[i] != ' ' && str[i] != '\0')
        {
            // Add the character to the token
            token[token_index++] = str[i];
        } 
        else
        {
            // If the token is not empty, print it
            if (token_index > 0)
            {
                token[token_index] = '\0'; // Null terminate the token

                // Check if token is a keyword
                if (keyword(token))
                {
                    printf("<keyword>: %s\n", token);
                }
                else if (identifier(token))
                {
                    printf("<identifier>: %s\n", token);
                }
                else if (operator(token))
                {
                    printf("<operator>: %s\n", token);
                }
                else if (number(token))
                {
                    printf("<number>: %s\n", token);
                }
                else if (special_character(token[0]))
                {
                    printf("<special_character>: %s\n", token);
                }
                else
                {
                    printf("<Token>: %s\n", token);
                }

                token_index = 0; // Reset token index for next token
            }
			
            // If the current character is a space, print it as a special character
            if (str[i] == ' ')
            {
                printf("<special_character>: SPACE\n");
            }
        }
    }
}

bool keyword(char *string)
{
    char *keywords[] = {"def", "and", "as", "assert", "break", "class", "continue", "del", "if", "else",
                        "elif", "except", "False", "finally", "for", "from", "global", "if", "import", "in", "is", "lambda", "None",
                        "nonlocal", "not", "or", "pass", "raise", "return", "True", "try", "while", "with", "yield"};

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
    char *operators[] = {"+", "-", "*", "/", "%", "=", "==", "!=", ">", "<", ">=", "<=", "**", "//",
                         "+=", "-=", "*=", "/=", "//=", "//=", "&=", "^=", ">>=", "<<=","%=", "&", "|", "^", "~",
						  "<<", ">>", "&&", "||", "!", "++", "--", };

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
