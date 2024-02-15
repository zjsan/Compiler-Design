#include <stdio.h>
#include <ctype.h>

void tokenizer(char *str);
//void read_file(struct lexical_struc s1);


int main()
{
	
	char input_string[100] = "int a = b + 1c; ";
	//read_file(s1);
	//tokenizer();
	return 0;
}



// void read_file(struct lexical_struc s1)
// {
	

// 	//read file
// 	FILE *file_pointer;
	
// 	// Open a file in read mode
// 	file_pointer = fopen("lexemes.txt", "r");
// 	// Store the content of the file
// 	char file_string[100];
	
	
// 	// If the file exist
// 	if(file_pointer != NULL) {	

//   		// Read the content and print it
//   		// Read the content and store it inside file_string
//   		while(fgets(file_string, 100, file_pointer)) 
// 		{
// 			//scans
// 			//strcpy(s1.string, scanf("%s",fgets(file_string, 100, file_pointer)));
//     		// Print the file content
// 			printf("%s", file_string);
//   	}

// 	// If the file does not exist
// 	} else {
//   		printf("Not able to open the file.");
// 	}
	
// 	// Close the file - must be in the end of the function after the tokenization of strings are done
// 	fclose(file_pointer);
	
// }

void tokenizer(char *str)
{	
	/**
	Rules:
	1. keywords - datatypes
	2. identifier
	3. operator
	4. number
	5. special characters 
	**/
	
	//keyword
	if(s1.string == "int" || s1.string == "float" || s1.string == "double" || s1.string == "char" || s1.string == "void" 
		||s1.string == "if" || s1.string == "else" || s1.string == "else if" || s1.string == "for" || s1.string == "while" ||
		s1.string == "do" || s1.string == "break" || s1.string == "continue")
	{
		printf("keyword");
	}
	else if(isalpha(s1.string) == 1)
	{
		//identifi
		printf("identifier");
	}
	else if(s1.string == "(" || s1.string == ")" || s1.string == ";" || s1.string == "{" || s1.string == "}"  || s1.string == "&")
	{
		//special characters
		printf("special characters");
	}
	else if(s1.string == "+" || s1.string == "-" || s1.string == "*" || s1.string == "/" || s1.string == "%" ||s1.string == "<" 
		|| s1.string == ">" || s1.string == "=" || s1.string == "!")
	{
		//operators
		printf("operators");
	}
	else if( s1.string == "0" || s1.string == "1" || s1.string == "2" || s1.string == "3" || s1.string == "4" || s1.string == "5" || s1.string == "6"
		|| s1.string == "7" || s1.string == "9" )
	{
		//number
		printf("number");
	}
	else{
		printf("invalid token");
	}
	
}