#include <stdio.h>
#include <string.h>
#include "addsubrn.h"

int ReadNumber(char *msg, char *num);
int GetLine (char *msg, char *buff, size_t sz);


int main(int argc, char **argv) {


   char number1[MAX_LEN] = {""};
   char number2[MAX_LEN] = {""};
   char addition[MAX_LEN*2] = {""};
   char subtraction_n1_n2[MAX_LEN*2] = {""};
   char subtraction_n2_n1[MAX_LEN*2] = {""};
   
   printf("*************************************************************");
   printf("\n* Welcome to program for aritmethic of roman numerals !!!");
   printf("\n* Operations available: addition and subtraction");
   printf("\n* Allowed symbols:      i,v,x,l,c,d,m and I,V,X,L,C,D,M ");
   printf("\n* Range of operation:   I to MMMCMXCIX (1 to 3999) ");
   printf("\n* Designed by Javier Soto Vargas - javiersotovargas@gmail.com");
   if (argc >= 2 && strcmp("pdm", argv[1]) == 0){
      pdm = 1;      
      printf("\n* Print debug messages enabled");   
   } else {
      pdm = 0;
      printf("\n* Print debug messages not enabled");
   }
   printf("\n*************************************************************");
   printf("\n");
   
   int code;
   //   
   do{
      code = ReadNumber("Please introduce the first Roman Numeral: ", number1);
      if (code == OK) code = ConvertUppercaseValidateChar(number1);
      if (code == OK) code = ValidateRoman(number1);
      //printf("\ncode = %d",code);
   }while(code != OK);
   //
   do{
      code = ReadNumber("Please introduce the second Roman Numeral: ", number2);
      if (code == OK) code = ConvertUppercaseValidateChar(number2);
      if (code == OK) code = ValidateRoman(number2);
   }while(code != OK);
   //
   if(pdm) printf("\n************************************************");
   code = AddRomanNumerals(number1, number2, addition);
   if(pdm) printf ("\n");
   if (code == OK){
      printf ("\nAddition : %s + %s = %s",number1, number2, addition);
   } else {
      printf ("\nAddition out of range max value is MMMCMXCIX");
   }
   //   
   if(pdm) printf("\n************************************************");
   if(pdm) printf ("\n");
   code = SubRomanNumerals(number1, number2, subtraction_n1_n2);
   if(pdm) printf ("\n");
   if (code == OK){
      printf ("\nSubtraction : %s - %s = %s",number1, number2, subtraction_n1_n2);
   } else if (code == SUBTRACTION_IS_ZERO) {
      printf ("\nSubtraction : %s - %s =  ; it is zero, no roman symbol for zero !!!",number1, number2); 
   } else if (code == SUBTRACTION_NOT_POSSIBLE) {
      printf ("\nSubtraction : %s - %s ; it is not possible, negative number !!!",number1, number2); 
   } else {
      printf ("\nSubtraction : %s - %s ; ERROR !!!",number1, number2); 
   }
   //
   if(pdm) printf("\n************************************************");
   if(pdm) printf ("\n");
   code = SubRomanNumerals(number2, number1, subtraction_n2_n1);
   if(pdm) printf ("\n");
   if (code == OK){
      printf ("\nSubtraction : %s - %s = %s",number2, number1, subtraction_n2_n1);
   } else if (code == SUBTRACTION_IS_ZERO) {
      printf ("\nSubtraction : %s - %s =  ; it is zero, no roman symbol for zero !!!",number1, number2); 
   } else if (code == SUBTRACTION_NOT_POSSIBLE) {
      printf ("\nSubtraction : %s - %s ; it is not possible, negative number !!!",number2, number1);
   } else {
      printf ("\nSubtraction : %s - %s ; ERROR !!!",number1, number2); 
   }
   
   printf("\n************************************************");
   printf("\n* End of program !!!");
   printf("\n************************************************");
   printf("\n\n");
   
   return 0;
}


/********************************************************
*Read numbers function
*********************************************************/
int ReadNumber(char *msg, char *num){
   int code;
   //
   code = GetLine (msg, num, MAX_LEN);
   if (code == NO_INPUT) {
       return code;
   }else if (code == TOO_LONG){
      if(pdm) printf ("\nThe maximun length is %d, the number was cutted !!!",(MAX_LEN-1));
      code = OK;
   }else if (code == OK){
      return code;
   }else{
      if(pdm) printf ("\nUndefined number option !!!");
   }
   return code;           
}
/********************************************************
*get line function
*Reference: 
*http://stackoverflow.com/questions/4023895/how-to-read-string-entered-by-user-in-c 
*********************************************************/
int GetLine (char *msg, char *num, size_t sz) {
   int ch, extra;

   // Get line with buffer overrun protection.
   if (msg != NULL) {
      printf ("\n%s", msg);
      fflush (stdout);
   }

   if (fgets (num, sz, stdin) == NULL)
      return NO_INPUT;

   if (num[0] == '\n')
      return NO_INPUT;      

   // If it was too long, there'll be no newline. In that case, we flush
   // to end of line so that excess doesn't affect the next call.
   if (num[strlen(num)-1] != '\n') {
      extra = 0;
      while (((ch = getchar()) != '\n') && (ch != EOF))
         extra = 1;
      return (extra == 1) ? TOO_LONG : OK;
   }

   // Otherwise remove newline and give string back to caller.
   num[strlen(num)-1] = '\0';
   return OK;
}



