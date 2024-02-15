#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void read(char *str, char string[100]);
void tokenizer(char *string);
bool keyword(char *string);
bool identifier(char *string);
bool operator(char *string);
bool number(char *string);
bool special_character(char *string);

int main()
{ 
    char input_string[100] = "int a = b + 1c; ";
    read(input_string, input_string);

}

void read(char *str, char string[100])
{
    int i = 0, length = strlen(str);
    char *ptr;
    ptr = string;

    printf("%d\n", length);
    if(length == 0)
    {
        printf("empty");
    }
    while ( i <= length)
    {
        printf("address of str[%d] = %x\n", i,str);
        printf("value of str[%d] = %c\n", i, *str);
        
        tokenizer(str[i]);
        str++;
        i++;
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


bool keyword(char *string)
{
    if(strcmp(string, "def") || strcmp(string, "and") || strcmp(string, "as") || strcmp(string, "assert")  || strcmp(string, "break") 
		|| strcmp(string, "class") || strcmp(string, "continue") || strcmp(string, "del") || strcmp(string, "if") || strcmp(string, "else") ||
		strcmp(string, "elif") ||strcmp(string, "except") || strcmp(string, "False") || strcmp(string, "finally") || strcmp(string, "for") || 
        strcmp(string,"from") || strcmp(string, "global") || strcmp(string, "if") || strcmp(string, "import") || strcmp(string,"in") || 
        strcmp(string, "is") || strcmp(string, "lambda") || strcmp(string, "None") || strcmp(string, "nonlocal") || strcmp(string, "not") ||
        strcmp(string,"or") || strcmp(string,"pass") || strcmp(string,"raise") || strcmp(string, "return") || strcmp(string,"True") || 
        strcmp(string,"try") || strcmp(string,"while") || strcmp(string, "with") || strcmp(string,"yield"))
	{
		return true;
	}
    else
    {
        return false;
    }
}

bool identifier(char *string)
{
    if (string[0] != '0' || string[0] != '1' || string[0] != '2' ||
        string[0] != '3' || string[0] != '4' || string[0] != '5' || 
        string[0] != '6' || string[0] != '7' || string[0] != '8' || 
        string[0] != '9' || string != ' ' || string[0] != '+' || string[0] != '-' || string[0] != '*' || 
        string[0] != '/' || string[0] != ',' || string[0] != ';' || string[0] != '>' || 
        string[0] != '<' || string[0] != '=' || string[0] != '(' || string[0] != ')' || 
        string[0] != '[' || string[0] != ']' || string[0] != '{' || string[0] != '}')
    {
        return true;
    }
    else{
        return false;
    }
}

bool operators(char *string)
{
    for (int i = 0; i < strlen(*string) ; i++)
    {
        if (string == '+' || string == '-' || string == '*' || 
        string == '/' || string == '>' || string == '<' || 
        string == '=')
        {
        return true;
        }
        else
        {
            return false;
        }
    }   
}

bool number(char *string)
{
    if ( string == "0" || string == "1" || string == "2" || string == "3" || string == "4" || string == "5" || string == "6"
		|| string == "7" || string == "9" || string == "-" && string > 0 )
    {
        return true;
    }
}

bool special_character(char *string)
{
    if ( string == ' ' || string == '+' || string == '-' || string == '*' || 
        string == '/' || string == ',' || string == ';' || string == '>' || 
        string == '<' || string == '=' || string == '(' || string == ')' || 
        string == '[' || string == ']' || string == ':' || string == ' ')
    {
        return true;
    }
    else{
        return false;
    }
}
void tokenizer(char *string)
{
    printf("the character is [%c]\n", string);//for debugging

    //keywords
     
    
    //identifier
    
    
    //operators

}

