#include<string.h>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
int Zero_Flag=0,Compare_Flag=0;


long long int Convert_To_Decimal(int num)    //Conversion to decimal of given binary number
{
	int num2=0, i=0, rem;
    while (num!=0)
    {
        rem = num%10;
        num/=10;
        num2 += rem*pow(2,i);
        ++i;
    }
	return num2;
}

int bitwiseadd(int x, int y)     //bitwise addition of numbers 
{
    while (y != 0)
    {
        int carry = x & y;
        x = x ^ y; 
        y = carry << 1;
    }
    return x;
}
 
int bitwisesub(int x, int y)      //bitwise substraction of numbers
{
    while (y != 0)
    {
        int borrow = (~x) & y;
        x = x ^ y;
        y = borrow << 1;
    }
    return x;
}

int bitwisemul(int a,int b)		//bitwise multiplication of two numbers
{
	 int result = 0;
    while (b != 0)              
    {
        if (b & 01)              
            result = result + a;  
        a<<=1;                    
        b>>=1;                   
    }
    return result;
}

int bitwisediv(int numerator, int denominator) //bitwise division of two numbers
{
	
	int mask = 0x1;
	int quotient = 0;

	while (denominator <= numerator) {
		denominator <<= 1;
		mask <<= 1;
	}

	while (mask > 1) {
		denominator >>= 1;
		mask >>= 1;
		if (numerator >= denominator) {
			numerator -= denominator;
			quotient |= mask;
		}
	}

return quotient;
}

void Display_Reg()							//Displaying register value at each step
{
	printf("\nZero Flag value is=%d\nSign Flag value is=%d\nCompare Flag value is=%d\n",Zero_Flag,Sign_Flag,Compare_Flag);
}

void MOV(char *str,int Reg_No[])			//MOV function and its operation
{
	long long int tmp1= myAtoi(str,20,25);
	long long int tmp2 =myAtoi(str,26,31);
	long long int Add1=Convert_To_Decimal(tmp1);
	long long int Add2=Convert_To_Decimal(tmp2);
	Reg_No[Add2]=Reg_No[Add1];
	Display_Reg();
	printf("Value R%lld=%d\n",Add2,Reg_No[Add2]);
	printf("\nALU control signal is given by D3 D2 D1 D0 : 1 1 0 0\n");
}

void ADD(char *str,int Reg_No[])		//ADD function for two register value
{
	long long int tmp1= myAtoi(str,20,25);
	long long int tmp2 =myAtoi(str,26,31);
	long long int Add1=Convert_To_Decimal(tmp1);
	long long int Add2=Convert_To_Decimal(tmp2);
	Reg_No[Add2] = bitwiseadd(Reg_No[Add2],Reg_No[Add1]);
	Display_Reg();
	printf("Value R%lld=%d\n",Add2,Reg_No[Add2]);
	printf("\nALU control signal is given by D3 D2 D1 D0 : 0 0 0 1\n");	
}

void SUB(char *str,int Reg_No[])		//sustraction function for two register value
{
	long long int tmp1= myAtoi(str,20,25);
	long long int tmp2 =myAtoi(str,26,31);
	long long int Add1=Convert_To_Decimal(tmp1);
	long long int Add2=Convert_To_Decimal(tmp2);
	Reg_No[Add2] =bitwisesub(Reg_No[Add2], Reg_No[Add1]);
	Display_Reg();
	printf("Value R%lld=%d\n",Add2,Reg_No[Add2]);
	printf("\nALU control signal is given by D3 D2 D1 D0 : 0 0 1 0\n");
}

void MUL(char *str,int Reg_No[])		//multiplication of two register value
{
	long long int tmp1= myAtoi(str,20,25);
	long long int tmp2 =myAtoi(str,26,31);
	long long int Add1=Convert_To_Decimal(tmp1);
	long long int Add2=Convert_To_Decimal(tmp2);
	Reg_No[Add2] = bitwisemul(Reg_No[Add2],Reg_No[Add1]);
	Display_Reg();
	printf("Value R%lld=%d\n",Add2,Reg_No[Add2]);
	printf("\nALU control signal is given by D3 D2 D1 D0 : 0 0 1 1\n");
}

void DIV(char *str,int Reg_No[])		//division of two register value
{
	long long int tmp1= myAtoi(str,20,25);
	long long int tmp2 =myAtoi(str,26,31);
	long long int Add1=Convert_To_Decimal(tmp1);
	long long int Add2=Convert_To_Decimal(tmp2);
	Reg_No[Add2] =bitwisediv(Reg_No[Add2], Reg_No[Add1]);
	Display_Reg();
	printf("Value R%lld=%d\n",Add2,Reg_No[Add2]);
	printf("\nALU control signal is given by D3 D2 D1 D0 : 0 1 0 0\n");
}

