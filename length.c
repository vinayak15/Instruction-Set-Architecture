#include<string.h>
#include<stdlib.h>
#include<stdio.h>
long long int myAtoi(char *str,int a, int b)
{
    long long int res = 0,i; // Initialize result
  
    // Iterate through all characters of input string and
    // update result
    for (i = a; i<=b; ++i)
        res = res*10 + str[i] - '0';
  
    // return result.
    return res;
}

void check_str(char * str,FILE *fp,int Add[])
{
	
	if(myAtoi(str,16,19)==0)		//Used to compare two values in register
		CMP(str,Add);
	
	else if(myAtoi(str,16,19)==1)		//	Used to add two values in register
		ADD(str,Add);
	
	else if(myAtoi(str,16,19)==10)		//Used to subtract two values register
		SUB(str,Add);
	
	else if(myAtoi(str,16,19)==11)		//Used to multiply two values in Register
		MUL(str,Add);
		
	else if(myAtoi(str,16,19)==100)		//Used to divide two values in register 
		DIV(str,Add);
			
	else if(myAtoi(str,16,19)==101)   //Used to add constant to Register
		ADDI(str,Add);
	
	else if(myAtoi(str,16,19)==110)	//Used to Sub Constant to from Register
		SUBI(str,Add);

	else if(myAtoi(str,16,19)==111)	//Used to multiply a constant to Register
		MULI(str,Add);
		
	else if(myAtoi(str,16,19)==1000)		//Used to do Logical and of two Register
		AND(str,Add);
		
	else if(myAtoi(str,16,19)==1001)	//Used to Divide value of register by constant
		DIVI(str,Add);
		
	else if(myAtoi(str,16,19)==1010)		//Logical Shift Right of Register Value by given Constant  
		SHAR(str,Add);
		
	else if(myAtoi(str,16,19)==1011)		//Logical Shift Left of Register Value by given Constant 
		SAAL(str,Add);
		
	else if(myAtoi(str,16,19)==1100)		//Move valeue of One Register to another
		MOV(str,Add);
		
	else if(myAtoi(str,16,19)==1101)	// Move one constant to another Register
		MOVI(str,Add);
	
	else if(myAtoi(str,16,25)==1110000000)			// Input in Given Register
		IN(str,Add);
	else if(myAtoi(str,16,25)==1110000001)	//Output in given Register
		OUT(str,Add);
	
	else if(myAtoi(str,16,25)==1110000010)	//JMP to a Label
		JMP(str,Add,fp);
	
	else if(myAtoi(str,16,25)==1110000011)	//Jump to label if not equals
		JNE(str,Add,fp);
		
	else if(myAtoi(str,16,25)==1110000100) //Jump to label if Equals
		JEQ(str,Add,fp);
		
	else if(myAtoi(str,16,25)==1110000101) 
		JLT(str,Add,fp);
	
	else if(myAtoi(str,16,25)==1110000110)
		JGT(str,Add,fp);
	
	else if(myAtoi(str,16,31)==1110000111000000)
	{
		fclose(fp);
		exit(0);
	}
}
