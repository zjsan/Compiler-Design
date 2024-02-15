#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void read(char *str);
void tokenizer(char *string);

int main()
{
    char input_string[100] = "int a = b + 1c; ";
    read(input_string);

}

void read(char *str)
{
    int i = 0, length = strlen(str);
    char *ptr;
    ptr = string;

    printf("%d\n", length);
    if(length == 0)
    {
        printf("empty");
    }
     // Tokenizing entire words or symbols
    char *token = strtok(str, " ");
    while (token != NULL)
    {
        printf("Token: %s\n", token);
        tokenizer(token);
        token = strtok(NULL, " ");
    }

}


/** Tokenization
	Rules:
	1. keywords -  datatypes
	2. identifier
	3. operator
	4. number
	5. special characters 
	**/

void tokenizer(char *string)
{   
    printf("the character is [%c]\n", string);

    //keywords
    if(strcmp(string, "int") || strcmp(string, "float") || strcmp(string, "double") || strcmp(string, "char")  || strcmp(string, "void") 
		|| strcmp(string, "if") || strcmp(string, "else") || strcmp(string, "else if") || strcmp(string, "for") || strcmp(string, "while") ||
		strcmp(string, "do") ||strcmp(string, "break") || strcmp(string, "continue"))
	{
		printf("keyword");
	}
    
    //identifier
    else if (string[0] != '0' || string[0] != '1' || string[0] != '2' ||
        string[0] != '3' || string[0] != '4' || string[0] != '5' || 
        string[0] != '6' || string[0] != '7' || string[0] != '8' || 
        string[0] != '9' || string != ' ' || string[0] != '+' || string[0] != '-' || string[0] != '*' || 
        string[0] != '/' || string[0] != ',' || string[0] != ';' || string[0] != '>' || 
        string[0] != '<' || string[0] != '=' || string[0] != '(' || string[0] != ')' || 
        string[0] != '[' || string[0] != ']' || string[0] != '{' || string[0] != '}')
    {
        printf("identifier");
    }
    
    //operators
    else if (string == '+' || string == '-' || string == '*' || 
        string == '/' || string == '>' || string == '<' || 
        string == '=')
    {
        printf("operator");
    }
    
    else if ( string == "0" || string == "1" || string == "2" || string == "3" || string == "4" || string == "5" || string == "6"
		|| string == "7" || string == "9" || string == "-" && string > 0 )
    {
        printf("number");
    }
    
    else if ( string == ' ' || string == '+' || string == '-' || string == '*' || 
        string == '/' || string == ',' || string == ';' || string == '>' || 
        string == '<' || string == '=' || string == '(' || string == ')' || 
        string == '[' || string == ']' || string == '{' || string == '}')
    {
        printf("delimeter/special character");
    }
    else{
        printf("invalid character");
    }
}