void MOVI(char * str,int Reg_No[])		//MOV of one constant to register value
{

	long long int Value= myAtoi(str,20,25);
	long long int Address1 =myAtoi(str,26,31);

	long long int Constant=Convert_To_Decimal(Value);
	long long int Add1=Convert_To_Decimal(Address1);
	Reg_No[Add1]=Constant;
	Display_Reg();
	printf("Value R%lld=%d\n",Add1,Reg_No[Add1]);
	printf("\nALU control signal is given by D3 D2 D1 D0 : 1 1 0 1\n");
}

void ADDI(char * str,int Reg_No[])		//Addition of one constant to register value
{
	long long int Value= myAtoi(str,20,25);
	long long int Address1 =myAtoi(str,26,31);

	long long int Constant=Convert_To_Decimal(Value);
	long long int Add1=Convert_To_Decimal(Address1);
	Reg_No[Add1] =bitwiseadd(Reg_No[Add1], Constant);
	Display_Reg();
	printf("Value R%lld=%d\n",Add1,Reg_No[Add1]);
	printf("\nALU control signal is given by D3 D2 D1 D0 : 0 1 0 1\n");
}

void SUBI(char * str,int Reg_No[])		//substraction of one constant from register value
{
	long long int Value= myAtoi(str,20,25);
	long long int Address1 =myAtoi(str,26,31);

	long long int Constant=Convert_To_Decimal(Value);
	long long int Add1=Convert_To_Decimal(Address1);
	Reg_No[Add1] =bitwisesub(Reg_No[Add1], Constant);
	Display_Reg();
	printf("Value R%lld=%d\n",Add1,Reg_No[Add1]);
	printf("\nALU control signal is given by D3 D2 D1 D0 : 0 1 1 0\n");
}

void MULI(char * str,int Reg_No[])	//multiplication of one constant to register value
{
	long long int Value= myAtoi(str,20,25);
	long long int Address1 =myAtoi(str,26,31);

	long long int Constant=Convert_To_Decimal(Value);
	long long int Add1=Convert_To_Decimal(Address1);
	Reg_No[Add1] =bitwisemul(Reg_No[Add1], Constant);
	Display_Reg();
	printf("Value R%lld=%d\n",Add1,Reg_No[Add1]);
	printf("\nALU control signal is given by D3 D2 D1 D0 : 0 1 1 1\n");
}

void DIVI(char * str,int Reg_No[])		//division of one constant to reigste value
{
	long long int Value= myAtoi(str,20,25);
	long long int Address1 =myAtoi(str,26,31);

	long long int Constant=Convert_To_Decimal(Value);
	long long int Add1=Convert_To_Decimal(Address1);
	Reg_No[Add1]=bitwisediv(Reg_No[Add1],Constant);
	Display_Reg();
	printf("Value R%lld=%d\n",Add1,Reg_No[Add1]);
	printf("\nALU control signal is given by D3 D2 D1 D0 : 1 0 0 1\n");
}

void AND(char *str,int Reg_No[])		//Logical AND of two value
{
	long long int Address1= myAtoi(str,20,25);
	long long int Address2 =myAtoi(str,26,31);

	long long int Add1=Convert_To_Decimal(Address1);
	long long int Add2=Convert_To_Decimal(Address2);
	Reg_No[Add2] &= Reg_No[Add1];
	Display_Reg();
	printf("Value R%lld=%d\n",Add2,Reg_No[Add2]);
	printf("\nALU control signal is given by D3 D2 D1 D0 : 1 0 0 0\n");
}

void SHAR(char * str,int Reg_No[])		//shift right of register value by given constant
{
	long long int Value= myAtoi(str,20,25);
	long long int Address1 =myAtoi(str,26,31);

	long long int Constant=Convert_To_Decimal(Value);
	long long int Add1=Convert_To_Decimal(Address1);
	Reg_No[Add1] >>=Constant;
	Display_Reg();
	printf("Value R%lld=%d\n",Add1,Reg_No[Add1]);
	printf("\nALU control signal is given by D3 D2 D1 D0 : 1 0 1 0\n");
}

void SAAL(char * str,int Reg_No[])		//shift left of register value by given constant
{
	long long int Value= myAtoi(str,20,25);
	long long int Address1 =myAtoi(str,26,31);

	long long int Constant=Convert_To_Decimal(Value);
	long long int Add1=Convert_To_Decimal(Address1);
	Reg_No[Add1] <<=Constant;
	Display_Reg();
	printf("Value R%lld=%d\n",Add1,Reg_No[Add1]);
	printf("\nALU control signal is given by D3 D2 D1 D0 : 1 0 1 1\n");
}

	
void CMP(char * str,int Reg_No[])	//Compare value of two register and sets the flag
{

	long long int Address1 =myAtoi(str,20,25);
	long long int Address2 =myAtoi(str,26,31);

	long long int Add1=Convert_To_Decimal(Address1);
	long long int Add2=Convert_To_Decimal(Address2);
	if(Reg_No[Add1] == Reg_No[Add2])
		Zero_Flag=0;
	else 
		Zero_Flag=1;
		
	if(Reg_No[Add1] > Reg_No[Add2])
		Compare_Flag=1;
	else 
		Compare_Flag=0;
	Display_Reg();
}

