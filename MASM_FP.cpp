// MASM_FP.cpp : Defines the entry point for the console application.
#include "stdafx.h"
#include <stdio.h>
void test(void); // Function prototype (description)
int _tmain(int argc, _TCHAR* argv[])
{
test();
return 0;
}
void test()
{
float A=3, B=9, C=0;
unsigned short cntrl=0x3FF,stat;
__asm
{
FINIT           		; Set FPU to default state
FLDCW		cntrl     	; Round even, Mask Interrupts
FLD 		A   		; Push SX onto FP stack
FMUL		ST,ST(0)   	; Multiply ST*ST result on ST		
FLD			A			; Push A onto FP Stack
FMUL 		ST,ST(1)	; Cube A
	
FLD 		B          ; Push SY onto FP stack
FSQRT    	 			; Square root number on stack
FADD 		ST,ST(1)   	; ADD top two numbers on stack
	
FSTSW stat ; Load FPU status into [stat]
FSTP C ; Copy result from stack into HY

}

printf("%3.3f",C);

while(getchar()!=10);
while(getchar()!=10);
}