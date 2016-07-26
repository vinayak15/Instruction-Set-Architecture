#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<stdio.h>
char* Convert_Binary(int num)  /* Function to convert decimal to binary.*/
{
    int rem,n=6;
   
	int i;
    char *binary=(char *)malloc(sizeof(char)*6);
    for( i=0;i<6;i++)
    	binary[i]='0';
    while (num!=0)
    {
        rem=num%2;
        num/=2;
        binary[--n]=rem + '0';
     
    }
    return binary;
}

//This function is to check whether scanned opcode is Two Address Instruction or not 

char* Check_Two_Add(char *str)
{
	if(strcmp(str,"CMP")==0)		//Used to compare two values in register
		return "0000";
	
	else if(strcmp(str,"ADD")==0)		//	Used to add two values in register
		return "0001";
	
	else if(strcmp(str,"SUB")==0)		//Used to subtract two values register
		return "0010";
	
	else if(strcmp(str,"MUL")==0)		//Used to multiply two values in Register
		return "0011";
		
	else if(strcmp(str,"DIV")==0)		//Used to divide two values in register 
		return "0100";
	
	else if(strcmp(str,"ADDI")==0)   //Used to add constant to Register
		return "0101";
	
	else if(strcmp(str,"SUBI")==0)	//Used to Sub Constant to from Register
		return "0110";

	else if(strcmp(str,"MULI")==0)	//Used to multiply a constant to Register
		return "0111";
		
	else if(strcmp(str,"AND")==0)		//Used to do Logical and of two Register
		return "1000";
		
	else if(strcmp(str,"DIVI")==0)	//Used to Divide value of register by constant
		return "1001";
		
	else if(strcmp(str,"SHAR")==0)		//Logical Shift Right of Register Value by given Constant  
		return "1010";
		
	else if(strcmp(str,"SAAL")==0)		//Logical Shift Left of Register Value by given Constant 
		return "1011";
		
	else if(strcmp(str,"MOV")==0)		//Move valeue of One Register to another
		return "1100";
		
	else if(strcmp(str,"MOVI")==0)	// Move one constant to another Register
		return "1101";
		
	else return "-1";
}

//This function ia to check whether given Instruction is One Address Instruction or not

char * Check_One_Add(char *str)
{
	if(strcmp(str,"IN")==0)			// Input in Given Register
		return "1110000000";
		
	else if(strcmp(str,"OUT")==0)	//Output in given Register
		return "1110000001";
	
	else if(strcmp(str,"JMP")==0)	//JMP to a Label
		return "1110000010";
	
	else if(strcmp(str,"JNE")==0)	//Jump to label if not equals
		return "1110000011";
		
	else if(strcmp(str,"JEQ")==0) //Jump to label if Equals
		return "1110000100";
		
	else if(strcmp(str,"JLT")==0) 
		return "1110000101";
	
	else if(strcmp(str,"JGT")==0)
		return "1110000110";
	
	else return "-1";
}

//This function ia to check whether given Instruction is Zero Address Instruction or not

char * Check_Zero_Add(char * str)
{
	if(strcmp(str,"HLT")==0)
		return "1110000111000000";
	
	else return "-1";

}
//This function ia to check whether Command is Register or not

char * Check_Reg(char *str)
{
	if(strcmp(str,"R00")==0)
		return "000000";
	
	else if(strcmp(str,"R01")==0)
		return "000001";
		
	else if(strcmp(str,"R02")==0)
		return "000010";
	
	else if(strcmp(str,"R03")==0)
		return "000011";	
		
	else if(strcmp(str,"R04")==0)
		return "000100";
		
	else if(strcmp(str,"R05")==0)
		return "000101";
		
	else if(strcmp(str,"R06")==0)
		return "000110";
		
	else if(strcmp(str,"R07")==0)
		return "000111";
		
	else if(strcmp(str,"R08")==0)
		return "001000";
	
	else if(strcmp(str,"R09")==0)
		return "001001";
		
	else if(strcmp(str,"R10")==0)
		return "001010";
	
	else if(strcmp(str,"R11")==0)
		return "001011";	
		
	else if(strcmp(str,"R12")==0)
		return "001100";
		
	else if(strcmp(str,"R13")==0)
		return "001101";
		
	else if(strcmp(str,"R14")==0)
		return "001110";
		
	else if(strcmp(str,"R15")==0)
		return "001111";
		
	else if(strcmp(str,"R16")==0)
		return "010000";
	
	else if(strcmp(str,"R17")==0)
		return "010001";
		
	else if(strcmp(str,"R18")==0)
		return "010010";
	
	else if(strcmp(str,"R19")==0)
		return "010011";	
		
	else if(strcmp(str,"R20")==0)
		return "010100";\
	
	else
		return "-1";
}

//This function ia to check whether Command is Label or not

char * Check_Label(char *str)
{
	if(strcmp(str,"L0")==0)
		return "010101";
	
	else if(strcmp(str,"L1")==0)
		return "010110";
		
	else if(strcmp(str,"L2")==0)
		return "010111";
	
	else if(strcmp(str,"L3")==0)
		return "011000";	
		
	else if(strcmp(str,"L4")==0)
		return "011001";
		
	else if(strcmp(str,"L5")==0)
		return "011010";
		
	else if(strcmp(str,"L6")==0)
		return "011011";
		
	else if(strcmp(str,"L7")==0)
		return "011100";
	
	else return "-1";	
}	