//one address Instruction
void IN(char * str,int Reg_No[])
{

	long long int Address1 =myAtoi(str,26,31);
	long long int Add1=Convert_To_Decimal(Address1);
	printf("Enter  input value\n");
	scanf("%d",&Reg_No[Add1]); 
	Display_Reg();
	printf("Value R%lld=%d\n",Add1,Reg_No[Add1]);
	printf("\nALU control signal is given by D9 D8 D7 D6 D5 D4 D3 D2 D1 D0 : 1 1 1 0 0 0 0 0 0 0\n"); 
}

void OUT(char * str,int Reg_No[])
{
	int a;
	long long int Address1 =myAtoi(str,26,31);
	long long int Add1=Convert_To_Decimal(Address1);
	printf("\nThe output value\n%d\n",Reg_No[Add1]);
	scanf("%d",&a); 
	Display_Reg();
	printf("Value R%lld=%d\n",Add1,Reg_No[Add1]);
	printf("\nALU control signal is given by D9 D8 D7 D6 D5 D4 D3 D2 D1 D0 : 1 1 1 0 0 0 0 0 0 1\n");
}

void JMP(char * str,int Reg_No[],FILE *fp)
{
	long long int Address1 =myAtoi(str,26,31);
	int read=0,a;
	char *temp=(char *)malloc(sizeof(char)*10);
	size_t t=10; 
	FILE *fp1 = fopen("SymbolTable.txt","r");	
	while(read=getline(&temp,&t,fp1)!=-1) 
	{
		long long int temp1 =myAtoi(temp,0,5);								
		if(temp1==Address1) 
		{
			a=atoi(temp+7);
			fseek(fp,(a-1)*33,0);
			break;
		}
	}
	fclose(fp1);
}

void JNE(char *str, int Reg_No[],FILE *fp)
{
	long long int Address1 =myAtoi(str,26,31);
	int read=0,a;
	char *temp=(char *)malloc(sizeof(char)*10);
	size_t t=10; 
	FILE *fp1 = fopen("SymbolTable.txt","r");	
	if(Zero_Flag==1)
	while(read=getline(&temp,&t,fp1)!=-1) 
	{
		long long int temp1 =myAtoi(temp,0,5);								
		if(temp1==Address1) 
		{
			a=atoi(temp+7);
			fseek(fp,(a-1)*33,0);
			break;
		}
	}
	fclose(fp1);
}
void JGT(char *str, int Reg_No[],FILE *fp)
{
	long long int Address1 =myAtoi(str,26,31);
	int read=0,a;
	char *temp=(char *)malloc(sizeof(char)*10);
	size_t t=10; 
	FILE *fp1 = fopen("SymbolTable.txt","r");	
	if(Compare_Flag==1)
	while(read=getline(&temp,&t,fp1)!=-1) 
	{
		long long int temp1 =myAtoi(temp,0,5);								
		if(temp1==Address1) 
		{
			a=atoi(temp+7);
			fseek(fp,(a-1)*33,0);
			break;
		}
	}
	fclose(fp1);
}

void JLT(char *str, int Reg_No[],FILE *fp)
{
	long long int Address1 =myAtoi(str,26,31);
	int read=0,a;
	char *temp=(char *)malloc(sizeof(char)*10);
	size_t t=10; 
	FILE *fp1 = fopen("SymbolTable.txt","r");	
	if(Compare_Flag==0)
	while(read=getline(&temp,&t,fp1)!=-1) 
	{
		long long int temp1 =myAtoi(temp,0,5);								
		if(temp1==Address1) 
		{
			a=atoi(temp+7);
			fseek(fp,(a-1)*33,0);
			break;
		}
	}
	fclose(fp1);
}
void JEQ(char *str, int Reg_No[],FILE *fp)
{
	long long int Address1 =myAtoi(str,26,31);
	int read=0,a;
	char *temp=(char *)malloc(sizeof(char)*10);
	size_t t=10; 
	FILE *fp1 = fopen("SymbolTable.txt","r");	
	if(Zero_Flag==0)
	while(read=getline(&temp,&t,fp1)!=-1) 
	{
		long long int temp1 =myAtoi(temp,0,5);								
		if(temp1==Address1) 
		{
			a=atoi(temp+7);
			fseek(fp,(a-1)*33,0);
			break;
		}
	}
	fclose(fp1);
}
