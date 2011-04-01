#ifndef __SEGMENT_HEADER__
#define __SEGMENT_HEADER__

//format class
//Looks at input vector and makes sure that there is no problems. 

//if starting symbol is found, put in stack,

//if ending symbol is found, check the first element on top, if it is the corresponding symbol, then pop, else error.

//if there are symbols left: error

/*symbols: 
! flag start				DONE
- flag end			     	DONE
{ service tag start			DONE
} service tag end			DONE
( repiar start				DONE
) repair end				DONE
[ data start 				DONE
] data end			    	DONE

*/

#include <vector>
#include <iostream>
#include <string>
#include <stack>
using namespace std;

class format
{
public:
        
        format(){
        error=false;};
        ~format(){};        
 bool is_right(vector<string> input);
        
 private:   
 stack<char> symbols;   
 bool strt(char e);
 bool end(char e);
 bool corr(char e);
 bool error;
};






bool format::strt(char e)//gives priority to expressions
{
        bool pri = false;

        if(e == '!' || e == '{' || e =='('||e=='[')
                pri = true;
        
        return pri;
};
bool format::end(char e)
{
        bool pri = false;

        if(e == '-' || e == '}' || e ==')'||e==']')
                pri = true;
        
        return pri;

};
bool format::corr(char e)
{
     bool test=true;
if(symbols.size()==0)
error=true;
else
{
	if(e=='}' && symbols.top()!='{')
		test=false;
	if(e=='-' && symbols.top()!='!')
		test=false;
	if(e==']' && symbols.top()!='[')
		test=false;
	if(e==')' && symbols.top()!='(')
		test=false;
 
 }
 if(error==true || test==false)
 return false;
 else
 return true;
};


bool format::is_right(vector<string> input)
{
int i=0,a=0;
char e;
	for(i=0;i<input.size();i++)
	{
	
	
		e=input[i][0];
			if(strt(e))//if a starting symbol symbol is found, then push onto stack.  
			{
			symbols.push(e);
						
			}

			else if(end(e))//if ending symbol is found, check to see if the top of the stack is the corresponding start and pop the start
				{
					if(corr(e))
					symbols.pop();
					else
					break;
					
													
				}
			
	
	}

	if(symbols.size()==0 && error==false)
		return true;
	else 
	{
         while(symbols.size()!=0)
         symbols.pop();
		return false;
     }
};
#endif
