#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>




bool match(){
    
    if ((/* condition */))
    {
        /* code */
    }
    


    return 0;
}


//<statement> ::= <assignment_statement> | <if_statement> | <else_statement>
bool statement() {
    if (assignment_stmt) {
        return true;
    } else {
        if (if_statement) {
            return true;
        } else if (else_stmt) {
            return true;
        } else {
            return false;
        }
    }
}

//assignment_statement> ::= <identifier> '=' <expression> 
bool assignment_stmt() {
    if () {
        if (match('=')) {
            if (expression) {
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    } else {
        return false;
    }
}

//<if_statement> ::= IF <expression> COLON INDENT <statement_list> DEDENT
bool if_statement() {
    if (match('if')) {
        if (expression) {
            if (match(':')) {
                if (statement()) {
                    return true;
                } else {
                    return false;
                }
            } else {
                return false;
            }
        } else {
            return false;
        }
    } else {
        return false;
    }
}

//<else_statement> ::= ELSE COLON INDENT <statement_list> DEDENT
bool else_stmt() {
    if (match('else')) {
      if(match(':'))
      {
        if (statement())
        {
            return true;
        }
        else{
            return false;
        }
      }
      else{
        return false;
      }
    }
    else{
        return false;
    }
}

bool expression(){

    if (identifier())
    {
        return true;
    }
    
    
}


int main()
{

    return 0;
}